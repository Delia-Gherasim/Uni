package model.types;

import model.value.IValue;
import model.value.IntValue;

public class IntType implements IType {

    public IntType() {
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!(obj instanceof IntType intType))
            return false;

        return super.equals(obj);
    }

    @Override
    public String toString() {
        return "int";
    }

    @Override
    public IValue defaultValue() {
        return new IntValue(0);
    }
}
