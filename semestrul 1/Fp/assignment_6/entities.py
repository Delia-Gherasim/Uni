def create_expense(day, sum, cat):
    return {"day":day, "sum":sum, "cat":cat}

def get_day(expenses):
    return expenses["day"]

def set_day(expenses, new_day):
    expenses["day"]=new_day
    return expenses

def get_sum(expenses):
    return expenses["sum"]

def set_sum(expenses, new_sum):
    expenses["sum"] = new_sum
    return expenses

def get_category(expenses):
    return expenses["cat"]

def set_category(expenses, new_cat):
    expenses["cat"]=new_cat
    return expenses
    
def sample_expanse():
        return [{"day":2, "sum":50, "cat": "housekeeping"},
                {"day":4, "sum":26, "cat":"others"},
                {"day":10, "sum":13, "cat":"food"},
                {"day":12, "sum":23, "cat":"internet"},
                {"day":14, "sum":3, "cat":"transport"},
                {"day":15, "sum":55, "cat":"clothing"},
                {"day":18, "sum":100, "cat":"food"},
                {"day":23, "sum":189, "cat":"others"},
                {"day":24, "sum":54, "cat":"internet"},
                {"day":29, "sum":300, "cat":"transport"}]