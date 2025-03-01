import os
import uuid
import xml.etree.ElementTree as ET
from typing import Dict, List, Tuple
from models.Group import Group

class GroupsRepository:
    def __init__(self):
        self.groups_list: List[Group] = []
        file_path = self.generate_default_file_path()

        if not os.path.exists(file_path):
            print(f"File not found, creating one: {file_path}")
            self.create_new_xml_file(file_path)
            self.create_default_groups_file(file_path)
        self.load_data(file_path)

    def create_new_xml_file(self, file_path: str):
        root = ET.Element("Groups")
        tree = ET.ElementTree(root)
        tree.write(file_path, encoding="utf-8", xml_declaration=True)
        print(f"New Groups.xml file created at: {file_path}")

    def generate_default_file_path(self):
        return os.path.join(os.getcwd(), "Groups.xml")

    def load_data(self, file_path: str):
        print(f"Reading groups data from file: {file_path}")
        try:
            tree = ET.parse(file_path)
            root = tree.getroot()

            for elem in root.findall("Group"):
                group_id = elem.get("Id")
                nr_of_kids = elem.get("NrOfKids")

                if not group_id or not nr_of_kids:
                    continue

                try:
                    group_id = uuid.UUID(group_id)
                    nr_of_kids = int(nr_of_kids)
                except ValueError:
                    continue

                necessary_subjects = {}
                subjects_element = elem.find("NecessarySubjects")

                if subjects_element is not None:
                    for subject_elem in subjects_element.findall("Subject"):
                        subject_id = subject_elem.get("SubjectId")
                        teacher_id = subject_elem.get("TeacherId")
                        hours = subject_elem.get("Hours")

                        if not subject_id or not teacher_id or not hours:
                            continue

                        try:
                            subject_id = uuid.UUID(subject_id)
                            teacher_id = uuid.UUID(teacher_id)
                            hours = int(hours)
                        except ValueError:
                            continue

                        necessary_subjects[(subject_id, teacher_id)] = hours

                group = Group(group_id, nr_of_kids, necessary_subjects)
                self.groups_list.append(group)

        except Exception as ex:
            print(f"An error occurred while loading groups data: {ex}")

    def get_group_guid_by_nr_of_kids(self, nr_of_kids: int) -> uuid.UUID:
        for group in self.groups_list:
            if group.nr_of_kids == nr_of_kids:
                return group.group_id
        return uuid.UUID(int=0)

    def add_group(self, group: Group):
        self.groups_list.append(group)

    def get_groups(self) -> List[Group]:
        return self.groups_list

    def create_default_groups_file(self, file_path: str):
        print(f"Creating default groups data file: {file_path}")
        root = ET.Element("Groups")
        group_data = [
            {
                "Id": "f949b1f0-2718-487b-a1a0-c1b4729ac7a9",
                "NrOfKids": 30,
                "NecessarySubjects": [
                    {"SubjectId": "a1111111-1111-1111-1111-111111111111", "TeacherId": "a1111111-1111-1111-1111-111111111111", "Hours": 4},
                    {"SubjectId": "a2222222-2222-2222-2222-222222222222", "TeacherId": "a2222222-2222-2222-2222-222222222222", "Hours": 2},
                    {"SubjectId": "a3333333-3333-3333-3333-333333333333", "TeacherId": "a3333333-3333-3333-3333-333333333333", "Hours": 3},
                    {"SubjectId": "a4444444-4444-4444-4444-444444444444", "TeacherId": "a4444444-4444-4444-4444-444444444444", "Hours": 4},
                    {"SubjectId": "a5555555-5555-5555-5555-555555555555", "TeacherId": "a5555555-5555-5555-5555-555555555555", "Hours": 1},
                    {"SubjectId": "a6666666-6666-6666-6666-666666666666", "TeacherId": "a6666666-6666-6666-6666-666666666666", "Hours": 1},
                    {"SubjectId": "a7777777-7777-7777-7777-777777777777", "TeacherId": "a7777777-7777-7777-7777-777777777777", "Hours": 1},
                    {"SubjectId": "a8888888-8888-8888-8888-888888888888", "TeacherId": "a8888888-8888-8888-8888-888888888888", "Hours": 2},
                    {"SubjectId": "b1111111-1111-1111-1111-111111111111", "TeacherId": "b1111111-1111-1111-1111-111111111111", "Hours": 4},
                    {"SubjectId": "b3333333-3333-3333-3333-333333333333", "TeacherId": "b3333333-3333-3333-3333-333333333333", "Hours": 2},
                ],
            },
            {
                "Id": "f949b1f0-2718-487b-a1a0-c1b4729ac7a8",
                "NrOfKids": 30,
                "NecessarySubjects": [
                    {"SubjectId": "a1111111-1111-1111-1111-111111111111", "TeacherId": "a1111111-1111-1111-1111-111111111111", "Hours": 5},
                    {"SubjectId": "a2222222-2222-2222-2222-222222222222", "TeacherId": "a2222222-2222-2222-2222-222222222222", "Hours": 2},
                    {"SubjectId": "a3333333-3333-3333-3333-333333333333", "TeacherId": "a3333333-3333-3333-3333-333333333333", "Hours": 3},
                    {"SubjectId": "a4444444-4444-4444-4444-444444444444", "TeacherId": "a4444444-4444-4444-4444-444444444444", "Hours": 2},
                    {"SubjectId": "a5555555-5555-5555-5555-555555555555", "TeacherId": "a5555555-5555-5555-5555-555555555555", "Hours": 1},
                    {"SubjectId": "a6666666-6666-6666-6666-666666666666", "TeacherId": "a6666666-6666-6666-6666-666666666666", "Hours": 1},
                    {"SubjectId": "a7777777-7777-7777-7777-777777777777", "TeacherId": "a7777777-7777-7777-7777-777777777777", "Hours": 1},
                    {"SubjectId": "a8888888-8888-8888-8888-888888888888", "TeacherId": "a8888888-8888-8888-8888-888888888888", "Hours": 2},
                    {"SubjectId": "b1111111-1111-1111-1111-111111111111", "TeacherId": "b1111111-1111-1111-1111-111111111111", "Hours": 5},
                    {"SubjectId": "b3333333-3333-3333-3333-333333333333", "TeacherId": "b3333333-3333-3333-3333-333333333333", "Hours": 2},
                ],
            },
            {
                "Id": "c87c9e5b-3a5e-4f0e-badd-990396d12be7",
                "NrOfKids": 25,
                "NecessarySubjects": [
                    {"SubjectId": "a1111111-1111-1111-1111-111111111111", "TeacherId": "a1111111-1111-1111-1111-111111111112", "Hours": 3},
                    {"SubjectId": "b2222222-2222-2222-2222-222222222222", "TeacherId": "b2222222-2222-2222-2222-222222222223", "Hours": 2},
                    {"SubjectId": "b3333333-3333-3333-3333-333333333333", "TeacherId": "b3333333-3333-3333-3333-333333333334", "Hours": 2},
                    {"SubjectId": "a4444444-4444-4444-4444-444444444444", "TeacherId": "a4444444-4444-4444-4444-444444444446", "Hours": 5},
                    {"SubjectId": "a5555555-5555-5555-5555-555555555555", "TeacherId": "a5555555-5555-5555-5555-555555555557", "Hours": 1},
                    {"SubjectId": "a6666666-6666-6666-6666-666666666666", "TeacherId": "a6666666-6666-6666-6666-666666666666", "Hours": 3},
                    {"SubjectId": "a7777777-7777-7777-7777-777777777777", "TeacherId": "a5555555-5555-5555-5555-555555555556", "Hours": 2},
                    {"SubjectId": "a8888888-8888-8888-8888-888888888888", "TeacherId": "a7777777-7777-7777-7777-777777777778", "Hours": 3},
                    {"SubjectId": "a9999999-9999-9999-9999-999999999999", "TeacherId": "a9999999-9999-9999-9999-999999999990", "Hours": 3},
                ],
            },
            {
                "Id": "c87c9e5b-3a5e-4f0e-badd-990396d12be8",
                "NrOfKids": 25,
                "NecessarySubjects": [
                    {"SubjectId": "a1111111-1111-1111-1111-111111111111", "TeacherId": "a1111111-1111-1111-1111-111111111112", "Hours": 3},
                    {"SubjectId": "b2222222-2222-2222-2222-222222222222", "TeacherId": "b2222222-2222-2222-2222-222222222222", "Hours": 2},
                    {"SubjectId": "b3333333-3333-3333-3333-333333333333", "TeacherId": "b3333333-3333-3333-3333-333333333333", "Hours": 2},
                    {"SubjectId": "a4444444-4444-4444-4444-444444444444", "TeacherId": "a4444444-4444-4444-4444-444444444446", "Hours": 5},
                    {"SubjectId": "a5555555-5555-5555-5555-555555555555", "TeacherId": "a5555555-5555-5555-5555-555555555557", "Hours": 1},
                    {"SubjectId": "a6666666-6666-6666-6666-666666666666", "TeacherId": "a5555555-5555-5555-5555-555555555556", "Hours": 3},
                    {"SubjectId": "a7777777-7777-7777-7777-777777777777", "TeacherId": "a5555555-5555-5555-5555-555555555556", "Hours": 2},
                    {"SubjectId": "a8888888-8888-8888-8888-888888888888", "TeacherId": "a7777777-7777-7777-7777-777777777778", "Hours": 3},
                    {"SubjectId": "a9999999-9999-9999-9999-999999999999", "TeacherId": "a9999999-9999-9999-9999-999999999999", "Hours": 3},
                ],
            },
            {
                "Id": "b33d6c3a-5c5f-4738-bfb9-f3ef77563a9c",
                "NrOfKids": 28,
                "NecessarySubjects": [
                    {"SubjectId": "a1111111-1111-1111-1111-111111111111", "TeacherId": "a1111111-1111-1111-1111-111111111111", "Hours": 3},
                    {"SubjectId": "b2222222-2222-2222-2222-222222222222", "TeacherId": "b2222222-2222-2222-2222-222222222223", "Hours": 3},
                    {"SubjectId": "b3333333-3333-3333-3333-333333333333", "TeacherId": "b3333333-3333-3333-3333-333333333334", "Hours": 2},
                    {"SubjectId": "a4444444-4444-4444-4444-444444444444", "TeacherId": "a4444444-4444-4444-4444-444444444447", "Hours": 5},
                    {"SubjectId": "a5555555-5555-5555-5555-555555555555", "TeacherId": "a5555555-5555-5555-5555-555555555555", "Hours": 1},
                    {"SubjectId": "a6666666-6666-6666-6666-666666666666", "TeacherId": "b2222222-2222-2222-2222-222222222223", "Hours": 4},
                    {"SubjectId": "a7777777-7777-7777-7777-777777777777", "TeacherId": "a7777777-7777-7777-7777-777777777777", "Hours": 4},
                    {"SubjectId": "a8888888-8888-8888-8888-888888888888", "TeacherId": "a8888888-8888-8888-8888-888888888888", "Hours": 2},
                    {"SubjectId": "a9999999-9999-9999-9999-999999999999", "TeacherId": "a9999999-9999-9999-9999-999999999999", "Hours": 2},
                    {"SubjectId": "a3333333-3333-3333-3333-333333333333", "TeacherId": "a3333333-3333-3333-3333-333333333333", "Hours": 2},
                ],
            },
        ]


        # for group_id, nr_of_kids, subjects in group_data:
        #     group_elem = ET.SubElement(root, "Group", Id=group_id, NrOfKids=str(nr_of_kids))
        #     subjects_elem = ET.SubElement(group_elem, "NecessarySubjects")

        #     for subject_id, teacher_id, hours in subjects:
        #         ET.SubElement(subjects_elem, "Subject", SubjectId=subject_id, TeacherId=teacher_id, Hours=str(hours))
        root = ET.Element("Groups")

        for group in group_data:
            group_id = group["Id"]
            nr_of_kids = group["NrOfKids"]
            subjects = group["NecessarySubjects"]
            
            group_elem = ET.SubElement(root, "Group", Id=group_id, NrOfKids=str(nr_of_kids))
            subjects_elem = ET.SubElement(group_elem, "NecessarySubjects")
            
            for subject in subjects:
                subject_id = subject["SubjectId"]
                teacher_id = subject["TeacherId"]
                hours = subject["Hours"]
                ET.SubElement(subjects_elem, "Subject", SubjectId=subject_id, TeacherId=teacher_id, Hours=str(hours))

        
        try:
            tree = ET.ElementTree(root)
            tree.write(file_path, encoding="utf-8", xml_declaration=True)
            print("Groups data file created successfully.")
        except Exception as ex:
            print(f"An error occurred while creating the default groups file: {ex}")
