from services import service
class UI:
    def __init__(self, adresses):
        self.adresses=adresses

    def print_options(self):
        print("1. first")
        print("2. second")
        print("3. third")
        print("4. 4th")
        print("any other number. exit")

    def add(self):
        id=int(input("id"))
        while id<0 or id!=int(id):
            print("invalid")
            id=int(input("id"))
        name=input("name")
        while len(name)<3:
            print("invalid")
            name=input("name")
        number=int(input("number"))
        while number<0 or number!=int(number) or number>100:
            print("invalid")
            number=int(input("number"))
        x=int(input("x"))
        while x<-100 or x!=int(x) or x>100:
            print("invalid")
            x=int(input("x"))
        y=int(input("y"))
        while y<-100 or y!=int(y) or y>100:
            print("invalid")
            y=int(input("y"))

        Service=service(self.adresses)
        Service.add_to_file(id, name, number, x, y)


    def display(self):
        print(self.adresses)

    def stations(self):
        x=int(input("x"))
        while x<-100 or x!=int(x) or x>100:
            print("invalid")
            x=int(input("x"))
        y=int(input("y"))
        while y<-100 or y!=int(y) or y>100:
            print("invalid")
            y=int(input("y"))
        d=int(input("d"))
        while d!=int(d) :
            print("invalid")
            d=int(input("d"))

        Service=service(self.adresses)
        ret=Service.nr3( x, y, d)
        print(ret)

    def coord(self):
        Service=service(self.adresses)
        Service.nr4()
        
    def menu(self):
        self.print_options()
        opt=int(input("option "))
        while True:
            
            if opt==1:
                self.add()
            elif opt==2:
                self.display()
            elif opt==3:
                self.stations()
            elif opt==4:
                self.coord()
            else:
                 return
            self.print_options()
            opt=int(input("option "))