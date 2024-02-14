package model.statements;

public class NoOperationStatement implements IStatement{
    public NoOperationStatement(){

    }

    @Override
    public ProgrState execute(ProgrState state) {
        return state;
    }

    @Override
    public String toString() {
        return "NoOperationStatement{}";
    }
}
