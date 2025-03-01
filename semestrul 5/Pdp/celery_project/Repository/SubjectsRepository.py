import os
import uuid
import xml.etree.ElementTree as ET
from models.Subject import Subject

class SubjectsRepository:
    def __init__(self):
        self.subjects_list = []
        file_path = self.generate_default_file_path()
        if not os.path.exists(file_path):
            print(f"File not found: {file_path}")
            self.create_default_subjects_file(file_path)
        self.load_data(file_path)

    def generate_default_file_path(self):
        return os.path.join(os.getcwd(), "Subjects.xml")

    def create_new_xml_file(self, file_path):
        root = ET.Element("Subjects")
        tree = ET.ElementTree(root)
        tree.write(file_path, encoding="utf-8", xml_declaration=True)
        print(f"New Subjects.xml file created at: {file_path}")

    def load_data(self, file_path):
        print(f"Reading subjects data from file: {file_path}")
        try:
            tree = ET.parse(file_path)
            root = tree.getroot()
            if root.tag == "Subjects":
                for elem in root.findall("Subject"):
                    try:
                        subject_id = uuid.UUID(elem.get("Id"))
                        name = elem.get("Name")
                        specific_room = elem.get("SpecificRoom") == "true"
                        room_id = (
                            uuid.UUID(elem.get("RoomId")) if specific_room else None
                        )
                        subject = Subject(subject_id, name, room_id)
                        self.subjects_list.append(subject)
                    except (ValueError, TypeError):
                        print(f"Skipping invalid Subject entry: {ET.tostring(elem, encoding='unicode')}")
        except Exception as ex:
            print(f"An error occurred while loading subjects data: {ex}")

    def get_subject_guid(self, name):
        for subject in self.subjects_list:
            if subject.name == name:
                return subject.id
        return None

    def add_subject(self, subject):
        self.subjects_list.append(subject)

    def get_subjects(self):
        return self.subjects_list

    def create_default_subjects_file(self, file_path):
        print(f"Creating default subjects data file: {file_path}")
        root = ET.Element("Subjects")

        default_subjects = [
            {"Id": "a1111111-1111-1111-1111-111111111111", "Name": "Mathematics", "SpecificRoom": "false", "RoomId": "a1111111-1111-1111-1111-111111111111"},
            {"Id": "a2222222-2222-2222-2222-222222222222", "Name": "Chemistry", "SpecificRoom": "true", "RoomId": "b2222222-2222-2222-2222-222222222222"},
            {"Id": "a3333333-3333-3333-3333-333333333333", "Name": "Physics", "SpecificRoom": "true", "RoomId": "c3333333-3333-3333-3333-333333333333"},
            {"Id": "a4444444-4444-4444-4444-444444444444", "Name": "English", "SpecificRoom": "false", "RoomId": "a1111111-1111-1111-1111-111111111112"},
            {"Id": "a5555555-5555-5555-5555-555555555555", "Name": "Biology", "SpecificRoom": "true", "RoomId": "b2222222-2222-2222-2222-222222222223"},
            {"Id": "a6666666-6666-6666-6666-666666666666", "Name": "History", "SpecificRoom": "false", "RoomId": "c3333333-3333-3333-3333-333333333334"},
            {"Id": "a7777777-7777-7777-7777-777777777777", "Name": "Geography", "SpecificRoom": "false", "RoomId": "b2222222-2222-2222-2222-222222222223"},
            {"Id": "a8888888-8888-8888-8888-888888888888", "Name": "German", "SpecificRoom": "false", "RoomId": "b2222222-2222-2222-2222-222222222222"},
            {"Id": "a9999999-9999-9999-9999-999999999999", "Name": "French", "SpecificRoom": "false", "RoomId": "b2222222-2222-2222-2222-222222222222"},
            {"Id": "b1111111-1111-1111-1111-111111111111", "Name": "Computer Science", "SpecificRoom": "true", "RoomId": "d1111111-1111-1111-1111-111111111111"},
            {"Id": "b2222222-2222-2222-2222-222222222222", "Name": "Psychology", "SpecificRoom": "false", "RoomId": "d1111111-1111-1111-1111-111111111111"},
            {"Id": "b3333333-3333-3333-3333-333333333333", "Name": "Sport", "SpecificRoom": "true", "RoomId": "d1111111-1111-1111-1111-111111111112"},
        ]

        for subject_data in default_subjects:
            subject_elem = ET.Element("Subject", subject_data)
            root.append(subject_elem)

        try:
            tree = ET.ElementTree(root)
            tree.write(file_path, encoding="utf-8", xml_declaration=True)
            print("Subjects file created successfully.")
        except Exception as ex:
            print(f"An error occurred while creating the default subjects file: {ex}")
