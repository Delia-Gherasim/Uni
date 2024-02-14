from prettytable import PrettyTable

class repo:
    def matrix():
        m = [[0 for col in range(8)] for row in range(8)]
        return m

    def pretty():
        x = PrettyTable()
        x.field_names = ["x", "1", "2", "3", "4", "5", "6", "7", "8"]
        for i in range(1, 9):
            x.add_row([i, " "," "," "," "," "," "," "," "])

        return x

