#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

class FA {
private:
    std::vector<std::string> states;
    std::vector<std::string> alphabet;
    std::map<std::pair<std::string, std::string>, std::string> transitions;
    std::string initialState;
    std::vector<std::string> finalStates;

    void trim(std::string& str) {
        size_t start = str.find_first_not_of(" \t");
        size_t end = str.find_last_not_of(" \t");
        str = str.substr(start, end - start + 1);
    }

    void loadElements(const std::string path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "can't open file\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            if (line.find("Q =") == 0) {
                parseSet(line, states);
            }
            else if (line.find("E =") == 0) {
                parseSet(line, alphabet);
            }
            else if (line.find("delta") == 0) {
                parseTransition(line);
            }
            else if (line.find("Q0 =") == 0) {
                initialState = line.substr(5);
            }
            else if (line.find("F =") == 0) {
                parseSet(line, finalStates);
            }
        }
    }

    void parseSet(std::string line, std::vector<std::string>& elements) {
        int start = line.find('{');
        int end = line.find('}');
        std::string elementsStr = line.substr(start + 1, end - start - 1);
        std::stringstream ss(elementsStr);
        std::string item;
        while (std::getline(ss, item, ',')) {
            trim(item);
            elements.push_back(item);
        }
    }

    void parseTransition(std::string line) {
        int openParen = line.find('(');
        int comma = line.find(',');
        int closeParen = line.find(')');
        int equalSign = line.find('=');

        std::string fromState = line.substr(openParen + 1, comma - openParen - 1);
        std::string symbol = line.substr(comma + 1, closeParen - comma - 1);
        std::string toState = line.substr(equalSign + 1);

        trim(fromState);
        trim(symbol);
        trim(toState);

        transitions[{fromState, symbol}] = toState;
    }

    bool checkDFA() {
        for (int i = 0; i < states.size(); i++) {
            for (int j = 0; j < alphabet.size(); j++) {
                if (transitions.count({ states[i], alphabet[j] }) != 1) {
                    std::cerr << "Missing transition for (" << states[i] << ", " << alphabet[j] << ")\n";
                    return false;
                }
            }
        }
        return true;
    }

public:

    FA(std::string filePath) {
        loadElements(filePath);
        if (!checkDFA()) {
            std::cerr << "Not valid\n";
        }
    }

    bool isSequenceAccepted(const std::string& input) const {
        std::string currentState = initialState;
        std::cout << "Starting at state: " << currentState << "\n";
        for (const char& ch : input) {
            std::string symbolStr(1, ch);
            std::cout << "Processing symbol: " << symbolStr << "\n";
            if (transitions.find({ currentState, symbolStr }) == transitions.end()) {
                std::cout << "No transition found for (" << currentState << ", " << symbolStr << ")\n";
                return false;
            }
            currentState = transitions.at({ currentState, symbolStr });
            std::cout << "Transitioning to state: " << currentState << "\n";
        }

        for (int i = 0; i < finalStates.size(); i++) {
            if (currentState == finalStates[i]) {
                std::cout << "Final state reached: " << currentState << "\n";
                return true;
            }
        }
        std::cout << "Not in final states.\n";
        return false;
    }

    void printStates() {
        std::cout << "States: ";
        for (int i = 0; i < states.size(); i++) {
            std::cout << states[i] << " ";
        }
        std::cout << "\n";
    }

    void printAlphabet() {
        std::cout << "Alphabet: ";
        for (int i = 0; i < alphabet.size(); i++) {
            std::cout << alphabet[i] << " ";
        }
        std::cout << "\n";
    }

    void printInitialState() {
        std::cout << "Initial State: " << initialState << "\n";
    }

    void printFinalStates() {
        std::cout << "Final States: ";
        for (int i = 0; i < finalStates.size(); i++) {
            std::cout << finalStates[i] << " ";
        }
        std::cout << "\n";
    }

    void printTransitions() {
        std::cout << "Transitions:\n";
        for (int i = 0; i < states.size(); i++) {
            for (int j = 0; j < alphabet.size(); j++) {
                if (transitions.find({ states[i], alphabet[j] }) != transitions.end()) {
                    std::cout << "delta(" << states[i] << "," << alphabet[j] << ") = "
                        << transitions[{states[i], alphabet[j]}] << "\n";
                }
            }
        }
    }

    void displayMenu() {
        int choice;
        do {
            std::cout << "1. states\n";
            std::cout << "2. alphabet\n";
            std::cout << "3. initial state\n";
            std::cout << "4. final states\n";
            std::cout << "5. transitions\n";
            std::cout << "6. check sequence\n";
            std::cout << "0. exit\n";
            std::cout << "-> ";
            std::cin >> choice;

            switch (choice) {
            case 1: printStates(); break;
            case 2: printAlphabet(); break;
            case 3: printInitialState(); break;
            case 4: printFinalStates(); break;
            case 5: printTransitions(); break;
            case 6: {
                std::string sequence;
                std::cout << "Enter sequence: ";
                std::getline(std::cin >> std::ws, sequence); 

                if (sequence.empty() || sequence.find_first_not_of(' ') == std::string::npos) {
                    std::cout << "Not Accepted\n";
                }
                else if (isSequenceAccepted(sequence)) {
                    std::cout << "Accepted\n";
                }
                else {
                    std::cout << "Not accepted\n";
                }
                break;
            }
            case 0: break;
            default: std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    FA fa("FA.txt");
    fa.displayMenu();
    return 0;
}
