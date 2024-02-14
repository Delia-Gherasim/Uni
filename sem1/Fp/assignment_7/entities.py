class Student:
    def __init__(self, id, name, group):
        self.__id = id
        self.__name = name
        self.__group = group

    def set_id(self, id):
        self.__id = id

    def get_id(self):
        return self.__id

    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

    def set_group(self, group):
        self.__group = group

    def get_group(self):
        return self.__group

    def __str__(self):
        return f'id = {self.__id}, name = {self.__name}, group = {self.__group}'
