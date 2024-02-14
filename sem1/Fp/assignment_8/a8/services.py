from entities import ent_book
from entities import ent_client
from entities import ent_rental

class service:
    def _init_(self, repository):
        self.repository=repository

    def add_client(self, new):
        if self.__find_by_id(new.ent_client.get_id()) is not None:
            raise ValueError("Duplicate ID")
        else:
            self.repository.append(new)

    def __find_by_id(self, id):
        if id in self.repository:
            return self.repository[id]
        return None

    def add_book(self, new):
        if self.__find_by_id(new.ent_book.get_id()) is not None:
            raise ValueError("Duplicate ID")
        else:
            self.repository.append(new)

    def update_client(self, old, new):
        if self.__find_by_id(new.ent_client.get_id()) is None:
            raise ValueError("Client doesn't exist")
        else:
            self.repository.ent_client.()
            self.repository.append(new)