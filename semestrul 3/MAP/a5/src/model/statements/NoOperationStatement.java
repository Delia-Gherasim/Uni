package model.statements;

import model.utils.ProgrState;

public class NoOperationStatement implements IStatement {
    public NoOperationStatement() {

    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        return null;
    }

    @Override
    public String toString() {
        return "NoOperationStatement{}";
    }
}
