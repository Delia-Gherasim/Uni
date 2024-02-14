package model.statements;

import model.utils.IDictionary;
import model.utils.IListoutput;
import model.utils.IStack;
import model.value.IValue;

import java.io.BufferedReader;

public class ProgrState {
    IStack<IStatement> exeStack;
    IDictionary<String, IValue> symTable;
    IListoutput<IValue> out;
    IDictionary<IValue, BufferedReader> fileTable;
    IStatement originalProgram;

    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        //originalProgram=deepCopy(prog);
        stack.push(prog);
    }

    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog, IDictionary<IValue, BufferedReader> fileT) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        //originalProgram=deepCopy(prog);
        stack.push(prog);
        this.fileTable = fileT;
    }

    public IStack<IStatement> getExeStack() {
        return exeStack;
    }

    public void setExeStack(IStack<IStatement> stack) {
        this.exeStack = stack;
    }

    public IDictionary<String, IValue> getSymTable() {
        return symTable;
    }

    public void setSymTable(IDictionary<String, IValue> symtable) {
        this.symTable = symtable;
    }

    public IListoutput<IValue> getOut() {
        return out;
    }

    public void setOut(IListoutput<IValue> out1) {
        this.out = out1;
    }

    public IDictionary<IValue, BufferedReader> getFileTable() {
        return fileTable;
    }

    public void setFileTable(IDictionary<IValue, BufferedReader> table) {
        this.fileTable = table;
    }

    @Override
    public String toString() {
        return "Program State: \n" +
                "Execution Stack: " + exeStack + "\n" +
                "Symbol Table: " + symTable + "\n" +
                "Output: " + out+"\n"+
                "File Table: "+fileTable+"\n";
    }

}
