import re


class Grammar:
    def __init__(self, nonterminal_symbols, terminal_symbols, productions, start_terminal):
        self.nonterminal_symbols = nonterminal_symbols
        self.terminal_symbols = terminal_symbols
        self.productions = productions
        self.start_terminal = start_terminal

    @staticmethod
    def read_from_file(filename):
        try:
            with open(filename, "r") as infile:
                grammar_def = infile.readline().strip()
                nt_start = grammar_def.find("{")
                nt_end = grammar_def.find("}", nt_start)
                nt_string = grammar_def[nt_start + 1:nt_end]
                t_start = grammar_def.find("{", nt_end)
                t_end = grammar_def.find("}", t_start)
                t_string = grammar_def[t_start + 1:t_end]
                start_symbol_start = grammar_def.rfind(",") + 1
                start_terminal = grammar_def[start_symbol_start:].strip().replace(")", "")

                print(f"Start symbol: {start_terminal}")

                nonterminal_symbols = Grammar.parse_symbols(nt_string)
                terminal_symbols = Grammar.parse_symbols(t_string)

                print(f"Nonterminals after parsing: {nonterminal_symbols}")
                print(f"Terminals after parsing: {terminal_symbols}")

                infile.readline()
                productions = []
                for line in infile:
                    line = line.strip()
                    if line:
                        productions.extend(Grammar.parse_production(line))
                return Grammar(nonterminal_symbols, terminal_symbols, productions, start_terminal)
        except FileNotFoundError:
            print(f"Error: Could not open file {filename}")
            return None

    @staticmethod
    def parse_symbols(input_str):
        symbols = re.split(r',\s*', input_str)
        symbol_set = set()
        for symbol in symbols:
            symbol_set.add(symbol.strip())
        return symbol_set

    @staticmethod
    def parse_production(line):
        left_side, right_side = line.split('->')
        left_side = left_side.strip()
        right_side = right_side.strip()

        productions = []
        for prod in right_side.split('|'):
            production = [symbol.strip() for symbol in prod.split()]
            productions.append((left_side, production))

        return productions

    def find_production(self, symbol):
        result = []
        for production in self.productions:
            if production[0] == symbol:
                result.append(production[1])
        return result

    def menu(self):
        print("0 - Exit")
        print("1 - Productions")
        print("2 - Nonterminal symbols")
        print("3 - Terminal symbols")
        print("4 - Productions for a given nonterminal")

    def printMenu(self):
        while True:
            self.menu()
            choice = int(input("> "))
            if choice == 0:
                return
            elif choice == 1:
                print(self.productions)
            elif choice == 2:
                print(self.nonterminal_symbols)
            elif choice == 3:
                print(self.terminal_symbols)
            elif choice == 4:
                nt = input("Give nonterminal: ")
                print(self.find_production(nt))
