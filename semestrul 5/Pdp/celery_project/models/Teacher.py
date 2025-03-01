import uuid
from typing import List

from models.Subject import Subject


class Teacher:
    def __init__(self,  _id: uuid.UUID, teacherName: str, teacherSubjects: List[uuid.UUID]):
        self.teacherName = teacherName
        self._id = _id
        self.teacherSubjects = teacherSubjects

    def AddNewSubjectForTeacher(self, subjectId: uuid.UUID):
        self.teacherSubjects.append(subjectId)

    def DoesTeacherTeachSubject(self, subjectId: uuid.UUID):
        for id in self.teacherSubjects:
            if id == subjectId:
                return True
        return False

    def __eq__(self, other) -> bool:

        if not isinstance(other, Subject):
            return False
        return self._id == other._id

    def __ne__(self, other) -> bool:

        return not self.__eq__(other)