package repository;

import exception.CustomException;
import exception.ItemNotFound;
import model.Item;

public interface RepositoryInterface {
    public void addItem(Item item) throws CustomException;
    public void removeItem(Item item) throws ItemNotFound;
    public Item[] getAll();
    public int getSize();
}
