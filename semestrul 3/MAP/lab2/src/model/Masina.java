package model;

import java.util.Objects;

public class Masina implements Item{
    private String color;
    public Masina(String color){
        this.color=color;
    }
    public Masina(){
        this.color="unknown";
    }

    @Override
    public String getColor(){
        return this.color;
    }

    @Override
    public String getType() {
        return "masina";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Masina masina)) return false;
        return Objects.equals(getColor(), masina.getColor());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getColor());
    }

    @Override
    public String toString(){
        return "Car :"+" color: "+color;
    }
}
