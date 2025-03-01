import itertools
import uuid

from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from threading import Lock
from typing import Dict, List

from models.TimetableEntry import TimetableEntry

class TimeTableGenerator:
    def __init__(self, teachers_repo, subjects_repo, rooms_repo, groups_repo, timetable_repo):
        self.teachers_repo = teachers_repo
        self.subjects_repo = subjects_repo
        self.rooms_repo = rooms_repo
        self.groups_repo = groups_repo
        self.timetable_repo = timetable_repo
        self.days = TimetableEntry.Days
        # self.global_room_assignments = defaultdict(list)
        # self.room_locks = defaultdict(Lock)
        self.room_assignments: Dict[uuid.UUID, List[TimetableEntry]]

    def geneateTimeTable(self):
        teachers = self.teachers_repo.get_teachers()
        subjects = self.subjects_repo.get_subjects()
        rooms = self.rooms_repo.get_rooms()
        groups = self.groups_repo.get_groups()

        hours = range(8, 8)

        maxAttempts = 5000
        isValidTimetable = False
        for attempt in range(maxAttempts):
            timeTableEntries = []
            for group in groups:
                localTimeTable = []
                self.GenerateTimeTableForGroup(group, teachers, subjects, rooms, self.days, hours, localTimeTable)
                for timetable in localTimeTable:
                    timeTableEntries.append(timetable)

            if (self.ValidateFinalTimeTable(timeTableEntries, groups)):
                for entry in timeTableEntries:
                    self.timetable_repo.add(entry)
                print("Validated!")
                isValidTimetable = True
                break
        if not isValidTimetable:
            print("Timetable not valid!")

    def IsSlotAvailableForGroup(self, group, day, hour):
        return all(entry.group != group or entry.day != day or entry.hour != hour
                   for entries in self.room_assignments.values() for entry in entries)

    def IsRoomCompatible(self, subjectEntity, room):
        if subjectEntity.specificRoom:
            print("SubjectEntity does support Room")
            return room._id == subjectEntity._id
        return True

    def GetAllCombinations(self,group, teachers, subjects, rooms, days, hours):
        entries = []
        for subject_key, hours_required in group.necessarySubjects.items():
            subjectId, teacherId = subject_key
            teacher = None
            for t in teachers:
                if t._id == teacherId:
                    teacher = t
                    break

            subjectEntity = None
            for s in subjects:
                if s._id == subjectId:
                    subjectEntity = s
                    break

            if teacher is None:
                continue
            if subjectEntity is None:
                continue
            for day in days:
                for hour in hours:
                    if not self.IsSlotAvailableForGroup(group, day, hour):
                        continue
                    for room in rooms:
                        if self.IsRoomCompatible(subjectEntity, room):
                            entries.append(TimetableEntry(teacher, subjectEntity, group, room, day, hour))
        return entries

    def IsValidEntry(self, entry, localTimeTable):
        if any(e.teacher == entry.teacher and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
            return False
        if self.IsTeacherOverLoaded(entry.teacher, localTimeTable, 6, 20):
            return False
        if any(e.room == entry.room and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
            return False
        if self.IsRoomOverused(entry.room, entry.group, localTimeTable):
            return False
        if any(e.group == entry.group and e.day == entry.day and e.hour == entry.hour for e in localTimeTable):
            return False
        if not self.IsSubjectBalanced(entry.subject, entry.group, localTimeTable):
            return False
        if self.GetSubjectAssignedHours(entry.subject, entry.group, localTimeTable) >= entry.group.necessarySubjects.find(entry.subject):
            return False
        if not self.IsRoomAvailable(entry.room, entry.group, entry.day, entry.hour, localTimeTable, entry):
            return False
        if not self.IsCorrectRoom(entry):
            return False
        return True
        

    def GenerateTimeTableForGroup(self, group, teachers, subjects, rooms, days, hours, localTimeTable):
        combinations = self.GetAllCombinations(group, teachers, subjects, rooms, days, hours)
        for combination in combinations:
            if (self.IsValidEntry(combination, localTimeTable)):
                localTimeTable.append(combination)

    def ValidateFinalTimeTable(self, timeTableEntries, groups):
        for group in groups:
            for subject_key, hoursRequired in group.necessarySubjects.items():
                subjectId, teacherId = subject_key
                count =0
                for e in timeTableEntries:
                    if e.group == group and e.subject._id == subjectId:
                        count += 1
                if count < hoursRequired:
                    return False
        return True

    def IsTeacherOverLoaded(self, teacher, localTimeTable, param, param1):
        for day in self.days:
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

    def IsRoomOverused(self, room, group, localTimeTable):
        daily_hours = defaultdict(int)
        for entry in localTimeTable:
            if entry.room == room and entry.group == group:
                daily_hours[entry.day] += 1
        return all(hours > 8 for hours in daily_hours.values())

    def IsRoomAvailable(self, room, group, day, hour, localTimeTable, entry):
        if any(e.room == room and e.day == day and e.hour == hour and e.group != group for e in localTimeTable):
            return False

        self.global_room_assignments[room.id].append(entry)
        return True

    def IsCorrectRoom(self, entry):
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


    def IsSubjectBalanced(self, subject, group, localTimeTable):
        daily_hours = defaultdict(int)
        for entry in localTimeTable:
            if entry.subject == subject and entry.group == group:
                daily_hours[entry.day] += 1
        return all(hours <= 5 for hours in daily_hours.values())

    def GetSubjectAssignedHours(self, subject, group, localTimeTable):
        count = 0
        for entry in localTimeTable:
            if entry.subject == subject and entry.group == group:
                count += 1
        return count

    

