class IdentifierTable : public SymbolTable {
public:
    void add_identifier(Key c, Value v) {
        add(c, v, "identifier");
    }

    std::vector<Value> search_identifier(Key c) const {
        return search(c, "identifier");
    }

    bool remove_identifier(Key c, Value v) {
        return remove(c, v);
    }
};

class ConstantTable : public SymbolTable {
public:
    void add_constant(Key c, Value v) {
        add(c, v, "constant");
    }

    std::vector<Value> search_constant(Key c) const {
        return search(c, "constant");
    }

    bool remove_constant(Key c, Value v) {
        return remove(c, v);
    }
};