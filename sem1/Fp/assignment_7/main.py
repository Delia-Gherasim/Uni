from ui import UI
import txt_repository
from repository import General_repository
from binary_repository import *

"""
Manage a list of students. Each student has an id (integer, unique), a name (string) and a group (positive integer). Provide the following features:

Add a student. Student data is read from the console.
Display the list of students.
Filter the list so that students in a given group (read from the console) are deleted from the list.
Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

"""
all_students = txt_repository.read_text_file("all_students.txt")
#students = General_repository()
#all_students = students.get_list()
#all_students = binary_file()

ui = UI(all_students)

ui.start()
