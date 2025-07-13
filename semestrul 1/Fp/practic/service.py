from repository import repo

class services:
    def __init__(self, matrix):
        self.matrx=matrix

    def place_blinker(self, r, c):
        if c+2<8:
            if self.matrx[r][c]==0 :
                if self.matrx[r][c+1]==0 and self.matrx[r][c+2]==0:
                    self.matrx[r][c] ='x'
                    self.matrx[r][c+1] ='x'
                    self.matrx[r][c+2] ='x'
                    return "placed"
        return "not possible"

    def place_block(self, r, c):
        if r+1<8 and c+1<8:
            if self.matrx[r][c]==0 :
                if self.matrx[r][c+1]==0 and self.matrx[r+1][c]==0 and self.matrx[r+1][c+1]==0 :
                    self.matrx[r][c]='x'
                    self.matrx[r][c+1] ='x'
                    self.matrx[r+1][c+1] ='x'
                    self.matrx[r+1][c] ='x'
                    return "placed"
        return "not possible"

    def place_tub(self, r, c):
        if c+2<8:
            if self.matrx[r][c]==0 :
                if self.matrx[r][c+2]==0 and self.matrx[r+1][c+1]==0 and self.matrx[r-1][c+1]==0 :
                    self.matrx[r][c+2]='x'
                    self.matrx[r][c] = 'x'
                    self.matrx[r+1][c+1] ='x'
                    self.matrx[r-1][c+1] ='x'
                    return "placed"
        return "not possible"

    def place_beacon(self, r, c):
        if r+3<8:
            if self.matrx[r][c]==0 :
                if self.matrx[r][c+1]==0 and self.matrx[r+1][c+1]==0 and self.matrx[r+1][c]==0 and self.matrx[r][c+1]==0:
                    if self.matrx[r+2][c+2]==0 and self.matrx[r+3][c+2]==0 and self.matrx[r+2][c+3]==0 and self.matrx[r+3][c+3]==0 :
                        self.matrx[r][c]='x'
                        self.matrx[r][c+1] = 'x'
                        self.matrx[r+1][c+1] = 'x'
                        self.matrx[r+1][c] = 'x'
                        self.matrx[r+2][c+2] = 'x'
                        self.matrx[r+3][c+2] = 'x'
                        self.matrx[r+2][c+3] = 'x'
                        self.matrx[r+3][c+3] = 'x'
                        return "placed"
        return "not possible"

    def place_spaceship(self, r, c):
        if r+2<=8:
            if self.matrx[r][c] == 0:
                if self.matrx[r+1][c + 1] == 0 and self.matrx[r + 2][c + 1] == 0 and self.matrx[r +2][c ] == 0 and self.matrx[r+2][c-1]:
                    self.matrx[r][c] = 'x'
                    self.matrx[r+1][c+1] = 'x'
                    self.matrx[r+2][c+1] = 'x'
                    self.matrx[r+2][c] = 'x'
                    self.matrx[r + 2][c-1] = 'x'
                    return "placed"
        return "not possible"

    def new_gen(self):
        for r in range(0, 9):
            for c in range(0, 9):
                if r-1>0 and c+1<8 :
                    nr=0
                    if self.matrx[r-1][c]=='x':
                        nr=nr+1
                    if self.matrx[r-1][c+1]=='x':
                        nr=nr+1
                    if self.matrx[r-1][c-1]=='x' :
                        nr=nr+1
                    if self.matrx[r][c] == 'x':
                        nr = nr + 1
                    if self.matrx[r][c + 1] == 'x':
                        nr = nr + 1
                    if self.matrx[r - 1][c - 1] == 'x':
                        nr = nr + 1

                    if nr<2 or nr>3:
                        self.matrx[r][c]=0
                    if nr==3:
                        self.matrx[r][c]='x'