from service import services

class UI:
    """class for managing the user interface
    
    :param self.user: matrix of user's planes
    :param self.computer: matrix of computer's planes

    """
    def __init__(self, user, computer):
        self.user=user
        self.computer=computer

    def Tutorial(self):
        print("We each draw up a 10 by 10 table and we consider the indexes to be from 0 to 9")
        print("Than, we fill the table with 3 planes, looking like this")
        print("  X  ")   
        print("XXXXX")
        print("  X  ")  
        print(" XXX ")
        print("we take turns guessing each others plane's location by typying 2 coordinates: the row and column")
        print("the other needs to specify where their plane has been hit by typping HEAD, BODY, WING, or NO")
        print("when a plane has it's head hit, the whole plane is down")

    def print_table(self):
        print("My board:")
        for i in self.computer:
            print(i)

    def game(self):
        Service=services(self.user)
        comp_down=0
        user_down=0
        while comp_down<3:
            while user_down<3:
            
                row=int(input("Guess a row: "))
                while row<0 or row>=10:
                    print("invalid choice ")
                    row=int(input("Guess a row: "))

                column=int(input("Guess a column"))
                while column < 0 or column>=10:
                    print("invalid choice ")
                    column=int(input("Guess a column: "))
                
                Service=services(self.computer)
                print(Service.they_hit_me(row, column))
                if Service.they_hit_me(row, column)=="head hit":
                    comp_down=comp_down+1

                print("My turn")
                Service=services(self.user)
                print(Service.attack())
                hit=input("did i hit your plane? If so, where?")
                
                while True:
                    if hit.upper().strip() == "HEAD":
                        user_down=user_down+1
                    if hit.upper().strip() == "HEAD" or hit.upper().strip() == "WING" or hit.upper().strip() == "BODY" :
                        Service=services(self.user)
                        Service.i_hit_them(hit.upper().strip())
                        break
                    elif hit.upper().strip() =="EXIT":
                        print("Already giving up?")
                        return
                    elif hit.upper().strip()=="NO":
                        Service=services(self.user)
                        Service.empty_space()
                        break
                    else:
                        print("i dont understand...")

                    hit=input("did i hit your plane? If so, where?")

                    Service=services(self.user)
                if comp_down==3:
                    print("you win")
                    self.print_table()
                    return
                if user_down==3:
                    print("i win")
                    self.print_table()
                    return
       
  
    def run_console(self):
        while True:
            print("hi and welcome to the game ~PLANES~")
            print("here are your options:")
            print("Option 1. Tutorial")
            print("Option 2. Start game")
            print("Option 3. Exit")
            print("You can also always exit a started game by typing EXIT")
            option = int(input("Please enter your choice: "))
            if option==1:
                self.Tutorial()
            elif option ==2:
                self.game()
            elif option==3:
                return
            else:
                print("invalid input")


    def start(self):
        self.run_console()