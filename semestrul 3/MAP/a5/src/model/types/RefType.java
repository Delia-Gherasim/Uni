package model.types;

import model.value.IValue;
import model.value.RefValue;

import java.util.Objects;

public class RefType implements IType{
    IType inner;
    public RefType(){}
    public RefType(IType inner){
        this.inner=inner;
    }
    public IType getInner(){
        return inner;
    }

    @Override
    public boolean equals(Object obj) {
        //return super.equals(obj);
        return obj instanceof RefType ? this.inner.equals(((RefType)obj).getInner()) : false;
    }

    @Override
    public String toString(){
        return  "Ref("+inner.toString()+") ";
    }

    @Override
    public IValue defaultValue() {
        return new RefValue(1, inner);
    }
}
