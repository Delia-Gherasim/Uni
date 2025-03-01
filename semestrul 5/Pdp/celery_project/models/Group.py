import uuid
from typing import Dict, Tuple


class Group:
    def __init__(self, id: uuid.UUID, nrOfKids: int, necessarySubjects: Dict[Tuple[uuid.UUID, uuid.UUID], int]):

        self._id = id
        self.nrOfKids = nrOfKids
        self.necessarySubjects = necessarySubjects

    def does_group_have_subject(self, subject: uuid.UUID, teacher: uuid.UUID = None) -> bool:

        if teacher:
            return (subject, teacher) in self.necessarySubjects
        return any(key[0] == subject for key in self.necessarySubjects)

    def __eq__(self, other) -> bool:

        if not isinstance(other, Group):
            return False
        return self._id == other._id

    def __ne__(self, other) -> bool:

        return not self.__eq__(other)

    def get_required_hours_for_subject(self, subject_id: uuid.UUID, teacher_id: uuid.UUID) -> int:

        key = (subject_id, teacher_id)
        return self.necessarySubjects.get(key, 0)
