package model.expresion;

import model.types.BoolType;
import model.types.IntType;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.IntValue;
import model.value.StringValue;

public class VariableExpression implements IExpression {
    String id;

    public VariableExpression(String variable) {
        id = variable;
    }

    @Override
    public String toString() {
        return id;
    }

    @Override
    public IValue eval(SymbolTable<String, IValue> symb) throws Exception {
        if (symb.isDefined(id))
            return symb.lookUp(id);
        else
            symb.put(id, new IntValue(0));
        return symb.lookUp(id);

    }
}
