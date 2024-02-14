package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.expresion.LogicExpression;
import model.utils.IStack;
import model.utils.SymbolTable;
import model.value.BoolValue;
import model.value.IValue;

public class IfStatement implements IStatement{
    IExpression expr;
    IStatement thenStatement;
    IStatement elseStatement;
    public IfStatement(IExpression expression, IStatement t, IStatement e){
        expr=expression;
        thenStatement=t;
        elseStatement=e;
    }

    @Override
    public String toString() {
        return "If(" +expr.toString() + ") THEN (" + thenStatement.toString() + " )ELSE(" + elseStatement.toString() + "))";
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IStack<IStatement> stack = state.getExeStack();
        SymbolTable<String, IValue> symb = (SymbolTable<String, IValue>) state.getSymTable();
        IValue conditionValue = expr.eval(symb);
        if (conditionValue instanceof BoolValue) {
            BoolValue boolValue = (BoolValue) conditionValue;
            boolean conditionResult = boolValue.getVal();

            if (conditionResult) {
                stack.push(thenStatement);
            } else {
                if (elseStatement != null) {
                    stack.push(elseStatement);
                }
            }
        } else {
            throw new ExceptionStatement("Condition expression is not of type Bool");
        }

        return state;
    }

}
