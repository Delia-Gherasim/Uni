from entities import Student
from repository import General_repository
from txt_repository import *

class Student_Repository:

    def __init__(self, all_students):
         self.__all_students = all_students

    def add_txt(self, student):
        """
        The function saves a new student to the list 
        :param student: a new student that needs to be appended
        :return nothing
        """
        if self.__find_by_id(student.get_id()) is not None:
            raise ValueError("Duplicate ID")
        else:
            write_text(file_name, student)

    def save(self, student):
        """
        The function saves a new student to the list 
        :param student: a new student that needs to be appended
        :return nothing
        """

        if self.__find_by_id(student.get_id()) is not None:
            raise ValueError("Duplicate ID")
        else:
            self.__all_students.append(student)

    def __find_by_id(self, student_id):
        """
        The function finds a student by id
        :param student_id: the student's id
        :return the student that has that specific id
        """

        if student_id in self.__all_students:
            return self.__all_students[student_id]
        return None

    def delete_by_group(self, group):
        """
        This function deletes a student by id
        :param group: the group of the student that is going to be deleted
        :return nothing
        """

        if self.__find_by_group(group) is None:
            raise ValueError("Group was not found!")
        del self.__all_students[group]

    def __find_by_group(self, group):
        """
        The function finds a student by group
        :param group: the student's group
        :return the student that has that specific group
        """
        if group in self.__all_students:
            return self.__all_students[group]
        return None

