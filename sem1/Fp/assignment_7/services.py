from students_repository import Student_Repository

class Student_services:
    """
    class for operating the coresponding functions"""

    def __init__(self, new_list):
        self.__all_students = new_list

    def add_student(self, student):
        """"
        This function adds a student to the list 
        :param student: the new book to be added
        :return: nothing
        """

        students = Student_Repository(self.__all_students)
        students.save(student)

    def delete_students(self, group_to_remove):
        """"
        This function deletes all the students from a group
        :param: group_to_remove: the given group
        :returns: nothing
        """

        for i in range(len(self.__all_students) - 1):
            group = self.__all_students[i].get_group()
            if group == group_to_remove:
                del self.__all_students[i]

