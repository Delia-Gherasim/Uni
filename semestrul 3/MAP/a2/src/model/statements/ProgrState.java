package model.statements;

import com.sun.jdi.Value;
import model.utils.IDictionarySymbolTable;
import model.utils.IListoutput;
import model.utils.IStack;
import model.value.IValue;

public class ProgrState {
    IStack<IStatement> exeStack;
    IDictionarySymbolTable<String, IValue> symTable;
    IListoutput<IValue> out;
    IStatement originalProgram;
    public ProgrState(IStack<IStatement> stack, IDictionarySymbolTable<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog){
        this.exeStack=stack;
        this.symTable=symbolTable;
        this.out=out;
        //originalProgram=deepCopy(prog);
        stack.push(prog);
    }
    public IStack<IStatement> getExeStack(){
        return exeStack;
    }

    public void setExeStack(IStack<IStatement> stack){
        this.exeStack=stack;
    }
    public IDictionarySymbolTable<String, IValue> getSymTable(){
        return symTable;
    }
    public void setSymTable(IDictionarySymbolTable<String, IValue> symtable){
        this.symTable=symtable;
    }
    public IListoutput<IValue> getOut(){
        return out;
    }

    public void setOut(IListoutput<IValue> out1){
        this.out=out1;
    }

    @Override
    public String toString() {
        return "Program State: \n" +
                "Execution Stack: " + exeStack + "\n" +
                "Symbol Table: " + symTable + "\n" +
                "Output: " + out;
    }

}
