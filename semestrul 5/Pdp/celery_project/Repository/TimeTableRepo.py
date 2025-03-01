import csv
from typing import List, Optional
from uuid import UUID
from models.TimetableEntry import TimetableEntry

class TimeTableRepo:
    def __init__(self, entries: Optional[List[TimetableEntry]] = None):
        self.list = entries if entries is not None else []

    def add_entry(self, timetable_entry: TimetableEntry):
        if timetable_entry is None:
            raise ValueError("Cannot add null entry.")
        self.list.append(timetable_entry)

    def delete_entry(self, timetable_entry: TimetableEntry):
        if timetable_entry is None:
            raise ValueError("Cannot delete null entry.")
        self.list.remove(timetable_entry)

    def get_entries_by_teacher_id(self, teacher_id: UUID) -> List[TimetableEntry]:
        return [entry for entry in self.list if entry.teacher and entry.teacher._id == teacher_id]

    def get_entries(self) -> List[TimetableEntry]:
        return self.list

    def get_entries_by_subject_id(self, subject_id: UUID) -> List[TimetableEntry]:
        return [entry for entry in self.list if entry.subject and entry.subject._id == subject_id]

    def get_entries_by_group_id(self, group_id: UUID) -> List[TimetableEntry]:
        return [entry for entry in self.list if entry.group and entry.group._id == group_id]

    def get_entries_by_room_id(self, room_id: UUID) -> List[TimetableEntry]:
        return [entry for entry in self.list if entry.room and entry.room._id == room_id]

    def print_to_csv(self, file_path: str):
        try:
            with open(file_path, mode='w', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(["Teacher", "Subject", "GroupID", "RoomID", "Day", "Hour"])
                for entry in self.list:
                    teacher_name = entry.teacher.teacherName if entry.teacher else "Unknown"
                    subject_name = entry.subject.name if entry.subject else "Unknown"
                    group_id = str(entry.group._id) if entry.group else "Unknown"
                    room_id = str(entry.room._id) if entry.room else "Unknown"
                    day = str(entry.day)
                    hour = str(entry.hour)
                    writer.writerow([teacher_name, subject_name, group_id, room_id, day, hour])

            if not self.list:
                print("No entries in the timetable.")

            print("Timetable successfully exported to CSV.")
        except Exception as ex:
            print(f"An error occurred while exporting to CSV: {ex}")
