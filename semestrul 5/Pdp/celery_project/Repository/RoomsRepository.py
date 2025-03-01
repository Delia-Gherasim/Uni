import os
import uuid
import xml.etree.ElementTree as ET
from models.Room import Room

class RoomsRepository:
    def __init__(self):
        self.rooms_list = []
        file_path = self.generate_default_file_path()
        if not os.path.exists(file_path):
            self.create_new_xml_file(file_path)
            self.create_default_rooms_file(file_path)
            self.load_data(file_path)
        else:
            self.load_data(file_path)

    def generate_default_file_path(self):
        return os.path.join(os.getcwd(), "Rooms.xml")

    def create_new_xml_file(self, file_path):
        root = ET.Element("Rooms")
        tree = ET.ElementTree(root)
        tree.write(file_path, encoding="utf-8", xml_declaration=True)
        print(f"New Rooms.xml file created at: {file_path}")

    def load_data(self, file_path):
        print(f"Reading rooms data from file: {file_path}")
        try:
            tree = ET.parse(file_path)
            root = tree.getroot()
            if root.tag == "Rooms":
                for elem in root.findall("Room"):
                    room_id = elem.get("Id")
                    capacity = elem.get("Cap")
                    try:
                        room_id = uuid.UUID(room_id)
                        capacity = int(capacity)
                        room = Room(room_id, capacity)
                        self.rooms_list.append(room)
                    except (ValueError, TypeError):
                        print(f"Skipping invalid Room entry: {ET.tostring(elem, encoding='unicode')}")
        except Exception as ex:
            print(f"An error occurred while loading rooms data: {ex}")

    def add_room(self, room):
        self.rooms_list.append(room)

    def get_rooms(self):
        return self.rooms_list

    def create_default_rooms_file(self, file_path):
        print(f"Creating default rooms data file: {file_path}")
        root = ET.Element("Rooms")

        default_rooms = [
            {"Id": "a1111111-1111-1111-1111-111111111111", "Cap": "30"},
            {"Id": "b2222222-2222-2222-2222-222222222222", "Cap": "50"},
            {"Id": "c3333333-3333-3333-3333-333333333333", "Cap": "100"},
            {"Id": "a1111111-1111-1111-1111-111111111112", "Cap": "100"},
            {"Id": "b2222222-2222-2222-2222-222222222223", "Cap": "100"},
            {"Id": "c3333333-3333-3333-3333-333333333334", "Cap": "100"},
            {"Id": "d1111111-1111-1111-1111-111111111111", "Cap": "100"},
            {"Id": "d1111111-1111-1111-1111-111111111112", "Cap": "100"}
        ]

        for room_data in default_rooms:
            room_elem = ET.Element("Room", room_data)
            root.append(room_elem)

        try:
            tree = ET.ElementTree(root)
            tree.write(file_path, encoding="utf-8", xml_declaration=True)
            print("Rooms file created successfully.")
        except Exception as ex:
            print(f"An error occurred while creating the default rooms file: {ex}")
