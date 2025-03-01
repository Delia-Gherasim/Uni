import uuid


class Room:
    def __init__(self, _id: uuid.UUID, capacity: int):
        self._id = _id
        self.capacity = capacity

    def __eq__(self, other) -> bool:

        if not isinstance(other, Room):
            return False
        return self._id == other._id

    def __ne__(self, other) -> bool:

        return not self.__eq__(other)