package model.statements;

import model.exceptions.ExceptionStatement;
import model.types.BoolType;
import model.types.IType;
import model.utils.*;
import model.value.IValue;

import java.io.BufferedReader;
import java.util.Map;

public class ForkStatement implements IStatement{
    @Override
    public String toString() {
        return "Fork( "+ stmt +" )";
    }

    private IStatement stmt;
    public ForkStatement(IStatement s) {
        stmt = s;
    }
    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        SymbolTable<String, IValue> parentSymTable = (SymbolTable<String, IValue>) state.getSymTable();
        SymbolTable<String, IValue> childSymTable = new SymbolTable<>();
        for (Map.Entry<String, IValue> entry : parentSymTable.getContent().entrySet()) {
            childSymTable.put(entry.getKey(), entry.getValue());
        }

        IHeap<Integer, IValue> heap = state.getHeap();
        IListoutput<IValue> output = state.getOut();
        IDictionary<IValue, BufferedReader> fileTable = state.getFileTable();
        int newId = ProgrState.getId()+1;
        ExecuteStack exeStack = new ExecuteStack<>();
        //exeStack.push(stmt);
        ProgrState childState = new ProgrState(exeStack, childSymTable, output, stmt, fileTable, heap, newId);

        return childState;
    }

    @Override
    public IDictionary<String, IType> typecheck(IDictionary<String, IType> typeEnv) throws Exception {
        stmt.typecheck(clone(typeEnv));
        return typeEnv;
    }
    private IDictionary<String, IType> clone(IDictionary<String, IType> original) {
        IDictionary<String, IType> cloned = new SymbolTable<>();
        for (Map.Entry<String, IType> entry : original.entrySet()) {
            cloned.put(entry.getKey(), entry.getValue());
        }
        return cloned;
    }
}
