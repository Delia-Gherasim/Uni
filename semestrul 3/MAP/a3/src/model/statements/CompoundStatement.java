package model.statements;

import model.utils.IStack;

public class CompoundStatement implements IStatement {
    IStatement statement1;
    IStatement statement2;

    public CompoundStatement(IStatement stm1, IStatement stm2) {
        statement1 = stm1;
        statement2 = stm2;
    }

    @Override
    public String toString() {
        return "( " + statement1.toString() + " , " + statement2.toString() + " )";
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IStack<IStatement> stack = state.getExeStack();
        stack.push(statement2);
        stack.push(statement1);
        return state;
    }
}
