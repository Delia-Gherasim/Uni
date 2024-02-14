#include "Service.h"

std::vector<Event> Service::getEvents()
{
    return repo.getEvents();
}

std::vector<Person> Service::getPersons()
{
    return repo.getPersons();
}

std::vector<Event> Service::getAlleventsNearPerson(const Person& p)
{
    return repo.getAlleventsNearPerson(p);
}

bool Service::addPerson(const Person& p)
{
    return repo.addPerson(p);
}

bool Service::addEvent(const Event& e)
{
    return repo.addEvent(e);
}

bool Service::personIsGoing(Person& p, Event& e)
{
    return repo.personIsGoing(p, e);
}

void Service::attachObserver(Observer* observer) {
    observers.push_back(observer);
}

void Service::detachObserver(Observer* observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Service::notifyObservers()
{
    std::vector<Event> events = getEvents();
    for (Observer* observer : observers) {
        observer->update(events);
    }
}
