package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.expresion.ValueExpression;
import model.expresion.VariableExpression;
import model.types.IType;
import model.utils.ExecuteStack;
import model.utils.IDictionarySymbolTable;
import model.utils.IStack;
import model.utils.SymbolTable;
import model.value.IValue;

public class AssignmentStatement implements IStatement{
    String id;
    IExpression exp;

    public AssignmentStatement(String v, IExpression valueExpression) {
        this.id=v;
        this.exp=valueExpression;
    }

    @Override
    public String toString() {/*
        if (exp !=null)
            return id+"="+exp.toString();
        else
            return "nuj";*/
        return id+"="+exp.toString();
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IStack<IStatement> stack = state.getExeStack();
        IDictionarySymbolTable<String, IValue> symbolTable = state.getSymTable();

        if (symbolTable.isDefined(id)) {
            IValue value = exp.eval((SymbolTable<String, IValue>) symbolTable);
            symbolTable.update(id, value);
        } else {
            throw new ExceptionStatement("The used variable " + id + " was not declared before.");
        }

        return state;
    }

}
