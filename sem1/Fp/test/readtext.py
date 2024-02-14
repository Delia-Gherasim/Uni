def read_text_file(file_name):
    result = []
    try:
        f = open(file_name, "r")
        line = f.readline().strip()
        while len(line) > 0:
            result.append(line)
            line = f.readline().strip()
        f.close()
    except IOError as e:
        print("An error occured - " + str(e))
        raise e

    return result