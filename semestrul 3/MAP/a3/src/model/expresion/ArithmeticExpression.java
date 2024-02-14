package model.expresion;

import model.exceptions.ExceptionExpr;
import model.types.IntType;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.IntValue;

public class ArithmeticExpression implements IExpression {
    ArithmOp op;
    IExpression e1;
    IExpression e2;

    public ArithmeticExpression(IExpression value1, ArithmOp operator, IExpression value2) {
        e1 = value1;
        op = operator;
        e2 = value2;
    }


    @Override
    public String toString() {
        return " " + e1.toString() + " " + op + " " + e2.toString() + " ";
    }

    @Override
    public IValue eval(SymbolTable<String, IValue> symb) throws Exception {
        IValue v1 = e1.eval(symb);
        IValue v2 = e2.eval(symb);
        int n1, n2;
        if (v1.getType().equals(new IntType())) {
            if (v2.getType().equals(new IntType())) {
                n1 = ((IntValue) v1).getVal();
                n2 = ((IntValue) v2).getVal();
            } else {
                throw new Exception("Second operand is not an int");
            }
        } else {
            throw new ExceptionExpr("First operand is not an int");
        }
        switch (op) {
            case ADD:
                return new IntValue(n1 + n2);
            case MINUS:
                return new IntValue(n1 - n2);
            case DIVIDE:
                if (n2 == 0) {
                    throw new ExceptionExpr("cannot divide by 0");
                }
                return new IntValue(n1 / n2);
            case MULTIPLY:
                return new IntValue(n1 * n2);
            default:
                throw new ExceptionExpr("Operation isn't valid");

        }
    }
}