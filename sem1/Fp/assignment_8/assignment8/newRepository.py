from exceptions import *
from domain import *
from iterable import *

class Repository:
    def __init__ (self, objectList):
        self.objectList = Iterable(objectList)
    
    def valid_ID (self, ID):
        '''
        Cheks if the id is correct or not
        '''
        try:
            nr = float(ID)
        except:
            raise badId
        else:
            if nr <= 0 or int(nr) != nr:
                raise badId

    @property
    def get_list (self):
        return self.objectList

    @get_list.setter
    def get_list (self, list):
        self.objectList = list

    def store (self, object):
        self.valid_ID(object.Id)
        for i in self.get_list:
            if i.Id == object.Id:
                raise duplicateID ("duplicate id")
        self.get_list.append(object)

    def find (self, id):
        for i in range(0, len(self.get_list)):
            if self.get_list[i].Id == id:
                return i
        raise IdDoesNotExist

    def delete (self, id):
        self.valid_ID(id)
        index = self.find(id)
        if index == None:
            raise IdDoesNotExist("No such object")
            
        #self.get_list.pop(self.find(id))
        del self.get_list[self.find(id)]
    
    def __getitem__ (self, value):
        return self.get_list[value]

    def __len__ (self):
        return len(self.get_list)

    @staticmethod
    def comparison (x,y):
        if x > y:
            return False
        return True

    def sort (self):
        #self.get_list.sort()
        gnomeSort(self.get_list, self.comparison)

