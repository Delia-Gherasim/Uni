package model;

import java.util.Objects;

public class Bicicleta implements Item {
    private String color;

    public Bicicleta(String color) {
        this.color = color;
    }

    public Bicicleta() {
        this.color = "unknown";
    }

    @Override
    public String getColor() {
        return this.color;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Bicicleta bicicleta)) return false;
        return Objects.equals(getColor(), bicicleta.getColor());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getColor());
    }

    @Override
    public String getType() {
        return "bicicleta";
    }

    @Override
    public String toString() {
        return "Bicycle :" + " color: " + color;
    }
}
