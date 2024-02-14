#pragma once
#include <QObject>
#include <vector>
#include "Event.h"

class Observer {
    // Q_OBJECT
public:
    virtual void update(const std::vector<Event>& events) = 0;
    virtual ~Observer() {}
};

class Subject {
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
            observer->update(events);
        }
    }

    void addItem(const Event& e) {
        events.push_back(e);
        notify();
    }

    void removeItem(const Event& e) {
        auto it = std::find(events.begin(), events.end(), e);
        if (it != events.end()) {
            events.erase(it);
            notify();
        }
    }

private:
    std::vector<Observer*> observers;
    std::vector<Event> events;
};
