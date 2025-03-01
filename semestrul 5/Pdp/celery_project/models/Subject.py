import uuid
from typing import Optional

class Subject:
    def __init__(self, _id:uuid.UUID, name: str, specific_room:bool, room_id: Optional[uuid.UUID] = None ):
        self._id = _id
        self.name = name
        self.specificRoom = specific_room
        self.roomId = room_id
