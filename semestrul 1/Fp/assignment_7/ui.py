from services import Student_services
from entities import Student
from copy import deepcopy
from txt_repository import write_text
from txt_repository import read_text_file
from txt_repository import append_text

class UI:
    """class for managing the user interface
    
    :param self: list of all students

    """
    def __init__(self, service):
        self.service = service
        self.history = [service]

    def ui_add_student(self):
        #user interface for adding students
        
        id = input("Input the id ")
        try:
            id = int(id)
        except ValueError:
            print("Invalid ID ")
            return
        name = input("Input the name of your student: ")
        group = input("Input the group of your student: ")
        try:
            group = int(group)
        except ValueError:
            print("Invalid group ")
            return

        try:
                #for memory:
            students = Student_services(self.service)
            student = Student(id, name, group)
            #students.add_student(student)


                #for text:            
            append_text("all_students.txt", (str(id)," , ", name," , ", str(group)))
            self.service=read_text_file("all_students.txt")


            self.history.append(self.service)
            print("Success \n")
        except Exception as e:
            print(e)

    def ui_display_students(self):
        print("The list has " + str(len(self.service)) + " students")
        students = Student_services(self.service)
        for b in self.service:
            print(b)

    def ui_filter(self):
        group = input("Enter the group you wish to filter by: ")
        students = Student_services(self.service)
        students.delete_students(group)
        self.history.append(self.service)
        print("Success \n")

    def ui_undo(self):
        if len(self.history) == 1:
            print("There are no more operations to undo \n")
        else:
            self.service=self.history[-1]
            self.history.pop()
            print("Success \n")

    def run_console(self):
        while True:
            print("Manage the list of students:")
            print("Option 1 : Add a new student")
            print("Option 2 : Display the list of students")
            print("Option 3: Filter by group")
            print("Option 4: Undo the last operation that modified program data")
            print("Option 5: Exit")
            option = int(input("Please enter your choice: "))
            self.service = deepcopy(self.history[-1])
            if option == 1:
                self.ui_add_student()
            elif option == 2:
                self.ui_display_students()
            elif option == 3:
                self.ui_filter()
            elif option == 4:
                self.ui_undo()
            elif option == 5:
                exit()
            else:
                print("Invalid choice ")

    def start(self):
        self.run_console()