package model.utils;

import java.util.List;

public interface IStack<T> {
    void push(T elem);

    T pop();

    boolean isEmpty();

    List<T> getReverse();
}
