package model.statements;

import model.exceptions.ExceptionDict;
import model.exceptions.ExceptionStatement;
import model.types.IType;
import model.types.IntType;
import model.utils.IDictionarySymbolTable;
import model.value.IValue;
import model.value.IntValue;

public class VariableDeclarationStatement implements IStatement {
    String name;
    IType type;

    public VariableDeclarationStatement(String name, IType type) {
        this.name = name;
        this.type = type;
    }

    @Override
    public String toString() {
        return type.toString()+" "+name;    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IDictionarySymbolTable<String, IValue> symbolTable = state.getSymTable();
        if (!symbolTable.isDefined(name)) {
            symbolTable.put(name, new IntValue(0));
        }
        else throw new ExceptionDict("symbol is not defined");
        return state;
    }
}

