package model;

import java.util.Objects;

public class Motocicleta implements Item{
    private String color;
    public Motocicleta(String color){
        this.color=color;
    }
    public Motocicleta(){
        this.color="unknown";
    }

    @Override
    public String getColor(){
        return this.color;
    }

    @Override
    public String getType() {
        return "motocicleta";
    }

    @Override
    public String toString(){
        return "Motorcycle :"+" color: "+color;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Motocicleta that)) return false;
        return Objects.equals(getColor(), that.getColor());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getColor());
    }
}
