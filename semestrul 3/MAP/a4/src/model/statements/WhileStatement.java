package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.utils.IStack;
import model.utils.SymbolTable;
import model.value.BoolValue;
import model.value.IValue;

import java.util.Objects;

public class WhileStatement implements  IStatement{
    IExpression expr;
    IStatement statement;
    public WhileStatement(IExpression e, IStatement s){
        this.expr=e;
        this.statement=s;
    }

    @Override
    public String toString() {
        return "While(" + expr +")"+ statement ;
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        SymbolTable<String, IValue> symTable= (SymbolTable<String, IValue>) state.getSymTable();
        IHeap<Integer, IValue> heap=state.getHeap();
        IStack<IStatement> exeStack= state.getExeStack();

        BoolValue bool= (BoolValue) expr.eval(symTable, heap);
        if (bool.getVal()){
            exeStack.push(this);
            exeStack.push(statement);
        }
        return state;
    }
}
