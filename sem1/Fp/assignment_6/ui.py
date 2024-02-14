from functions import *
from entities import *

def add(all_expenses, sum, cat):
    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param sum: integer holding the sum spent
    :param cat: string holding the category
    """
    undo_matrix.append(all_expenses)
    try:
        sum = int(sum)
        cat = str(cat)
        add_expenses(all_expenses, sum, cat)
        print("command succesfull")
    except ValueError as ve:
        print("Invalid input", ve)

def insert(all_expenses, day, sum, cat):
    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param day: integer holding the day of the spending
    :param sum: integer holding the sum spent
    :param cat: string holding the category
    """
    undo_matrix.append(all_expenses)
    try:
        day=int(day)
        sum = int(sum)
        cat = str(cat)
        insert_expenses(all_expenses, day, sum, cat)
        print("command succesfull")
    except ValueError as ve:
        print("Invalid input", ve)

def remove(all_expenses, arg ):

    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param arg: list holding the values to be removed
    """
    undo_matrix.append(all_expenses)
    try:
        if "to" in arg:
            i=arg.index('to')
            start=int(arg[0])
            end=int(arg[2])
            all_expenses=remove_expenses(all_expenses, start, end, None)
            print("command succesfull")
    
        if is_integer_num(arg[0]):
            all_expenses=remove_expenses(all_expenses, arg[0], None, None )
            print("command succesfull")
        else:
            cat=str(arg[0])
            all_expenses=remove_expenses(all_expenses, None, None, cat)
        print("command succesfull")

    except ValueError as ve:
        print("Invalid input", ve)

def display(all_expenses, arg):

    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param arg: list holding the values to be rdisplayed
    """
    categ=None
    cond=None
    val=None
    if len(arg)==1:
        categ=arg[0]  
    else:
        if len(arg)==3:
            categ=arg[0]
            cond=arg[1]
            val=arg[2]        

    if cond is not None:
        for i in range(0, len(all_expenses)):
            if get_category(all_expenses[i])==categ:
                if cond=='=':
                    if get_sum(all_expenses[i])==val:
                        print(all_expenses[i])
                if cond=='<':
                    if get_sum(all_expenses[i])<val:
                        print(all_expenses[i])
                if cond=='>':
                    if get_sum(all_expenses[i])>val:
                        print(all_expenses[i])
    else:
        if categ is not None:
            for i in range(0, len(all_expenses)):
                if get_category(all_expenses[i])==categ:
                    print(all_expenses[i])
        else:
            print(all_expenses)

def filtr(all_expenses, arg):
    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param arg: list holding the values to be removed
    """
    undo_matrix.append(all_expenses)
    categ=None
    cond=None
    val=None
    if len(arg)==1:
        categ=arg[0]  
    else:
        if len(arg)==3:
            categ=arg[0]
            cond=arg[1]
            val=arg[2]        
    filter_cat(all_expenses, categ, cond, val)
    print("command succesfull")
    
def undo(all_expenses):
    """ 
    :param all_expenses: list containing dictionarys of the family's expenses
    :param undo_matrix: list of list, saving every iteration of original list
    """

    all_expenses=undo_matrix[-1]
    undo_matrix.pop()
    print("command succesfull")

def read_command():
    """"
    command: list that has the value written by the user
    pos: variable that holds the value of the index where the command ends and the args begin
    cmd: holds the value of the command
    args: holds the value of the arguments
    :return: cmd, arguments
    """

    command = input("command: ")
    pos = command.find(" ")
    
    if pos == -1:
        return command, []

    cmd = command[:pos]

    args = command[(pos + 1):]
    args = args.split()
    for i in range (0, len(args)):
        if args[i].isdigit():
            args[i]=int(args[i])

    return cmd, args

def print_options(commands):
    print(*list(commands.keys()), "exit", sep="\n")

def print_all(all_expenses):
    print(all_expenses)

def run_console():
    commands = {
        "add" : add,
        "insert" : insert,
        "remove" : remove,
        "list" : display,
        "filter" : filtr,
        "print": print_all,
        "undo": undo
        #"exit" : exit
    }
    all_expenses = sample_expanse()
    while True:
        
        print_options(commands)
        cmd,args = read_command()

        if cmd == "exit":
            break
        try:
                if cmd == "remove"  or cmd == "list" or cmd == "filter":
                    args=list(args)
                    commands[cmd](all_expenses, args)
                else:
                    commands[cmd](all_expenses, *args)
        except KeyError as ke:
            print("This option is not yet implemented", ke)

undo_matrix=[]
run_console()


