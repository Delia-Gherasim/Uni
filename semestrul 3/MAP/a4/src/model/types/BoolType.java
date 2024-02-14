package model.types;

import model.value.BoolValue;
import model.value.IValue;

public class BoolType implements IType {
    public BoolType() {
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

    @Override
    public String toString() {
        return "bool";
    }

    @Override
    public IValue defaultValue() {
        return new BoolValue(false);
    }
}
