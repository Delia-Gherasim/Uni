#include "Service.h"

std::vector<Idea> Service::getIdeas()
{
    return repo.getIdeas();
}

std::vector<Screenwriter> Service::getWriters()
{
    return repo.getWriters();
}

bool Service::addWriter(Screenwriter& writer)
{
    if (repo.findWriter(writer))
        return false;
    repo.addWriter(writer);
    return false;
}

bool Service::addIdea(Idea& newIdea)
{
    bool result = repo.addIdea(newIdea);
    if (result)
        notifyObservers(); // Notify observers when a new idea is added
    return result;
}

bool Service::removeIdea(Idea& idea)
{
    bool result = repo.removeIdea(idea);
    if (result)
        notifyObservers(); // Notify observers when an idea is removed
    return result;
}

bool Service::updateIdea( Idea& idea)
{
    bool result = repo.updateIdea(idea);
    if (result)
        notifyObservers(); // Notify observers when an idea is updated
    return result;
}

bool Service::savePlot()
{
    return repo.savePlot();
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
    std::vector<Idea> ideas = getIdeas();
    for (Observer* observer : observers) {
        observer->update(ideas);
    }
}


