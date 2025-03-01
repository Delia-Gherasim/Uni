import os
import uuid
import xml.etree.ElementTree as ET
from models.Teacher import Teacher

class TeachersRepository:
    def __init__(self):
        self.teachers_list = []
        file_path = self.generate_default_file_path()

        if not os.path.exists(file_path):
            print(f"File not found: {file_path}")
            self.create_default_teachers_file(file_path)

        self.load_data(file_path)

    @staticmethod
    def generate_default_file_path():
        return os.path.join(os.getcwd(), "Teachers.xml")

    @staticmethod
    def create_new_xml_file(file_path):
        root = ET.Element("Teachers")
        tree = ET.ElementTree(root)
        tree.write(file_path, encoding="utf-8", xml_declaration=True)
        print(f"New Teachers.xml file created at: {file_path}")

    def load_data(self, file_path):
        print(f"Reading teachers data from file: {file_path}")

        try:
            tree = ET.parse(file_path)
            root = tree.getroot()

            for teacher_elem in root.findall("Teacher"):
                teacher_id = teacher_elem.get("Id")
                teacher_name = teacher_elem.get("Name")

                if not teacher_id or not teacher_name:
                    continue

                subjects = []
                subjects_elem = teacher_elem.find("Subjects")
                if subjects_elem is not None:
                    for subject_elem in subjects_elem.findall("Subject"):
                        subject_id = subject_elem.get("SubjectId")
                        if subject_id:
                            subjects.append(subject_id)

                teacher = Teacher(teacher_id, teacher_name, subjects)
                self.teachers_list.append(teacher)

        except Exception as e:
            print(f"An error occurred while loading teachers data: {e}")

    def add_teacher(self, teacher):
        self.teachers_list.append(teacher)

    def get_teachers(self):
        return self.teachers_list

    @staticmethod
    def create_default_teachers_file(file_path):
        print(f"Creating default teachers data file: {file_path}")

        teachers = [
            {"Id": "a1111111-1111-1111-1111-111111111111", "Name": "Teacher_1", "Subjects": ["a1111111-1111-1111-1111-111111111111"]},
            {"Id": "a2222222-2222-2222-2222-222222222222", "Name": "Teacher_2", "Subjects": ["a2222222-2222-2222-2222-222222222222"]},
            {"Id": "a3333333-3333-3333-3333-333333333333", "Name": "Teacher_3", "Subjects": ["a3333333-3333-3333-3333-333333333333"]},
            {"Id": "a4444444-4444-4444-4444-444444444444", "Name": "Teacher_4", "Subjects": ["a4444444-4444-4444-4444-444444444444"]},
            {"Id": "a4444444-4444-4444-4444-444444444446", "Name": "Teacher_46", "Subjects": ["a4444444-4444-4444-4444-444444444444"]},
            {"Id": "a4444444-4444-4444-4444-444444444447", "Name": "Teacher_47", "Subjects": ["a4444444-4444-4444-4444-444444444444"]},
            {"Id": "a5555555-5555-5555-5555-555555555555", "Name": "Teacher_5", "Subjects": ["a5555555-5555-5555-5555-555555555555"]},
            {"Id": "a5555555-5555-5555-5555-555555555557", "Name": "Teacher_57", "Subjects": ["a5555555-5555-5555-5555-555555555555"]},
            {"Id": "a6666666-6666-6666-6666-666666666666", "Name": "Teacher_6", "Subjects": ["a6666666-6666-6666-6666-666666666666"]},
            {"Id": "a7777777-7777-7777-7777-777777777777", "Name": "Teacher_7", "Subjects": ["a7777777-7777-7777-7777-777777777777"]},
            {"Id": "a8888888-8888-8888-8888-888888888888", "Name": "Teacher_8", "Subjects": ["a8888888-8888-8888-8888-888888888888"]},
            {"Id": "a9999999-9999-9999-9999-999999999999", "Name": "Teacher_9", "Subjects": ["a9999999-9999-9999-9999-999999999999"]},
            {"Id": "b1111111-1111-1111-1111-111111111111", "Name": "Teacher_b1", "Subjects": ["b1111111-1111-1111-1111-111111111111"]},
            {"Id": "b2222222-2222-2222-2222-222222222222", "Name": "Teacher_b2", "Subjects": ["b2222222-2222-2222-2222-222222222222"]},
            {"Id": "b3333333-3333-3333-3333-333333333333", "Name": "Teacher_b3", "Subjects": ["b3333333-3333-3333-3333-333333333333"]},
            {"Id": "a1111111-1111-1111-1111-111111111112", "Name": "Teacher_12", "Subjects": [
                "a1111111-1111-1111-1111-111111111111",
                "b1111111-1111-1111-1111-111111111111"
            ]},
            {"Id": "a2222222-2222-2222-2222-222222222223", "Name": "Teacher_23", "Subjects": [
                "a2222222-2222-2222-2222-222222222222",
                "a3333333-3333-3333-3333-333333333333"
            ]},
            {"Id": "a3333333-3333-3333-3333-333333333334", "Name": "Teacher_34", "Subjects": [
                "a3333333-3333-3333-3333-333333333333",
                "a2222222-2222-2222-2222-222222222222",
                "a1111111-1111-1111-1111-111111111111"
            ]},
            {"Id": "b1111111-1111-1111-1111-111111111112", "Name": "Teacher_b12", "Subjects": [
                "b1111111-1111-1111-1111-111111111111",
                "a1111111-1111-1111-1111-111111111111"
            ]},
            {"Id": "b2222222-2222-2222-2222-222222222223", "Name": "Teacher_b23", "Subjects": [
                "b2222222-2222-2222-2222-222222222222",
                "a6666666-6666-6666-6666-666666666666"
            ]},
            {"Id": "b3333333-3333-3333-3333-333333333334", "Name": "Teacher_b34", "Subjects": ["b3333333-3333-3333-3333-333333333333"]},
            {"Id": "a5555555-5555-5555-5555-555555555556", "Name": "Teacher_56", "Subjects": [
                "a7777777-7777-7777-7777-777777777777",
                "a6666666-6666-6666-6666-666666666666"
            ]},
            {"Id": "a7777777-7777-7777-7777-777777777778", "Name": "Teacher_78", "Subjects": [
                "a9999999-9999-9999-9999-999999999999",
                "a8888888-8888-8888-8888-888888888888"
            ]},
            {"Id": "a9999999-9999-9999-9999-999999999990", "Name": "Teacher_90", "Subjects": [
                "a4444444-4444-4444-4444-444444444444",
                "a9999999-9999-9999-9999-999999999999",
                "a8888888-8888-8888-8888-888888888888"
            ]}
        ]


        root = ET.Element("Teachers")

        for teacher in teachers:
            teacher_elem = ET.SubElement(root, "Teacher", Id=teacher["Id"], Name=teacher["Name"])
            subjects_elem = ET.SubElement(teacher_elem, "Subjects")

            for subject_id in teacher["Subjects"]:
                ET.SubElement(subjects_elem, "Subject", SubjectId=subject_id)

        tree = ET.ElementTree(root)

        try:
            tree.write(file_path, encoding="utf-8", xml_declaration=True)
            print("Teachers file created successfully.")
        except Exception as e:
            print(f"An error occurred while creating the default teachers file: {e}")
