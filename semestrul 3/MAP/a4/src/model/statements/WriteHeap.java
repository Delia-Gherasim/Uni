package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.types.RefType;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.RefValue;

public class WriteHeap implements IStatement {
    String var_name;
    IExpression expr;

    public WriteHeap(String name, IExpression exp) {
        this.var_name = name;
        this.expr = exp;
    }

    @Override
    public String toString() {
        return var_name + "->" + expr;
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IDictionary<String, IValue> symbolTable = state.getSymTable();
        IHeap<Integer, IValue> heap = state.getHeap();

        if (!symbolTable.isDefined(var_name)) {
            throw new ExceptionStatement("WriteHeap: Variable Name is not defined");
        } else {
            SymbolTable<String, IValue> symb = (SymbolTable<String, IValue>) state.getSymTable();
            IValue varValue = symbolTable.lookUp(var_name);

            if (!(varValue.getType() instanceof RefType)) {
                throw new ExceptionStatement("WriteHeap: Variable is not of type RefType");
            } else {
                int address = ((RefValue) varValue).getAddress();
                if (!heap.isDefined(address)) {
                    throw new ExceptionStatement("WriteHeap: Invalid heap address");
                } else {
                    IValue exprValue = expr.eval(symb, heap);

                    if (!exprValue.getType().equals(((RefType) varValue.getType()).getInner())) {
                        throw new ExceptionStatement("WriteHeap: Type mismatch between expression and variable location type");
                    } else {
                        heap.update(address, exprValue);
                    }
                }
            }
        }
        return state;
    }
}