package model.expresion;

import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.IValue;

public class ValueExpression implements IExpression {
    IValue val;

    public ValueExpression(IValue value) {
        this.val = value;
    }

    @Override
    public String toString() {
        return " " + val + " ";
    }

    @Override
    public IValue eval(SymbolTable<String, IValue> symb, IHeap<Integer, IValue> heap) throws Exception {
        return val;
    }

 }
