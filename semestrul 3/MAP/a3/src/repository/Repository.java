package repository;

import model.exceptions.ExceptionList;
import model.statements.IStatement;
import model.statements.ProgrState;
import model.utils.ExecuteStack;
import model.utils.IDictionary;
import model.utils.IListoutput;
import model.utils.IStack;
import model.value.IValue;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Repository implements IRepository {
    List<ProgrState> programStateList;
    String logFilePath;

    public Repository() {
        programStateList = new ArrayList<>();
    }

    public Repository(String logFile) {
        this.programStateList = new ArrayList<>();
        this.logFilePath = logFile;
    }

    @Override
    public ProgrState getCurrentProgramState() throws Exception {
        if (this.programStateList.isEmpty()) {
            throw new ExceptionList("the program state list is empty");
        }
        return programStateList.get(0);
    }

    @Override
    public void add(ProgrState programState) {
        programStateList.add(programState);
    }

    @Override
    public void logProgrState() throws Exception {
        Path path = Paths.get(logFilePath);
        PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
        logFile.println("ExeStack: ");
        IStack<IStatement> stack = getCurrentProgramState().getExeStack();
        IStack<IStatement> tempStack = new ExecuteStack<IStatement>() {};
        while (!stack.isEmpty()) {
            tempStack.push(stack.pop());
        }
        while (!tempStack.isEmpty()) {
            IStatement statement = tempStack.pop();
            logFile.println(statement.toString());
            stack.push(statement);
        }

        logFile.println("SymTable: ");
        IDictionary<String, IValue> simbTable = getCurrentProgramState().getSymTable();
        if (!simbTable.isEmpty()) {
            for (Map.Entry<String, IValue> entry : simbTable.entrySet()) {
                logFile.println(entry.getKey() + ": " + entry.getValue());
            }
        }

        logFile.println("FileTable: ");
        IDictionary<IValue, BufferedReader> fileTable = getCurrentProgramState().getFileTable();
        if (!fileTable.isEmpty()) {
            for (Map.Entry<IValue, BufferedReader> entry : fileTable.entrySet()) {
                logFile.println(entry.getKey());
            }
        }

        IListoutput<IValue> list = getCurrentProgramState().getOut();
        if (!list.isEmpty()) {
            logFile.println(list.toString());
        }
        logFile.println();
        logFile.flush();
        logFile.close();
    }
    @Override
    public String toString() {
        return "programStateList=" + programStateList;
    }

}

