#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Grammar {
private:
    map<string, vector<vector<string>>> productions;
    set<string> nonTerminals;
    set<string> terminals;
    string startSymbol;

public:
    Grammar(const string& startSymbol = "") : startSymbol(startSymbol) {}

    bool readGrammarFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return false;
        }

        string line;
        while (getline(infile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            }

            stringstream ss(line);
            string leftSide;
            string rightSide;

            getline(ss, leftSide, '-');
            ss.ignore(2);

            getline(ss, rightSide);

            vector<string> production;
            stringstream rhsStream(rightSide);
            string symbol;
            while (rhsStream >> symbol) {
                production.push_back(symbol);
                if (isNonTerminal(symbol)) {
                    nonTerminals.insert(symbol);
                }
                else {
                    terminals.insert(symbol);
                }
            }

            productions[leftSide].push_back(production);
            nonTerminals.insert(leftSide);
            if (startSymbol.empty()) {
                startSymbol = leftSide;
            }
        }

        infile.close();
        return true;
    }

    void printNonTerminals() const {
        cout << "Non-Terminals: ";
        for (const auto& nt : nonTerminals) {
            cout << nt << " ";
        }
        cout << endl;
    }

    void printTerminals() const {
        cout << "Terminals: ";
        for (const auto& t : terminals) {
            cout << t << " ";
        }
        cout << endl;
    }

    void printProductions() const {
        cout << "Productions:" << endl;
        for (const auto& pair : productions) {
            const string& nonTerminal = pair.first;
            const vector<vector<string>>& prodRules = pair.second;
            for (const vector<string>& rule : prodRules) {
                cout << nonTerminal << " -> ";
                for (const string& symbol : rule) {
                    cout << symbol << " ";
                }
                cout << endl;
            }
        }
    }

    void printProductionsForNonTerminal(const string& nonTerminal) const {
        if (productions.find(nonTerminal) == productions.end()) {
            cout << "No productions for non-terminal: " << nonTerminal << endl;
            return;
        }

        cout << "Productions for " << nonTerminal << ":" << endl;
        for (const vector<string>& rule : productions.at(nonTerminal)) {
            cout << nonTerminal << " -> ";
            for (const string& symbol : rule) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }

    bool isContextFree() const {
        for (const auto& pair : productions) {
            const string& nonTerminal = pair.first;
            const vector<vector<string>>& prodRules = pair.second;

            for (const vector<string>& rule : prodRules) {
                if (rule.empty() || !isNonTerminal(nonTerminal)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isTerminal(const string& symbol) const {
        return terminals.find(symbol) != terminals.end();
    }

    bool isNonTerminal(const string& symbol) const {
        return nonTerminals.find(symbol) != nonTerminals.end();
    }
};

int main() {
    Grammar grammar;

    string filename = "grammar.txt";
    if (!grammar.readGrammarFromFile(filename)) {
        return 1;
    }

    grammar.printNonTerminals();
    grammar.printTerminals();
    grammar.printProductions();

    string nonTerminal = "S";
    grammar.printProductionsForNonTerminal(nonTerminal);

    if (grammar.isContextFree()) {
        cout << "The grammar is context-free!" << endl;
    }
    else {
        cout << "The grammar is not context-free." << endl;
    }

    return 0;
}