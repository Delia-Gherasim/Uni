import random

class user:
    """function creates an empty 10 x 10 matrix that will represent the computer's guess of the player's grid
    :return arr: matrix
    """
    def userm():
        arr = [[0 for col in range(10)] for row in range(10)]
        return arr

class computer:
    """class generates a grid with 3 planes for the computer"""
    def create_plane(r, c, orientation):
        """function checks whether a part of the grid is empty and draws up a plane based on the coordonates of the head
        :param r: row, int
        :param c: column, int
        :param orientation: int, how the plane is positioned(upright, horizontally)
        """
        global m
        if orientation==1:
            if r+3<10 and c+2<10 and c-2>=0:
                if m[r][c]==0 and m[r+1][c]==0 and m[r+2][c]==0 and m[r+3][c]==0 and m[r+1][c+1]==0 and m[r+1][c+2]==0 and m[r+1][c-1]==0 and m[r+1][c-2]==0 and m[r+3][c+1]==0 and m[r+3][c-1]==0:
                        m[r][c]=1
                        m[r+1][c]=3
                        m[r+2][c]=3
                        m[r+3][c]=3
                        m[r+1][c+1]=2
                        m[r+1][c+2]=2
                        m[r+1][c-1]=2
                        m[r+1][c-2]=2
                        m[r+3][c+1]=2
                        m[r+3][c-1]=2
                        return 1
                else:
                    return None
        elif orientation==2:
            if r-3>=0 and c+2<10 and c-2>=0:
                if m[r][c]==0 and m[r-1][c]==0 and m[r-2][c]==0 and m[r-3][c]==0 and m[r-1][c+1]==0 and m[r-1][c+2]==0 and m[r-1][c-1]==0 and m[r-1][c-2]==0 and m[r-3][c+1]==0 and m[r-3][c-1]==0:
                        m[r][c]=1
                        m[r-1][c]=3
                        m[r-2][c]=3
                        m[r-3][c]=3
                        m[r-1][c+1]=2
                        m[r-1][c+2]=2
                        m[r-1][c-1]=2
                        m[r-1][c-2]=2
                        m[r-3][c+1]=2
                        m[r-3][c-1]=2
                        return 1
                else:
                    return None
        elif orientation==3:
            if r-2>=0 and c-3 >=0 and r+2<10 :
                if m[r][c]==0 and m[r][c-3]==0 and m[r][c-2]==0 and m[r][c-1]==0 and m[r-1][c-1]==0 and m[r-2][c-1]==0 and m[r+1][c-1]==0 and m[r+2][c-1]==0 and m[r-1][c-3]==0 and m[r+1][c-3]==0:
                        m[r][c]=1
                        m[r][c-3]=3
                        m[r][c-2]=3
                        m[r][c-1]=3
                        m[r-1][c-1]=2
                        m[r-2][c-1]=2
                        m[r+1][c-1]=2
                        m[r+2][c-1]=2
                        m[r-1][c-3]=2
                        m[r+1][c-3]=2
                        return 1
                else:
                    return None
        elif orientation==4:
            if r-2>=0 and c+3<10 and r+2<10:
                if m[r][c]==0 and m[r][c+3]==0 and m[r][c+2]==0 and m[r][c+1]==0 and m[r-1][c+1]==0 and m[r-2][c+1]==0 and m[r+1][c+1]==0 and m[r+2][c+1]==0 and m[r-1][c+3]==0 and m[r+1][c+3]==0:
                        m[r][c]=1
                        m[r][c+3]=3
                        m[r][c+2]=3
                        m[r][c+1]=3
                        m[r-1][c+1]=2
                        m[r-2][c+1]=2
                        m[r+1][c+1]=2
                        m[r+2][c+1]=2
                        m[r-1][c+3]=2
                        m[r+1][c+3]=2
                        return 1
                else:
                    return None

    def options(nr):
        """function generates randomly 2 coordonates for the plane's head and checks whether a plane can be put on the grid based on them
        :param nr: number of planes placed down
        """
        while nr<3:
            r=random.randint(0, 9)
            c=random.randint(0, 9)
            if computer.create_plane(r, c, 1) is not None:
                nr=nr+1
            elif computer.create_plane(r, c, 2) is not None:
                nr=nr+1
            elif computer.create_plane(r, c, 3) is not None:
                nr=nr+1
            elif computer.create_plane(r, c, 4) is not None:
                nr=nr+1
        return
            
    def compm():
        """function computes a grid of 3 planes for the computer"""
        global m
        m = [[0 for col in range(10)]  for row in range(10)]
        computer.options(0)
        return m

#for i in computer.compm():
    #print(i)