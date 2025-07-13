import PySimpleGUI as sg
from tkinter import *
from tkinter import messagebox
from service import services


sg.theme('DarkBlue')
class GUI:
    def __init__(self, user, computer):
        self.user=user
        self.computer=computer


    def callback_tutorial(self):
        layout=[    
        [sg.Text("We each draw up a 10 by 10 table and we consider the indexes to be from 0 to 9")],
        [sg.Text("Than, we fill the table with 3 planes, looking like this")],
        [sg.Text("  X  ") ] , 
        [sg.Text("XXXXX")],
        [sg.Text("  X  ") ], 
        [sg.Text(" XXX ")],
        [sg.Text("we take turns guessing each others plane's location by typying 2 coordinates: the row and column")],
        [sg.Text("the other needs to specify where their plane has been hit by typping HEAD, BODY, WING, or NO")],
        [sg.Text("when a plane has it's head hit, the whole plane is down")], 
        [sg.Cancel()]]

        window=sg.Window("TUTORIAL", layout, size=(1400,600))
        window.read()
        window.close()
        
    def matrx(self):
        tkWindow = Tk()
        Service=services(self.computer)
        for i in range(100):
            for j in range(100):
                button = Button(tkWindow, command=lambda i=i, j=j: Service.they_hit_me(i, j))
                button.pack()

        tkWindow.mainloop()
        #button00 = Button(tkWindow, command=Service.they_hit_me(0, 0))
        #button00.grid(row=0, column=0)

    def callback_game(self):                
        Service=services(self.user)
        comp_down=0
        user_down=0
        while comp_down<3:
            while user_down<3:
                
                layout=[[sg.Text("input a row"), sg.InputText()],
                        [sg.Text("input a column"), sg.InputText()],
                        [sg.Submit(), sg.Cancel()]]
                window = sg.Window('Simple data entry window', layout)
                event, values = window.read()
                window.close()
                
                row=int(values[0])
                column=int(values[1])
                Service=services(self.computer)
                layout=[[sg.Text((Service.they_hit_me(row, column)))],
                        [sg.Cancel]]
                window = sg.Window(' ', layout)
                window.read()
                window.close()

                if Service.they_hit_me(row, column)=="head hit":
                    comp_down=comp_down+1

                Service=services(self.user)
                layout=[[sg.Text("My turn")],
                        [sg.Text(Service.attack())],
                        [sg.Text("did i hit your plane? If so, where?"),sg.InputText()],
                        [sg.Submit(), sg.Cancel()]]
                
                window = sg.Window('Simple data entry window', layout)
                event, values = window.read()
                window.close()
                hit=str(values[0])
                while True:
                    if hit.upper().strip() == "HEAD":
                        user_down=user_down+1
                    if hit.upper().strip() == "HEAD" or hit.upper().strip() == "WING" or hit.upper().strip() == "BODY" :
                        Service=services(self.user)
                        Service.i_hit_them(hit.upper().strip())
                        break
                    elif hit.upper().strip() =="EXIT":
                        layout=[[sg.Text("Already giving up?")],
                                [sg.Cancel("no")]]
                        window = sg.Window(' ', layout)
                        window.read()
                        window.close()
                        return
                    elif hit.upper().strip()=="NO":
                        Service=services(self.user)
                        Service.empty_space()
                        break
                    else:
                        layout=[[sg.Text("i dont understand...")],
                                [sg.Cancel()]]
                        window = sg.Window(' ', layout)
                        window.read()
                        window.close()

                    layout=[[sg.Text("did i hit your plane? If so, where?"),sg.InputText()],
                            [sg.Submit(), sg.Cancel()]]
                    window = sg.Window(' ', layout)
                    window.read()
                    window.close()

                    Service=services(self.user)
                if comp_down==3:
                    layout=[[sg.Text("you win")],
                            [sg.Cance()]]
                    window = sg.Window(' ', layout)
                    window.read()
                    window.close()
                    return
                if user_down==3:
                    layout=[[sg.Text("i win")],
                            [sg.Cancel()]]
                    window = sg.Window(' ', layout)
                    window.read()
                    window.close()
                    return
        
    def start(self):
        layout=[
                [sg.Text("hi and welcome to the game ~PLANES~")],
                [sg.Text("here are your options:")],
                [sg.Button('Tutorial')],
                [sg.Button('Start game')], 
                [sg.Cancel()]         
            ]
        window=sg.Window("best_game_ever", layout, size=(1400,600))
        while True:            
            event, values = window.read()
            if event == sg.WIN_CLOSED:
                break
            elif event == 'Tutorial':
                self.callback_tutorial()       
            elif event == 'Start game':
                self.callback_game()   
            else:
                break
        window.close()