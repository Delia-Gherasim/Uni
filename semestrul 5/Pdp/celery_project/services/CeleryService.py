import uuid
from typing import Dict, List
from celery_app import app
from models.TimetableEntry import TimetableEntry
from celery import shared_task
from multiprocessing import Lock

room_assignments_lock = Lock()

@shared_task
def generate_combination_for_group(group, teachers, subjects, rooms, hours, room_assignments):
    days = TimetableEntry.Days
    days=list(days)
    entries = []
    for subject_key, hours_required in group.necessarySubjects.items():
        subjectId, teacherId = subject_key
        teacher = None
        for t in teachers:
            if str(t._id) == str(teacherId):              
                teacher = t
                break

        subjectEntity = None
        for s in subjects:
            if s._id == subjectId:
                subjectEntity = s
                break
                
        if teacher is None or subjectEntity is None:
            continue
        for day in days:
            for hour in hours:
                if not IsSlotAvailableForGroup(group, day, hour, room_assignments):
                    continue
                for room in rooms:
                    if IsRoomCompatible(subjectEntity, room):
                        entries.append(TimetableEntry(teacher, subjectEntity, group, room, day, hour))
   
    return entries

def generate_timetable(teachers_repo, subjects_repo, rooms_repo, groups_repo, timetable_repo ):
    teachers =  teachers_repo.get_teachers()
    subjects =  subjects_repo.get_subjects()
    rooms =  rooms_repo.get_rooms()
    groups =  groups_repo.get_groups()
    timetable_repo = timetable_repo
    room_assignments: Dict[uuid.UUID, List[TimetableEntry]]={}

    hours = range(8, 15)
    maxAttempts = 5000
    isValidTimetable = False

    for attempt in range(maxAttempts):
        timeTableEntries = []
        tasks = []
        room_assignments.clear()
        for group in groups:
            tasks.append( generate_combination_for_group.apply_async(
                args=[ group, teachers, subjects, rooms, hours, room_assignments]
            ))

        for task in tasks:
            localTimeTable: List[TimetableEntry] = []
            result = task.get()
            for combination in result:
                if (IsValidEntry(combination, localTimeTable, room_assignments)==True):
                    localTimeTable.append(combination)
            timeTableEntries.extend(localTimeTable)
        if ValidateFinalTimeTable(timeTableEntries, groups):
            for entry in timeTableEntries:
                timetable_repo.add_entry(entry)
            
            print("Validated!")
            isValidTimetable = True   
            break

    if not isValidTimetable:
        print("Timetable not valid!")

def IsSlotAvailableForGroup( group, day, hour, room_assignments):
    with room_assignments_lock:
        for entries in room_assignments.values():
            for entry in entries:
                if entry.group == group and entry.day == day and entry.hour == hour:
                    return False
    return True

def IsRoomCompatible(subjectEntity, room):
    if subjectEntity.specificRoom:
        return room._id == subjectEntity.roomId
    return True


def IsValidEntry(entry, localTimeTable, room_assignments):
    if any(e.teacher == entry.teacher and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
        return False
    
    if IsTeacherOverLoaded(entry.teacher, localTimeTable, 6, 20):
        return False
    
    if any(e.room == entry.room and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
        return False
    
    if IsRoomOverused(entry.room, entry.group, localTimeTable):
        return False
    
    if any(e.group == entry.group and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
        return False
    
    if not IsSubjectBalanced(entry.subject, entry.group, localTimeTable):
        return False

    teacher_id = entry.teacher._id
    subject_id = entry.subject._id
    if not isinstance(teacher_id, uuid.UUID):
        teacher_id = uuid.UUID(teacher_id)
    if not isinstance(subject_id, uuid.UUID):
        subject_id = uuid.UUID(subject_id)
    
    if GetSubjectAssignedHours(entry.subject, entry.group, localTimeTable) >= entry.group.necessarySubjects[(subject_id, teacher_id)]:
        return False
    
    if not IsRoomAvailable(entry.room, entry.group, entry.day, entry.hour, localTimeTable, entry, room_assignments):
        return False
    
    if not IsCorrectRoom(entry):
        return False

    return True


def ValidateFinalTimeTable(timeTableEntries, groups):
    for group in groups:     
        for subject_key, hoursRequired in group.necessarySubjects.items():
            subjectId, teacherId = subject_key
            
            count = 0
            for e in timeTableEntries:
                if e.group._id == group._id and e.subject._id == subjectId:
                    count = count + 1
            
            if count > hoursRequired:
                return False  
    return True


def IsTeacherOverLoaded( teacher, localTimeTable, param, param1):
    days = TimetableEntry.Days
    days=list(days)
    for day in days:
        count = 0
        for entry in localTimeTable:
            if entry.teacher == teacher and entry.day == day:
                count += 1
        if count > param:
            return True
    count = 0
    for entry in localTimeTable:
        if entry.teacher == teacher:
            count += 1
    if count > param1:
        return True

def IsRoomOverused(room, group, localTimeTable):
    daily_hours: Dict[TimetableEntry.Days, int] = {day: 0 for day in TimetableEntry.Days}
    for entry in localTimeTable:
        if entry.room == room and entry.group == group:
            daily_hours[entry.day] += 1  
    return any(hours > 8 for hours in daily_hours.values())

def IsRoomAvailable(room, group, day, hour, localTimeTable, entry, room_assignments):
    if any(e.room._id == room._id and e.day == day and e.hour == hour and e.group._id != group._id for e in localTimeTable):
        return False
    
    room_id = room._id
    if not isinstance(room_id, uuid.UUID):
        room_id = uuid.UUID(room_id)
    with room_assignments_lock:
        if room_id not in room_assignments:
            room_assignments[room_id] = []
        else:
            for entries in room_assignments.values():
                for e in entries:
                    if e.room._id == room_id and e.day == day and e.hour == hour and e.group._id != group._id:
                        return False 

        room_assignments[room_id].append(entry)
    return True

def IsCorrectRoom(entry):
    group = entry.group
    room = entry.room
    subject = entry.subject

    if subject.specificRoom == True:
        if subject.roomId == room._id :
            return True
        else:
            return False
    else:
        return True

def IsSubjectBalanced(subject, group, localTimeTable):
    daily_hours: Dict[TimetableEntry.Days, int] = {day: 0 for day in TimetableEntry.Days}
    for entry in localTimeTable:
        if entry.subject == subject and entry.group == group:
            daily_hours[entry.day] += 1  
    for day, hours in daily_hours.items():
        if hours > 5:
            return False  
    
    return True  


def GetSubjectAssignedHours(  subject, group, localTimeTable):
    count = 0
    for entry in localTimeTable:
        if entry.subject == subject and entry.group == group:
            count += 1
    return count