package model.statements;

import model.expresion.IExpression;
import model.utils.IListoutput;
import model.utils.SymbolTable;
import model.value.IValue;

public class PrintStatement implements IStatement{
    IExpression expr;
    public PrintStatement(IExpression expression){
        expr=expression;
    }

    @Override
    public String toString() {
        return "Print(" +expr.toString()+")";
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IListoutput<IValue> output = state.getOut();
        IValue value = expr.eval((SymbolTable<String, IValue>) state.getSymTable());
        output.add(value);
        return state;
    }
}
