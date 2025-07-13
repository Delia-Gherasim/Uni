from entities import *

def add_expenses(all_expenses, sum, category):
    d=get_day(all_expenses[len(all_expenses)-1])
    all_expenses.append(create_expense(d, sum, category))
    return all_expenses

def insert_expenses(all_expenses, day, sum, category):
    all_expenses.append(create_expense(day, sum, category))
    return all_expenses

def remove_expenses(all_expenses, start, end, cat):
    if cat is not None:
        i=0
        while (i<len(all_expenses)):
            if get_category(all_expenses[i])==cat:
                all_expenses.pop(i)
                i=i-1
            i=i+1
    else:
        if end is not None:
            i=0
            while (i<len(all_expenses)):
                if get_day(all_expenses[i])>=start and get_day(all_expenses[i])<=end:
                    all_expenses.pop(i)
                    i=i-1
                i=i+1
        else:
            i=0
            while (i<len(all_expenses)):
                if get_day(all_expenses[i])==start:
                    all_expenses.pop(i)
                    i=i-1
                i=i+1
            
    return all_expenses

def is_integer_num(n):
    if isinstance(n, int):
        return True
    if isinstance(n, float):
        return n.is_integer()
    return False

def filter_cat(all_expenses, categ, cond, val):
    new=[]
    if cond is not None:
        for i in range(0, len(all_expenses)):
            if get_category(all_expenses[i])==categ:
                if cond=='=':
                    if get_sum(all_expenses[i])==val:
                        new.append(all_expenses[i])
                if cond=='<':
                    if get_sum(all_expenses[i])<val:
                        new.append(all_expenses[i])
                if cond=='>':
                    if get_sum(all_expenses[i])>val:
                        new.append(all_expenses[i])
    else:
        if categ is not None:
            for i in range(0, len(all_expenses)):
                if get_category(all_expenses[i])==categ:
                    new.append(all_expenses[i])
    all_expenses=[]

    for i in range(0, len(new)):
        all_expenses.append(new[i])
    
    print(all_expenses)
    return all_expenses
