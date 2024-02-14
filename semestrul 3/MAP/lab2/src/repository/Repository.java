package repository;

import exception.CustomException;
import exception.ItemNotFound;
import model.Item;

public class Repository implements RepositoryInterface {

    Item[] items;
    int size;

    public Repository() {
        this.items = new Item[100];
        size = 0;
    }

    @Override
    public void addItem(Item item) throws  CustomException{
        if (size==100)
            throw new CustomException("size reached");
        this.items[size++] = item;
    }

    @Override
    public void removeItem(Item item) throws ItemNotFound{
        int position = -1;
        for (int i = 0; i < this.size; i++) {
            if (this.items[i].equals(item)){
                position = i;
                break;
            }
        }
        if (position != -1) {
            for (int i = position; i < this.size - 1; i++)
                this.items[i] = this.items[i + 1];
            this.items[this.size - 1] = null;
            this.size--;
        }
        if (position == -1)
            throw new ItemNotFound("The item does not exist");
    }

    @Override
    public Item[] getAll() {
        return this.items;
    }

    @Override
    public int getSize() {
        return this.size;
    }
}
