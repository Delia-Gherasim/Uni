#pragma once
#include <QObject>
#include <vector>
#include "Screenwritter.h"
//#include "Service.h"

class Observer {
   // Q_OBJECT
public:
    virtual void update(const std::vector<Item>& items) = 0;
    virtual ~Observer() {}
};

class Subject{
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(items);
        }
    }

    void addItem(const Item& item) {
        items.push_back(item);
        notify();
    }

    void removeItem(const Item& item) {
        auto it = std::find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
            notify();
        }
    }

private:
    std::vector<Observer*> observers;
    std::vector<Item> items;
};
