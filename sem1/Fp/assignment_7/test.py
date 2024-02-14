from services import Student_services
from entities import Student
from ui import UI
from unittest import *

def test_add():
    service=Student_services([])
    service.all_students=[]
    service.add_student(Student(123, "iulian", 344))
   
    assert len(service.all_students) == 1
    assert service.all_students[0]==123
    assert service.all_students[1]=="iulian"
    assert service.all_students[2]==344


test_add()