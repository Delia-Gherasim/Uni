package model.expresion;


import model.exceptions.ExceptionExpr;
import model.types.BoolType;
import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.BoolValue;
import model.value.IValue;

public class LogicExpression implements IExpression {
    IExpression e1, e2;
    LogicOperator operator;

    public LogicExpression(IExpression operand1, LogicOperator operator, IExpression operand2) {
        e1 = operand1;
        e2 = operand2;

    }

    @Override
    public String toString() {
        return " " + e1 + " " + operator + " " + e2 + " ";
    }

    @Override
    public IValue eval(SymbolTable<String, IValue> symb, IHeap<Integer, IValue> heap) throws Exception {
        IValue v1;
        IValue v2;
        v1 = e1.eval(symb, heap);
        if (v1.getType().equals(new BoolType())) {
            v2 = e2.eval(symb, heap);
            if (v2.getType().equals(new BoolType())) {
                BoolValue b1 = (BoolValue) v1;
                BoolValue b2 = (BoolValue) v2;
                boolean n1 = b1.getVal();
                boolean n2 = b2.getVal();
                switch (operator) {
                    case OR:
                        boolean b = n1 || n2;
                        return new BoolValue(b);
                    case AND:
                        return new BoolValue(n1 & n2);
                    default:
                        throw new ExceptionExpr("operation isn't valid");
                }

            } else
                throw new ExceptionExpr("second operand is not boolean");
        } else throw new ExceptionExpr("first operand is not bool");

    }


}


