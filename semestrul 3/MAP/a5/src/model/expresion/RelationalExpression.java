package model.expresion;

import model.exceptions.ExceptionExpr;
import model.types.IntType;
import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.BoolValue;
import model.value.IValue;
import model.value.IntValue;

public class RelationalExpression implements IExpression{
    RelationEnum relation;
    IExpression e1;
    IExpression e2;
    public RelationalExpression(IExpression expr1, RelationEnum rel, IExpression expr2){
        e1=expr1;
        e2=expr2;
        relation=rel;
    }

    @Override
    public String toString() {
        return e1.toString()+" "+relation+" "+e2.toString();
    }

    @Override
    public IValue eval(SymbolTable<String, IValue> symb, IHeap<Integer, IValue> heap) throws Exception {
        IValue v1 = e1.eval(symb, heap);
        IValue v2 = e2.eval(symb, heap);
        int n1, n2;
        if (v1.getType().equals(new IntType())) {
            if (v2.getType().equals(new IntType())) {
                n1 = ((IntValue) v1).getVal();
                n2 = ((IntValue) v2).getVal();
            } else if (v2 instanceof IntValue) {
                n1 = ((IntValue) v1).getVal();
                n2 = ((IntValue) v2).getVal();
            } else {
                throw new Exception("Second operand is not an int");
            }
        } else if (v1 instanceof IntValue) {
            if (v2.getType().equals(new IntType())) {
                n1 = ((IntValue) v1).getVal();
                n2 = ((IntValue) v2).getVal();
            } else if (v2 instanceof IntValue) {
                n1 = ((IntValue) v1).getVal();
                n2 = ((IntValue) v2).getVal();
            } else {
                throw new ExceptionExpr("Second operand is not an int");
            }
        } else {
            throw new ExceptionExpr("First operand is not an int");
        }
        switch (relation) {
            case EQUAL:
                return new BoolValue(n1==n2);
            case LESS_THAN:
                return new BoolValue(n1<n2);
            case GREATER_THAN:
                return new BoolValue(n1>n2);
            case LESS_OR_EQUAL:
                return new BoolValue(n1<=n2);
            case GREATER_OR_EQUAL:
                return new BoolValue(n1>=n2);
            case NOT_EQUAL:
                return new BoolValue(n1!=n2);
            default:
                throw new ExceptionExpr("Relation isn't valid");

        }
    }

}
