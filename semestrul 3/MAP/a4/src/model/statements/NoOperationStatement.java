package model.statements;

public class NoOperationStatement implements IStatement {
    NoOperationStatement() {

    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        return state;
    }

    @Override
    public String toString() {
        return "NoOperationStatement{}";
    }
}
