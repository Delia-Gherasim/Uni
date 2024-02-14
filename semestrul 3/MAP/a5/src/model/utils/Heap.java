package model.utils;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Heap<V> implements IHeap<Integer, V>{
    Map<Integer,V> heap;
    Integer nextFreeAddress;
    public Heap(){
        heap=new HashMap<>();
        this.nextFreeAddress=1;
    }

    @Override
    public String toString(){
        return "heap= "+heap;
    }
    @Override
    public Integer add(Integer key, V value) {
        Integer pos=this.nextFreeAddress++;
        this.heap.put(pos, value);
        //System.out.println(heap);
        return key;
    }
    public Integer firstFreeAddress(){
        return nextFreeAddress;
    }
    @Override
    public V lookUp(Integer key) {
        return heap.get(key);
    }
    @Override
    public boolean isDefined(Integer address) {
        return heap.containsKey(address);
    }
    @Override
    public void update(Integer key, V value) {
        heap.put(key, value);
    }

    @Override
    public boolean isEmpty() {
        return heap.isEmpty();
    }
    @Override
    public Set<Map.Entry<Integer,V>> entrySet() {
        return heap.entrySet();
    }

    public void setContent(Map<Integer, V> newHeap){
        heap=newHeap;
    }
    @Override
    public Map<Integer, V> getContent() {
        return heap;
    }

}
