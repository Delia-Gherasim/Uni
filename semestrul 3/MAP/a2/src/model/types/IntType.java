package model.types;

import java.util.Objects;

public class IntType implements IType{

    public IntType(){}

    @Override
    public boolean equals(Object obj) {
        if (this==obj)
            return true;
        if (!(obj instanceof IntType intType))
            return false;

        return super.equals(obj);
    }

    @Override
    public String  toString() {
        return "int";
    }
}
