from enum import Enum
from typing import Optional

from models.Group import Group
from models.Room import Room
from models.Subject import Subject
from models.Teacher import Teacher

class TimetableEntry:
    class Days(Enum):
        MONDAY = "Monday"
        TUESDAY = "Tuesday"
        WEDNESDAY = "Wednesday"
        THURSDAY = "Thursday"
        FRIDAY = "Friday"
    def __init__(self,teacher: Teacher, subject: Subject, group: Group, room: Room, day: Days, hour: int):
        self.teacher = teacher
        self.subject = subject
        self.group = group
        self.room = room
        self.day = day
        self.hour = hour

    def __str__(self):
        return (
            f"Combination Details:\n"
            f"  Group ID:     {self.group._id}\n"
            f"  Subject ID:   {self.subject._id}\n"
            f"  Teacher ID:   {self.teacher._id}\n"
            f"  Room ID:      {self.room._id}\n"
            f"  Hour:         {self.hour}\n"
            f"  Day:          {self.day}"
        )
        
    def __eq__(self, other):
        if not isinstance(other, TimetableEntry):
            return False
        return (
                self.hour == other.hour
                and self.day == other.day
                and self.teacher == other.teacher
                and self.group == other.group
                and self.room == other.room
        )

    def __ne__(self, other):
        return not self.__eq__(other)
