from Grammar import Grammar


class Parser:
    def __init__(self, option):
        self.option = option
        if option ==1 :
            self.grammar = Grammar.read_from_file("C:\\Facultation\\sem5\\lftc\\lab_python\\a\\g1.txt")
        else :
            self.grammar = Grammar.read_from_file("C:\\Facultation\\sem5\\lftc\\lab_python\\a\\g2.txt")
        self.workingStack = []
        self.inputStack = []
        self.output = []

    def closure(self, productions):
        if not productions:
            return None
        closure = productions
        done = False
        while not done:
            done = True
            for dotted_prod in closure:
                dotPos = dotted_prod[1].index('.')
                afterDot = dotted_prod[1][dotPos + 1:]
                if len(afterDot) == 0:
                    continue
                afterDotLetters = afterDot[0]
                if self.option == 1:
                    for symbol in afterDotLetters:
                        if symbol in self.grammar.terminal_symbols:
                            continue
                        
                        for prod in self.grammar.find_production(symbol):
                            print(prod)
                            dotted_prod = (symbol, ['.'] + prod)
                            if dotted_prod not in closure:
                                closure += [dotted_prod]
                                done = False
                else:
                    if afterDotLetters in self.grammar.terminal_symbols:
                        continue
                    
                    for prod in self.grammar.find_production(afterDotLetters):
                        dotted_prod = (afterDotLetters, ['.'] + prod)
                        if dotted_prod not in closure:
                            closure += [dotted_prod]
                            done = False
               

        return closure

    def goTo(self, state, symbol):
        C = []
        for production in state:
            print(production)
            if '.' not in production[1]: 
                continue
            dotPos = production[1].index('.')
            beforeDot = production[1][:dotPos]
            afterDot = production[1][dotPos + 1:]
            if len(afterDot) == 0:
                continue

            firstElementAfterDot, restAfterDot = afterDot[0], afterDot[1:]
            if symbol in firstElementAfterDot:
                    res = beforeDot + [firstElementAfterDot] + ['.'] + restAfterDot
                    result_prod = (production[0], res)
                    C += [result_prod]
        return self.closure(C)

    def canonicalCollection(self):
        C = [self.closure([('S1', ['.', self.grammar.start_terminal])])]
        finished = False
        while not finished:
            finished = True
            for state in C:       
                all_symbols = self.grammar.nonterminal_symbols.union(self.grammar.terminal_symbols)
                for symbol in all_symbols:
                    next_state = self.goTo(state, symbol)
                    if next_state and next_state not in C:
                        C += [next_state]
                        finished = False
        return C

    def generate_table(self):
        states = self.canonicalCollection()
        table = [{} for _ in range(len(states))]
        for index in range(len(states)):
            state = states[index]
            first_rule_cnt = 0
            second_rule_cnt = 0
            third_rule_cnt = 0
            partAfterDot = []
            for prod in state:
                dot_index = prod[1].index('.')
                partBeforeDot = prod[1][:dot_index]
                partAfterDot = prod[1][dot_index + 1:]
                if len(partAfterDot) != 0:
                    first_rule_cnt += 1
                else:
                    if prod[0] != 'S1':
                        second_rule_cnt += 1
                        production_index = self.grammar.productions.index((prod[0], partBeforeDot))
                    elif partBeforeDot == [self.grammar.start_terminal]:
                        third_rule_cnt += 1
            if first_rule_cnt == len(state):
                table[index]['action'] = 'shift'
            elif second_rule_cnt == len(state):
                table[index]['action'] = 'reduce ' + str(production_index)
            elif third_rule_cnt == len(state):
                table[index]['action'] = 'acc'
            else:
                conflict_msg = 'Conflict! State I' + str(index) + ': ' + str(state) + '\nSymbol: ' + partAfterDot[0]
                raise (Exception(conflict_msg))
            all_symbols = self.grammar.nonterminal_symbols.union(self.grammar.terminal_symbols)
            for symbol in all_symbols:
                next_state = self.goTo(state, symbol)
                if next_state in states:
                    table[index][symbol] = states.index(next_state)
        return table
   
    def print_table(self, table):
        for idx, row in enumerate(table):
            print(f"State {idx}: {row}")

        print()

    def parse(self, input_string):
        table = self.generate_table()
        self.print_table(table)
        self.workingStack = ['0']
        self.inputStack = [char for char in input_string]
        self.output = []
        try:
            while len(self.workingStack) != 0:
                state = int(self.workingStack[-1])
                if len(self.inputStack) > 0:
                    char = self.inputStack.pop(0)
                else:
                    char = None
                if table[state]['action'] == 'shift':
                    if char not in table[state]:
                        raise (Exception("Syntax error! \nCannot parse shift. Character: " + char))
                    self.workingStack.append(char)
                    self.workingStack.append(table[state][char])
                elif table[state]['action'] == 'acc':
                    if len(self.inputStack) != 0:
                        raise (Exception("Syntax error! \nCannot parse accept. Character: " + char))
                    self.workingStack.clear()
                else:
                    reduce_state = int(table[state]['action'].split(' ')[1])
                    reduce_production = self.grammar.productions[reduce_state]
                    to_remove_from_working_stack = [symbol for symbol in reduce_production[1]]
                    while len(to_remove_from_working_stack) > 0 and len(self.workingStack) > 0:
                        if self.workingStack[-1] == to_remove_from_working_stack[-1]:
                            to_remove_from_working_stack.pop()
                        self.workingStack.pop()
                    if len(to_remove_from_working_stack) != 0:
                        raise (Exception('Syntax error!' + '! \n Cannot parse reduce. Character: '+ char))
                   
                    self.inputStack.insert(0, char)
                    self.inputStack.insert(0, reduce_production[0])
                    self.output.insert(0, reduce_state)

        except Exception as ex:
            raise Exception(ex)

        print()

        return self.output





