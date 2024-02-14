package model.statements;

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
    Map<Integer, IValue> garbage;


    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        stack.push(prog);
    }

    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog, IDictionary<IValue, BufferedReader> fileT) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        this.fileTable = fileT;
        stack.push(prog);
        //this.fileTable = fileT;
    }
    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog, IDictionary<IValue, BufferedReader> fileT, IHeap<Integer, IValue> heap) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        //originalProgram=deepCopy(prog);
        this.fileTable = fileT;
        this.heap=heap;
        stack.push(prog);
        //this.fileTable = fileT;
        //this.heap=heap;
    }/*
    public ProgrState(IStack<IStatement> stack, IDictionary<String, IValue> symbolTable, IListoutput<IValue> out, IStatement prog, IDictionary<IValue, BufferedReader> fileT, IHeap<Integer, IValue> heap, Garbage g) {
        this.exeStack = stack;
        this.symTable = symbolTable;
        this.out = out;
        //originalProgram=deepCopy(prog);
        this.fileTable = fileT;
        this.heap=heap;
        this.garbage=g;
        stack.push(prog);
        //this.fileTable = fileT;
        //this.heap=heap;
    }*/
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

   // public Map<Integer, IValue> getContent(return garbage;)

    //public void setContent(Map<Integer, IValue> g){this.garbage=g;    }

    @Override
    public String toString() {
        return "Program State: \n" +
                "Execution Stack: " + exeStack + "\n" +
                "Symbol Table: " + symTable + "\n" +
                "Output: " + out+"\n"+
                "File Table: "+fileTable+"\n"+
                "Heap: "+heap+"\n";
    }

}
