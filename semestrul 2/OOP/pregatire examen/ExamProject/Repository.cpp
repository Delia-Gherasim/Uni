#include "Repository.h"

std::vector<Event> Repository::getEvents()
{
    for (int i = 0; i < events.size(); i++)
        for (int j = 0; j < events.size(); j++)
            if (events[i].getDate() < events[j].getDate())
                std::swap(events[i], events[j]);
    return events;
}

std::vector<Person> Repository::getPersons()
{
    return persons;
}

std::vector<Event> Repository::getAlleventsNearPerson(const Person& p)
{
    std::vector<Event> result;
    for (auto e : events) {
        int x1 = e.getLat();
        int x2 = p.getLatitude();
        int y1 = e.getLong();
        int y2 = p.getLongitude();
        if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= 5)
            result.push_back(e);
    }
    return result;
}

bool Repository::addPerson(const Person& p)
{
    for (const Person& pers: persons) {
        if(pers.getName()==p.getName() && pers.getStatus()==p.getStatus()){
       
            return false;
        }
    }
    persons.push_back(p);
    return true;
}

bool Repository::addEvent(const Event& e)
{
    for (const Event& ev : events) {
        if (ev.getName() == e.getName() && ev.getLat() == e.getLat() && ev.getLong() == e.getLong())
            return false;
    }
    events.push_back(e);
    return true;
}

bool Repository::personIsGoing(Person& p, Event& e)
{
    for (auto ev : events) {
        if (ev.getName() == e.getName() && ev.getLat() == e.getLat() && ev.getLong() == e.getLong())
            return false;
    }
    for (auto pers : persons) {
        if (pers.getName() == p.getName() && pers.getStatus() == p.getStatus()) {

            return false;
        }
    }
    p.setLat(e.getLat());
    p.setLong(e.getLong());
    return true;
}
