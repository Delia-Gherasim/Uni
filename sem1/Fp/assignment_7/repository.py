from entities import Student

class General_repository:
    def __init__(self):
        student1 = Student(111, "Popescu Ion", 913)
        student2 = Student(112 , "Ionescu Pop" , 112)
        student3 = Student(113, "Albert ", 311)
        student4 = Student(114,  "Alex ",  312 )
        student5 = Student(115, "Andra", 915)
        student6 = Student(116, "Andreea", 715)
        student7 = Student(117, "Taylor Swift", 826)
        student8 = Student(118,  "Emilia ",  936)
        student9 = Student(119,  "Wednesday Addams", 611)
        student10 = Student(120, "Horia Brenciu", 913)

        self.all_students = [student1, student2, student3, student4, student5, student6, student7, student8, student9, student10]

    def get_list(self):
        return self.all_students
