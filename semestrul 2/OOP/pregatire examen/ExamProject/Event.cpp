#include "Event.h"

void Event::setOrganizer(const std::string& org)
{
	organizer = org;
}

void Event::setName(const std::string& _name)
{
	name = _name;
}

void Event::setDescription(const std::string& _desc)
{
	description = _desc;
}

void Event::setLat(int _lat)
{
	loc_lat = _lat;
}

void Event::setLong(int _long)
{
	loc_long = _long;
}

void Event::setDate(int _date)
{
	date = _date;
}

std::string Event::getOrganizer() const
{
	return organizer;
}

std::string Event::getName() const
{
	return name;
}

std::string const Event::getcName() const
{
	return name;
}

std::string Event::getDescr() const
{
	return description;
}

int Event::getLat() const
{
	return loc_lat;
}

int Event::getLong() const
{
	return loc_long;
}

int Event::getDate() const
{
	return date;
}

std::string Event::toString() const
{

	return organizer + " " + name + " " + std::to_string(loc_lat) + " " + std::to_string(loc_long)+" "+std::to_string(date);
}

void Person::setName(const std::string& _name)
{
	name = _name;
}

void Person::setLat(int _lat)
{
	loc_lat = _lat;
}

void Person::setLong(int _long)
{
	loc_long = _long;
}

void Person::setStatus(bool _sta)
{
	status = _sta;
}

std::string const Person::getcName() const
{
	return name;
}

std::string Person::getName() const
{
	return name;
}

int Person::getLatitude() const
{
	return loc_lat;
}

int Person::getLongitude() const
{
	return loc_long;
}

bool Person::getStatus() const
{
	return status;
}
