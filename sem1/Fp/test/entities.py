class Adress:
    def __init__(self, id, name, number, x, y):
        self.__id=id
        self.__name=name
        self.__number=number
        self.__x=x
        self.__y=y

    def set_id(self,id):
        self.__id=id

    def get_id(self):
        return self.__id

    def set_name(self,name):
        self.__name=name

    def get_name(self):
        return self.__name

    def set_number(self,number):
        self.__number=number

    def get_number(self):
        return self.__number

    def set_x(self,x):
        self.__x=x

    def get_x(self):
        return self.__x

    def set_y(self,y):
        self.__y=y

    def get_y(self):
        return self.__y

    def __str__(self):
        return f'id = {self.__id}, name = {self.__name}, number={self.__number}, x={self.__x}, y={self.__y}'