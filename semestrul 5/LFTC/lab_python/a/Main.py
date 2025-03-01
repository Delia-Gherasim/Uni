from Parser import Parser
from ParserOutput import ParserOutput


class Main:
    def main(self):
        print("1. run for g1")
        print("2. run for g2")
        choice = int(input("> "))
        if choice == 1:
            parser = Parser(1)
            output_parser = parser.parse("ab")
        elif choice == 2:
            parser = Parser(2)
            output_parser = parser.parse("a = number")
        
        parserOutput = ParserOutput(parser)
        print("Derivation strings: " + str(parserOutput.DS(output_parser)))
        outputfile = open("out.txt", "w")
        parserOutput.writeOutput(output_parser, outputfile)
if __name__ == "__main__":
    main = Main()
    try:
        main.main()
    except Exception as e:
        print(e)