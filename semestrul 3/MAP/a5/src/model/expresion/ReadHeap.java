package model.expresion;

import model.exceptions.ExceptionExpr;
import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.RefValue;

public class ReadHeap implements IExpression{
    IExpression exp;
    public ReadHeap(IExpression expression){
        this.exp=expression;
    }

    @Override
    public String toString() {
        return exp.toString();
    }


    @Override
    public IValue eval(SymbolTable<String, IValue> symb, IHeap<Integer, IValue> heap) throws Exception {
        IValue expressionValue = exp.eval((SymbolTable<String, IValue>) symb, heap);
        if (!(expressionValue instanceof RefValue)) {
            throw new ExceptionExpr("Expression is not RefValue");
        }

        RefValue value = (RefValue) expressionValue;
        int address = value.getAddress();
        
        if (!heap.isDefined(address)) {
         throw new ExceptionExpr("The address is not a key in the heap table");
       }

        return heap.lookUp(address);
    }
}
