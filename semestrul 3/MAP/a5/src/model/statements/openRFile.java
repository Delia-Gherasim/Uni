package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.utils.IDictionary;
import model.utils.IStack;
import model.utils.ProgrState;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.StringValue;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;


public class openRFile implements IStatement {
    IExpression expr;

    public openRFile(IExpression expression) {
        expr = expression;
    }

    @Override
    public String toString() {
        return "open file: "+ expr.toString() ;
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IStack<IStatement> stack = state.getExeStack();
        IDictionary<String, IValue> symbolTable = state.getSymTable();
        IDictionary<IValue, BufferedReader> fileTable = state.getFileTable();

        IValue value = expr.eval((SymbolTable<String, IValue>) symbolTable, state.getHeap());
        if (!(value instanceof StringValue stringValue)) {
            throw new ExceptionStatement("Expression does not evaluate to StringType");
        }
        String fileName = stringValue.getValue();
        if (fileTable.isDefined(value)) {
            throw new ExceptionStatement("File '" + fileName + "' is already opened");
        }
        File file = new File(fileName);

        BufferedReader br = new BufferedReader(new FileReader(file.getAbsolutePath()));
        fileTable.put(value, br);
        state.setFileTable((fileTable));

        return null;
    }
}

