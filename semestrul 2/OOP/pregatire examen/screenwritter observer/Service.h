#pragma once
#include "Repository.h"
#include "Observer.h"

class Service:public Subject
{
private:
    Repository& repo;
    std::vector<Observer*> observers;

public:
    Service(Repository& repo) : repo{ repo } {}
    std::vector<Idea> getIdeas();
    std::vector<Screenwriter> getWriters();
    bool addWriter(Screenwriter& writer);
    bool addIdea(Idea& newIdea);
    bool removeIdea(Idea& idea);
    bool updateIdea(Idea& idea);
    bool savePlot();

    void attachObserver(Observer* observer);
    void detachObserver(Observer* observer);
    void notifyObservers();

};
