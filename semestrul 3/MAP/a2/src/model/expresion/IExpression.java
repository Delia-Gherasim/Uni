package model.expresion;

import model.exceptions.ExceptionExpr;
import model.utils.SymbolTable;

import model.value.IValue;

public interface IExpression {

    public String toString();
    IValue eval(SymbolTable<String, IValue> symb) throws Exception;
}
