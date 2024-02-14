package model.utils;

import model.value.IValue;

import java.util.Map;
import java.util.Set;
import java.lang.Integer;

public interface IHeap<Integer, V> {
    public Integer add(Integer key, V value);
    public boolean isEmpty();
    public Integer firstFreeAddress();
    public void update(Integer key, V value);
    public Set<Map.Entry<Integer,V>> entrySet();
    public V lookUp(Integer key);
    boolean isDefined(Integer address);
    void setContent(Map<Integer, V> newMap);
    Map<Integer, V> getContent();
}
