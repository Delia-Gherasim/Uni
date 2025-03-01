#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

typedef std::string Key; 
typedef int Value;

const int NULL_Value = -1;
const int DELETED = -2;

struct Node {
    Key key;                
    std::vector<Value> values;
    std::string type;

    Node() : key(""), type("") {} 
};

class SymbolTable {
private:
    int capacity;
    int length;
    Node* elements;
    int nextKey;            

    int hash(int key) const {
        return abs(key) % capacity;
    }

    int quadratic_probe(int hash_val, int i) const {
        return (hash_val + i * i) % capacity;
    }

    void resize() {
        int old_capacity = capacity;
        Node* old_elements = elements;
        capacity *= 2;
        length = 0;
        elements = new Node[capacity]();

        for (int i = 0; i < old_capacity; i++) {
            if (old_elements[i].key != "" && old_elements[i].key != "DELETED") {
                for (const auto& value : old_elements[i].values) {
                    add(old_elements[i].key, value, old_elements[i].type);
                }
            }
        }
        delete[] old_elements;
    }

public:
    SymbolTable() : capacity(1000), length(0), elements(new Node[capacity]()), nextKey(0) {}

    ~SymbolTable() {
        delete[] elements;
    }

    int add(Key c, Value v, const std::string& type) {
        int key = nextKey++; 

        if (length >= capacity) {
            resize();
        }

        int index = hash(key); 
        int i = 0;

        while (elements[index].key != "" && elements[index].key != "DELETED") {
            if (elements[index].key == c && elements[index].type == type) {
                elements[index].values.push_back(v);
                std::sort(elements[index].values.begin(), elements[index].values.end());
                return key; 
            }
            index = quadratic_probe(hash(key), ++i);
        }

        elements[index].key = c; 
        elements[index].values = { v };
        elements[index].type = type;
        length++;

        return key; 
    }

    std::vector<Value> search(Key c, const std::string& type) const {
        std::vector<Value> values;
        int i = 0;
        int index = hash(nextKey); 

        while (i < capacity && elements[index].key != "" && elements[index].key != "DELETED") {
            if (elements[index].key == c && elements[index].type == type) {
                return elements[index].values;
            }
            index = quadratic_probe(hash(nextKey), ++i);
        }
        return values;
    }

    bool remove(Key c, Value v) {
        int index = hash(nextKey); 
        int i = 0;

        while (i < capacity && elements[index].key != "" && elements[index].key != "DELETED") {
            if (elements[index].key == c) {
                auto& values = elements[index].values;
                auto it = std::find(values.begin(), values.end(), v);
                if (it != values.end()) {
                    values.erase(it);
                    if (values.empty()) {
                        elements[index].key = "DELETED"; 
                    }
                    length--;
                    return true;
                }
            }
            index = quadratic_probe(hash(nextKey), ++i);
        }
        return false;
    }

    void print() const {
        for (int i = 0; i < capacity; i++) {
            if (elements[i].key != "" && elements[i].key != "DELETED") {
                std::cout << "Key: " << elements[i].key << ", Values: ";
                for (const auto& value : elements[i].values) {
                    std::cout << value << " ";
                }
                std::cout << ", Type: " << elements[i].type << std::endl;
            }
        }
    }
};
