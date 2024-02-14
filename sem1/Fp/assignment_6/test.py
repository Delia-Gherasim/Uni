from functions import *
from entities import *

def find(sample_expanse, sum, category):
    sample_expanse=list(sample_expanse)
    for i in range(0, len(sample_expanse)):
        if get_category(sample_expanse[i])==category:
            if get_sum(sample_expanse[i])==sum:
                return True
    return False

def find_day(sample_expanse, day, sum, category):
    for i in range(0, len(sample_expanse)):
        if get_category(sample_expanse[i])==category:
            if get_sum(sample_expanse[i])==sum:
                if get_day(sample_expanse[i])==day:
                    return True
    return False

def test_add(sample_expanse):
    sum=10
    category='others'
    add_expenses(sample_expanse, sum, category)
    if find(sample_expanse, sum, category):
        print(" adding an element works :)")
    else:
        print("adding an element doesn't work:(")

def test_insert(sample_expanse):
    day=7
    sum=10
    category='others'
    insert_expenses(sample_expanse,day, sum, category)
    if find_day(sample_expanse, day, sum, category):
        print("inserting an element works :)")
    else:
        print("inserting an element doesn't work:(")

def test_remove(sample_expanse):
    start=3
    end=8
    cat="food"
    remove_expenses(sample_expanse, start, end, None)
    if find_day(sample_expanse, day, sum, cat):
        print("removing an element doesn't work:(")
    else:
        print("removing an element works :)")

def testing(sample_expanse):
    """function calls and runs the tests from test.py
    """
    test_add(sample_expanse)
    test_insert(sample_expanse)
    test_remove(sample_expanse)

testing(sample_expanse)