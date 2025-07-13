class ent_book:
    def _init_(self, id, title, author):
        self.__id = id
        self.__title = title
        self.__author = author

    def set_id(self, id):
        self.__id = id

    def get_id(self):
        return self.__id

    def set_title(self, title):
        self.__title = title

    def get_title(self):
        return self.__title

    def set_author(self, author):
        self.__author = author

    def get_author(self):
        return self.__author

    def __str__(self):
        return f'id = {self.__id}, title = {self.__title}, author = {self.__author}'
    

class ent_client:
    def _init_(self, id, name):
        self.__id = id
        self.__name = name

    def set_id(self, id):
        self.__id = id

    def get_id(self):
        return self.__id

    def set_name(self, name):
        self.__name = name

    def get_name(self):
        return self.__name

    def __str__(self):
        return f'id = {self.__id}, name = {self.__name}'

class ent_rental:
    def _init_(self, rental_id, book_id, client_id, rented_date, returned_date):
        self.__rental_id = rental_id
        self.__book_id = book_id
        self.__client_id = client_id
        self.__rented_date = rented_date
        self.__returned_date = returned_date

    def set_rental_id(self, rental_id):
        self.__rental_id = rental_id

    def get_rental_id(self):
        return self.__rental_id

    def set_book_id(self, book_id):
        self.__book_id = book_id

    def get_book_id(self):
        return self.__book_id

    def set_client_id(self, client_id):
        self.__client_id = client_id

    def get_client_id(self):
        return self.__client_id

    def set_rented_date(self, rented_date):
        self.__rented_date = rented_date

    def get_rented_date(self):
        return self.__rented_date

    def set_returned_date(self, returned_date):
        self.__returned_date = returned_date

    def get_returned_date(self):
        return self.__returned_date

    def __str__(self):
        return f'rental_id = {self.__rental_id}, book_id = {self.__book_id}, client_id = {self.__client_id}, rented_date = {self.__rented_date}, returned_date = {self.__returned_date}'