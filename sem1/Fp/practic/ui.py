from practic.repository import repo
from service import services
from prettytable import PrettyTable

class ui:
    def __init__(self, table):
        self.table = table

    def display(self):
        """
        table = repo.pretty()
        print(table)
        """
        for l in self.table:
            print(l)

    def save(self):
        x=self.table
        with open('file.txt', 'w') as w:
            w.write(str(x))

    def place(self, pattern, row, column):
        try:
            pattern=pattern.strip()

            if pattern=="blinker":
                Service=services(self.table)
                print(Service.place_blinker( row, column))
                self.save()

            elif pattern=="block":
                Service=services(self.table)
                print(Service.place_block( row, column))
                self.save()

            elif pattern == "tub":
                Service = services(self.table)
                print(Service.place_tub( row, column))
                self.save()

            elif pattern=="beacon":
                Service=services(self.table)
                print(Service.place_beacon( row, column))
                self.save()

            elif pattern=="spaceship":
                Service=services(self.table)
                print(Service.place_spaceship( row, column))
                self.save()

        except KeyError as ke:
            print("not a pattern")

    def tick(self, n):
        for i in range (n):
            Service = services(self.table)
            Service.new_gen()

    def load(self):
        """
        f = open('file.txt', 'r')

        rows = []
        for line in f:
            row = line.split()
            rows.append(row)

        self.table=rows
        """
        result = []
        try:
            f = open("file.txt", "r")
            line = f.readline().strip()
            while len(line) > 0:
                line = line.split(",")
                result.append([(line[0]), (line[1]), (line[2]), (line[3]),(line[4]),(line[5]),(line[6]),(line[7])])
                line = f.readline().strip()
            f.close()
        except IOError as e:
            print(str(e))
            raise e
        self.table=result

    def read_command(self):

        command = input("command: ")
        pos = command.find(" ")

        if pos == -1:
            return command, None

        cmd = command[:pos]

        args = command[(pos + 1):]
        args = args.split()
        for i in range (0, len(args)):
            if args[i].isdigit():
                args[i]=int(args[i])

        return cmd, args

    def print_options(self, commands):
        print(*list(commands.keys()), "exit", sep="\n")

    def menu(self):
        while True:
            print("1.display")
            print("2.place")
            print("3.tick")
            print("4.save")
            print("5.load")
            option = int(input("your option"))
            if option ==1:
                self.display()
            elif option ==2:
                row=int(input("row"))
                column=int(input("column"))
                pattern=input("pattern")
                self.place(pattern, row, column)
            elif option ==4:
                self.save()
            elif option ==5:
                self.load()
            elif option ==3:
                n=int(input("number"))
                self.tick(n)
            else:
                return


    def start(self):
        for l in self.table:
            print(l)
        #table=repo.pretty()
        #print(table)

        self.menu()
            
