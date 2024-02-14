package controller;

import exception.CustomException;
import exception.ItemNotFound;
import model.Item;
import repository.RepositoryInterface;

import java.util.Objects;

public class Controller {
    RepositoryInterface repo;

    public Controller(RepositoryInterface repository) {
        this.repo = repository;
    }

    public void addItem(Item item) throws CustomException {
        this.repo.addItem(item);

    }

    public void removeItem(Item item) throws ItemNotFound {
        this.repo.removeItem(item);

    }

    public Item[] getAll() {
        return this.repo.getAll();
    }

    public Item[] getFiltered() {
        int j = 0;
        Item[] filteredItems;
        filteredItems = new Item[100];
        for (int i = 0; i < this.repo.getSize(); i++) {
            if (Objects.equals(this.repo.getAll()[i].getColor(), "red")) {
                filteredItems[j] = this.repo.getAll()[i];
                j++;
            }
        }
        return filteredItems;
    }

    public int getFilteredSize() {
        int j = 0;
        for (int i = 0; i < this.repo.getSize(); i++) {
            if (Objects.equals(this.repo.getAll()[i].getColor(), "red")) {
                j++;
            }
        }
        return j;
    }

    public int getSize() {
        return this.repo.getSize();
    }
}
