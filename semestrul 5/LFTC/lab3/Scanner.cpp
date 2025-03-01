#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <sstream>

#include "Pif.cpp"
#include "SymbolTable.cpp"

class Scanner {
private:
    Pif pif;
    SymbolTable constants;
    SymbolTable identifiers;
    std::vector<std::string> keywords;
    std::vector<std::string> operators;
    std::vector<std::string> separators;
    std::vector<std::string> program;
   
    bool hasSyntaxError = false;

    void loadTokens(const std::string& tokensPath) {
        std::ifstream file(tokensPath);
        std::string line;
        std::string section;

        while (std::getline(file, line)) {
            if (line.empty()) continue;
            if (line == "Keywords") {
                section = "keywords";
                continue;
            }
            else if (line == "Operators") {
                section = "operators";
                continue;
            }
            else if (line == "Separators") {
                section = "separators";
                continue;
            }

            if (section == "keywords") {
                keywords.push_back(line);
            }
            else if (section == "operators") {
                operators.push_back(line); 
            }
            else if (section == "separators") {
                separators.push_back(line); 
            }
        }
    }

    std::vector<std::string> tokenizeLine(const std::string& line) {
        std::string modifiedLine = line;

        for (const auto& sep : separators) {
            size_t pos = 0;
            while ((pos = modifiedLine.find(sep, pos)) != std::string::npos) {
                modifiedLine.insert(pos, " ");
                pos += sep.size() + 1;
                modifiedLine.insert(pos, " ");
            }
        }

        std::istringstream stream(modifiedLine);
        std::vector<std::string> tokens;
        std::string token;
        while (stream >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void processToken(const std::string& token, int lineNum, int charPos) {
        if (std::regex_match(token, std::regex("^(0|[-]?[1-9][0-9]*)$"))) {
            pif.add("constant", constants.add(token, lineNum, "constant"));
        }
        else if (std::find(keywords.begin(), keywords.end(), token) != keywords.end()) {
            pif.add(token, -1);
        }
        else if (std::find(operators.begin(), operators.end(), token) != operators.end()) {
            pif.add(token, -1);
        }
        else if (std::find(separators.begin(), separators.end(), token) != separators.end()) {
        }
        else if (std::regex_match(token, std::regex("^[a-zA-Z]([a-zA-Z]|[0-9])*$"))) {
            pif.add("id", identifiers.add(token, lineNum, "id"));
        }
        else {
            std::cerr << "Syntax error: unrecognized token '" << token << "' at line " << lineNum + 1 << ", char " << charPos << std::endl;
            hasSyntaxError = true;
        }
    }

public:
    Scanner(const std::string& programPath, const std::string& tokensPath)
        : program(readFileLines(programPath)) {
        loadTokens(tokensPath);
    }

    std::vector<std::string> readFileLines(const std::string& filePath) {
        std::ifstream file(filePath);
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        return lines;
    }

    void scan() {
        int lineNum = 0;
        for (const auto& line : program) {
            auto lineTokens = tokenizeLine(line);
            int charPos = 0;
            for (const auto& token : lineTokens) {
                charPos = line.find(token, charPos);
                processToken(token, lineNum, charPos);
                charPos += token.length();
            }
            lineNum++;
        }
    }

    void printResults() const {
        std::cout << "PIF:" << std::endl;
        pif.print();
        printf("\n");
        printf("\n");

        std::cout << "Identifiers:" << std::endl;
        identifiers.print();
        printf("\n"); printf("\n");

        std::cout << "Constants:" << std::endl;
        constants.print();
    }

    void printSyntaxResult() const {
        if (hasSyntaxError) {
            std::cout << "Incorrect syntax." << std::endl;
        }
        else {
            std::cout << "Correct syntax." << std::endl;
        }
    }
};

int main() {
    Scanner scanner("p1err.txt", "token.in");
    scanner.scan();
    scanner.printResults();
    scanner.printSyntaxResult();
    return 0;
}
