from entities import Student

def write_text(file_name, info):
    info=str(info)
    with open(file_name, "w") as f:
        f.writelines(info)

def append_text(file_name, info):
    with open(file_name, "a") as f:
        f.writelines("\n")
        f.writelines(info)


def read_text_file(file_name):
    result = []
    try:
        f = open(file_name, "r")
        line = f.readline().strip()
        while len(line) > 0:
            line = line.split(",")
            result.append(Student(int(line[0]), line[1], int(line[2])))
            line = f.readline().strip()
        f.close()
    except IOError as e:
        print("An error occured - " + str(e))
        raise e
    return result