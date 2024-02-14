#pragma once
#include "Observer.h"
#include "Repository.h"
class Service:public Subject
{
private:
	Repository& repo;
	std::vector<Observer*> observers;
public:
	Service(Repository& _repo): repo{_repo}{}
	std::vector<Event> getEvents();
	std::vector<Person> getPersons();
	std::vector<Event> getAlleventsNearPerson(const Person& p);
	bool addPerson(const Person& p);
	bool addEvent(const Event& e);
	bool personIsGoing(Person& p, Event& e);

	void attachObserver(Observer* observer);
	void detachObserver(Observer* observer);
	void notifyObservers();


};

