
from entities import *
import random

class services:
    """
    class for operating the coresponding functions
    """
    global me
    global user
    
    me=[]
    user=[]

    def __init__(self, matrix):
        self.matrix=matrix

    def matrix_find(self, row, column):
        """ function returns the value of a given square within the matrix

        :param row: int
        :param column: int
        """
        if self.matrix[row][column]==1:
            return "HEAD"
        elif self.matrix[row][column]==2:
            return "WING"
        elif self.matrix[row][column]==3:
            return "BODY"
        return None

    def full_body(self, r, c):
        """function computes the position of a full plane and marks them as hit with an 'x', being given the coordonates of the head
        :param r: row, int
        :param c: column, int
        """
            #cap in sus
        if r+3<10 and c+2<10 and c-2>=0:
            if self.matrix[r+1][c]==3 or self.matrix[r+1][c]=='x':
                if (self.matrix[r+1][c+1]==2 or self.matrix[r+1][c+1]=='x') and (self.matrix[r+1][c+2]==2 or self.matrix[r+1][c+2]=='x'):
                    if (self.matrix[r+1][c-1]==2 or self.matrix[r+1][c-1]=='x' )and (self.matrix[r+1][c-2]==2 or self.matrix[r+1][c-2]=='x'):
                        for i in range(r, r+4):
                            self.matrix[i][c]='x'
                        self.matrix[r+1][c+1]='x'
                        self.matrix[r+1][c+2]='x' 
                        self.matrix[r+1][c-1]='x' 
                        self.matrix[r+1][c-2]='x'
                        self.matrix[r+3][c-1]='x'
                        self.matrix[r+3][c+1]='x'
                        return
                #cap in stanga
        if c+3<10 and r+2<10 and r-2>=0:
            if self.matrix[r][c+1]==3 or self.matrix[r][c+1]=='x':
                if (self.matrix[r-2][c+1]==2 or self.matrix[r-2][c+1]=='x') and (self.matrix[r-1][c+1]==2 or self.matrix[r-1][c+1]=='x') and (self.matrix[r+1][c+1]==2 or self.matrix[r+1][c+1]=='x') and (self.matrix[r+2][c+1]==2 or self.matrix[r+2][c+1]=='x'):
                    for i in range(c, c+4):
                        self.matrix[r][i]='x'
                    self.matrix[r+1][c+1]='x'
                    self.matrix[r+2][c+1]='x' 
                    self.matrix[r-1][c+1]='x' 
                    self.matrix[r-2][c+1]='x'
                    self.matrix[r-1][c+3]='x'
                    self.matrix[r+1][c+3]='x'
                    return
                #cap in dreapta
        if c-3>=0 and r+2<10 and r-2>=0:
            if self.matrix[r][c-1]==3 or self.matrix[r][c-1]=='x':
                if (self.matrix[r-2][c-1]==2 or self.matrix[r-2][c-1]=='x') and (self.matrix[r-1][c-1]==2 or self.matrix[r-1][c-1]=='x') and (self.matrix[r+1][c-1]==2 or self.matrix[r+1][c-1]=='x') and (self.matrix[r+2][c-1]==2 or self.matrix[r+2][c-1]=='x'):
                    for i in range(c, c-4, -1):
                        self.matrix[r][i]='x'
                    self.matrix[r+1][c-1]='x'
                    self.matrix[r+2][c-1]='x' 
                    self.matrix[r-1][c-1]='x' 
                    self.matrix[r-2][c-1]='x'
                    self.matrix[r-1][c-3]='x'
                    self.matrix[r+1][c-3]='x'
                    return
                #sta in cap
        if r-3>=0 and c+2<10 and c-2>=0:
            if self.matrix[r-1][c]==3 or self.matrix[r-1][c]=='x':
                if (self.matrix[r-1][c+1]==2 or self.matrix[r-1][c+1]=='x') and (self.matrix[r-1][c+2]==2 or self.matrix[r-1][c+2]=='x'):
                    if (self.matrix[r-1][c-1]==2 or self.matrix[r-1][c-1]=='x') and (self.matrix[r-1][c-2]==2 or self.matrix[r-1][c-2]=='x'):
                        for i in range(r, r-4, -1):
                            self.matrix[i][c]='x'
                        self.matrix[r-1][c+1]='x'
                        self.matrix[r-1][c+2]='x' 
                        self.matrix[r-1][c-1]='x' 
                        self.matrix[r-1][c-2]='x'
                        self.matrix[r-3][c-1]='x'
                        self.matrix[r-3][c+1]='x'
                        return
        return None


    def they_hit_me(self, row, column):
        """function appends a user's move and registers within the matrix the coordonates that have been struck
        :param row: int
        :param column: int
        :return: whether or not a part of the plane has been struck
        """
        result=self.matrix_find(row, column)
        if result is not None:
            if result=="HEAD":
                user.append([row, column, "HEAD"])
                self.matrix[row][column]='x'
                self.full_body(row, column)
                return "head hit"
            elif result=="WING":
                user.append([row, column, "WING"])
                self.matrix[row][column]='x'
                return "wing down"
            elif result=="BODY":
                user.append([row, column, "BODY"])
                self.matrix[row][column]='x'
                return "body hit"
        else:
            user.append([row, column, "None"])
            return None

    def headless_rider(self):
        """function searches the list of computer moves for a value "body", and using the coordonates of a hit part of body, it computes where the head would be
        :return coordonates of head of plane, or none
        """
        #d = next((d for d in self.matrix if "BODY" in d), None)
        d = next((d for d in me if "BODY" in d), None)
        while d is not None:
            c=d.get_column()
            r=d.get_row()
            if self.matrix[r+1][c]==3 and self.matrix[r-1][c]==3:
                if self.matrix[r+2][c]==0:
                    return r+2, c
                elif self.matrix[r-2][c]==0:
                    return r-2, c
            elif self.matrix[r+1][c]==3 and self.matrix[r+2][c]==3 :
                if self.matrix[r-1][c]==0:
                    return r-1, c
                elif self.matrix[r+3][c]==0:
                    return r+3, c
            elif self.matrix[r-1][c]==3 and self.matrix[r-2][c]==3:
                if self.matrix[r-3][c]==0:
                    return r-3, c
                elif self.matrix[r+1][c]==0:
                    return r+1, c
            elif self.matrix[r][c+1]==3 and self.matrix[r][c+2]==3:
                if self.matrix[r][c+3]==0:
                    return r, c+3
                elif self.matrix[r][c-1]==0:
                    return r, c-1
            elif self.matrix[r][c-1]==3 and self.matrix[r][c+1]==3:
                if self.matrix[r][c+2]==0:
                    return r, c+2
                elif self.matrix[r][c-2]==0:
                    return r, c-2
            elif self.matrix[r][c-2]==3 and self.matrix[r][c-1]==3 : 
                if self.matrix[r][c+1]==0:
                    return r, c+1
                elif self.matrix[r][c-3]==0:
                    return r, c-3

            #d = next((d for d in self.matrix if "BODY" in d), None)
            d = next((d for d in me if "BODY" in d), None)
        return None

    def attack(self):
        """function checks whether the computer can make a winning move by hitting a plane's head or generates 2 coordonates randomly
        :return: row, column, int 
        """
        
        if self.headless_rider() is not None:
            r,c=self.headless_rider()
            if r>=0 and r<=10 and c>=0 and c<=10:
                return r,c
        
        row=random.randint(0, 9)
        column=random.randint(0, 9)
        while row in me and column in me is not None:
            row=random.randint(0, 9)
            column=random.randint(0, 9)
        me.append([row, column, "WAIT"])
        return row, column

    def head_hit(self):
        """function registers in the list of moves that a head has been hit and changes the values within the matrix acordingly
        """
        me[-1][2]="HEAD"
        r=int(me[-1][0])
        c=int(me[-1][1])
        self.full_body(r,c)
        return

    def wing_hit(self):
        """function registers in the list of moves that a wing has been hit and changes the values within the matrix acordingly
        """
        me[-1][2]="WING"
        r=int(me[-1][0])
        c=int(me[-1][1])
        self.matrix[r][c]='x'
        return

    def body_hit(self):
        """function registers in the list of moves that a body part has been hit and changes the values within the matrix acordingly
        """
        me[-1][2]="BODY"
        r=int(me[-1][0])
        c=int(me[-1][1])
        self.matrix[r][c]='x'
        return

    def empty_space(self):
        """function registers in the list of moves that no plane has been hit and changes the values within the matrix acordingly
        """
        me[-1][2]="NO"
        r=int(me[-1][0])
        c=int(me[-1][1])
        self.matrix[r][c]='.'
        return

    def i_hit_them(self, hit):
        """function computes if computer's according to the user's input 
        :param hit: string, part of plane
        """
        #global user_planes_down
        if hit.upper().strip() == "HEAD":
            self.head_hit()
        elif hit.upper().strip() == "WING":
            self.wing_hit()
        elif hit.upper().strip() == "BODY":
            self.body_hit()
        elif hit.upper().strip()=="NO":
            self.empty_space()


