#pragma once
#include "Event.h"
#include <vector>
class Repository
{
private:
	std::vector<Event> events;
	std::vector<Person> persons;
public:
	std::vector<Event> getEvents();
	std::vector<Person> getPersons();
	std::vector<Event> getAlleventsNearPerson(const Person& p);
	bool addPerson(const Person& p);
	bool addEvent(const Event& e);
	bool personIsGoing(Person& p, Event& e);


};

