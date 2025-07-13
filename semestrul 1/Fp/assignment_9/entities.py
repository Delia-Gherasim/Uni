"""
class entities:
    def _init_(self, row, column, hit):
        self.row=row
        self.column=column
        self.hit=hit

    def set_row(self, row):
        self.row=row

    def get_row(self):
        return self.row

    def set_column(self, column):
        self.column=column

    def get_column(self):
        return self.column

    def set_hit(self, hit):
       self.hit=hit

    def get_hit(self):
        return self.hit

    def __str__(self):
        return f'row = {self.row}, column = {self.column}, hit = {self.hit}'

"""
def get_row(move):
    return move["row"]

def set_row(move, new_row):
    move["row"]=new_row
    return move

def get_column(move):
    return move["column"]

def set_column(move, new_column):
    move["column"] = new_column
    return move

def get_hit(move):
    return move["cat"]

def set_hit(move, new_hit):
    move["hit"]=new_hit
    return move