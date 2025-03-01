import itertools
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
from threading import Lock
from models.TimetableEntry import TimetableEntry


class TimeTableGenerator:
    def __init__(self, teachers_repo, subjects_repo, rooms_repo, groups_repo, timetable_repo):
        self.teachers_repo = teachers_repo
        self.subjects_repo = subjects_repo
        self.rooms_repo = rooms_repo
        self.groups_repo = groups_repo
        self.timetable_repo = timetable_repo
        self.global_room_assignments = defaultdict(list)
        self.room_locks = defaultdict(Lock)

    def generate_timetable(self, max_attempts=5000):
        teachers = self.teachers_repo.get_teachers()
        subjects = self.subjects_repo.get_subjects()
        rooms = self.rooms_repo.get_rooms()
        groups = self.groups_repo.get_groups()
        days = [TimetableEntry.Days.MONDAY, TimetableEntry.Days.TUESDAY, TimetableEntry.Days.WEDNESDAY,
                TimetableEntry.Days.THURSDAY, TimetableEntry.Days.FRIDAY]
        days = TimetableEntry.Days.__members__
        hours = range(8, 16)

        for attempt in range(max_attempts):
            valid_timetables = []

            with ThreadPoolExecutor() as executor:
                futures = [
                    executor.submit(self.generate_timetable_for_group, group, teachers, subjects, rooms, days, hours, valid_timetables)
                    for group in groups
                ]

                for future in as_completed(futures):
                    valid_timetables.extend(future.result())

            if self.validate_final_timetable(valid_timetables, groups):
                for entry in valid_timetables:
                    self.timetable_repo.add_entry(entry)
                print("Valid timetable generated!")
                return

        print("Failed to generate a valid timetable after maximum attempts.")

    def generate_timetable_for_group(self, group, teachers, subjects, rooms, days, hours, valid_timetables):
        combinations = self.get_all_combinations(group, teachers, subjects, rooms, days, hours)


        for entry in combinations:
            if self.is_valid_entry(entry, valid_timetables):
                valid_timetables.append(entry)

        return valid_timetables

    def get_all_combinations(self, group, teachers, subjects, rooms, days, hours):
        entries = []
        for subject_key, hours_required in group.necessarySubjects.items():
            subject_id, teacher_id = subject_key
            teacher = next((t for t in teachers if t._id == teacher_id), None)
            subject = next((s for s in subjects if s._id == subject_id), None)

            if not teacher or not subject:
                continue

            for day, hour, room in itertools.product(days, hours, rooms):
                if self.is_slot_available_for_group(group, day, hour) and self.is_room_compatible(subject, room):
                    entries.append(TimetableEntry(teacher, subject, group, room, day, hour))
        return entries

    def is_slot_available_for_group(self, group, day, hour):
        return all(entry.group != group or entry.day != day or entry.hour != hour
                   for entries in self.global_room_assignments.values() for entry in entries)

    def is_room_compatible(self, subject, room):
        if subject.specific_room:
            return subject.room_id == room.id
        return True

    def is_valid_entry(self, entry, existing_entries):
        lock_key = (entry.room.id, entry.hour, entry.day)
        with self.room_locks[lock_key]:
            if any(e.teacher == entry.teacher and e.day == entry.day and e.hour == entry.hour
                   for e in existing_entries):
                return False
            if any(e.room == entry.room and e.day == entry.day and e.hour == entry.hour for e in existing_entries):
                return False
            if any(e.group == entry.group and e.day == entry.day and e.hour == entry.hour for e in existing_entries):
                return False
            if not self.is_subject_balanced(entry.subject, entry.group, existing_entries):
                return False
            if not self.is_room_available(entry.room, entry.group, entry.day, entry.hour, existing_entries, entry):
                return False
            return True

    def is_room_available(self, room, group, day, hour, existing_entries, entry):
        with self.room_locks[(room.id, hour, day)]:
            if any(e.room == room and e.day == day and e.hour == hour and e.group != group for e in existing_entries):
                return False

            self.global_room_assignments[room.id].append(entry)
            return True

    def is_subject_balanced(self, subject, group, timetable):
        daily_hours = defaultdict(int)
        for entry in timetable:
            if entry.subject == subject and entry.group == group:
                daily_hours[entry.day] += 1
        return all(hours <= 5 for hours in daily_hours.values())

    def validate_final_timetable(self, timetable, groups):
        for group in groups:
            for subject_key, hours_required in group.necessarySubjects.items():
                subject_id = subject_key[0]
                assigned_hours = sum(1 for e in timetable if e.group == group and e.subject.id == subject_id)
                if assigned_hours < hours_required:
                    return False
        return True
