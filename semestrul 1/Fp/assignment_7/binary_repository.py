import pickle

def read_binary_file(file_name):
    try:
        f = open(file_name, "rb")
        return pickle.load(f)
    except EOFError:
        return []
    except IOError as e:
        print("An error occured - " + str(e))
        raise e

def write_binary_file(file_name, persons):
    f = open(file_name, "wb")
    pickle.dump(persons, f)
    f.close()

def binary_file():
    student1 =(111, "Popescu Ion", 913)
    student2 = (112 , "Ionescu Pop" , 112)
    student3 = (113, "Albert ", 311)
    student4 = (114,  "Alex ",  312 )
    student5 = (115, "Andra", 915)
    student6 = (116, "Andreea", 715)
    student7 = (117, "Taylor Swift", 826)
    student8 = (118,  "Emilia ",  936)
    student9 = (119,  "Wednesday Addams", 611)
    student10 = (120, "Horia Brenciu", 913)

    all_students = [student1, student2, student3, student4, student5, student6, student7, student8, student9, student10]
    write_binary_file("data.pickle", all_students)
    result = read_binary_file("data.pickle")
    return result