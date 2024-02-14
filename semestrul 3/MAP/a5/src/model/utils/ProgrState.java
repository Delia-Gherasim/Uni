package model.utils;

import model.exceptions.ExceptionStack;
import model.statements.IStatement;
import model.utils.*;
import model.value.IValue;

import java.io.BufferedReader;
import java.util.Map;

public class ProgrState {
    IStack<IStatement> exeStack;
    IDictionary<String, IValue> symTable;
    IListoutput<IValue> out;
    IDictionary<IValue, BufferedReader> fileTable;
    IHeap<Integer, IValue> heap;
    IStatement originalProgram;
    static int id;

    public static int getId() {
        return id;
    }

    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog, IDictionary<IValue, BufferedReader> fileT, IHeap<Integer, IValue> heap, int nextId) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        this.fileTable = fileT;
        this.heap=heap;
        id=nextId;
        stack.push(prog);
    }

    public boolean isNotCompleted(){
        if (!this.exeStack.isEmpty())
            return true;
        return false;
    }

    public ProgrState oneStep() throws Exception {
         if (exeStack.isEmpty())
            throw new ExceptionStack("programstate stack is empty");
        IStatement crtStmt = exeStack.pop();
        return crtStmt.execute(this);
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

    public IHeap<Integer, IValue> getHeap(){
        return heap;
    }
    public void setHeap(IHeap<Integer, IValue> newHeap){
        this.heap=newHeap;
    }

    @Override
    public String toString() {
        return "Program State: "+ id+"\n" +
                "Execution Stack: " + exeStack + "\n" +
                "Symbol Table: " + symTable + "\n" +
                "Output: " + out+"\n"+
                "File Table: "+fileTable+"\n"+
                "Heap: "+heap+"\n";
    }

}
