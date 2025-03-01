#include <vector>
#include <string>
#include <iostream>

class Pif {
private:
    std::vector<std::pair<std::string, int>> data;

public:
    void add(const std::string& type, int pos) {
        data.emplace_back(type, pos);
    }

    void print() const {
        for (const auto& entry : data) {
            std::cout << "Token: " << entry.first << ", Position: " << entry.second << std::endl;
        }
    }
};