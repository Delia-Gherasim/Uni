package model.expresion;

import model.utils.SymbolTable;
import model.value.IValue;

public interface IExpression {

    String toString();

    IValue eval(SymbolTable<String, IValue> symb) throws Exception;
}
