package model.statements;

import model.exceptions.ExceptionStatement;
import model.expresion.IExpression;
import model.types.IType;
import model.types.IntType;
import model.types.RefType;
import model.utils.Heap;
import model.utils.IDictionary;
import model.utils.IHeap;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.RefValue;

public class New implements IStatement {
    String var_name;
    IExpression expr;

    public New(String var, IExpression expression) {
        var_name = var;
        expr = expression;
    }

    @Override
    public String toString() {
        return "New( " + var_name + " " + expr +" )";
    }

    @Override
    public ProgrState execute(ProgrState state) throws Exception {
        IDictionary<String, IValue> symbolTable = state.getSymTable();
        IHeap<Integer, IValue> heap = state.getHeap();

        if (!symbolTable.isDefined(var_name)) {
            throw new ExceptionStatement("New: Variable Name is not defined");
        } else {
            SymbolTable<String, IValue> symb = (SymbolTable<String, IValue>) state.getSymTable();
            IValue expresionValue = expr.eval(symb, heap);

            if (!(expresionValue.getType() instanceof RefType)) {
                throw new ExceptionStatement("New: Variable "+var_name+" is not of type RefType");
            } else {
               IValue varValue = symbolTable.lookUp(var_name);
                IType varLocationType = varValue.getType();
               if (expresionValue.getType().equals(varValue.getType())) {
                 throw new ExceptionStatement("New: Expression "+expresionValue.getType().toString() +"and variable location type"+varLocationType.toString());
               } else {
                   int currentAdr= heap.firstFreeAddress();
                   RefType newRefType=new RefType(expresionValue.getType());
                   RefValue newRefValue = new RefValue(currentAdr, newRefType);
                   symbolTable.update(var_name, newRefValue);
                   heap.add(currentAdr,expresionValue);

               }
            }
        }
        return state;
    }
}

