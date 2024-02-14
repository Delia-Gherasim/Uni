#pragma once
#include <string>
#include <fstream>
class Event
{
private:
	std::string organizer;
	std::string name;
	std::string description;
	int loc_lat;
	int loc_long;
	int date;
public:
	Event():organizer{""}, name{""}, description{""}, loc_lat{0}, loc_long{0}, date{0}{}
	Event(const std::string& _org, const std::string& _name, const std::string& _desc, int _lat, int _long, int _date):organizer{_org}, name{_name}, description{_desc}, loc_lat{_lat}, loc_long{_long}, date{_date}{}

	void setOrganizer(const std::string& org);
	void setName(const std::string& _name);
	void setDescription(const std::string& _desc);
	void setLat(int _lat);
	void setLong(int _long);
	void setDate(int _date);

	std::string getOrganizer() const;
	std::string getName() const;
	std::string const getcName() const;
	std::string getDescr() const;
	int getLat() const;
	int getLong() const;
	int getDate() const;

	std::string toString() const;

	friend std::ostream& operator<<(std::ostream& os, Event& e) {
		os << e.organizer << "\n" << e.name << "\n" << e.description << "\n" << e.loc_lat << "\n" << e.loc_long << "\n" << e.date << "\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Event& e) {
		std::getline(is >> std::ws, e.organizer);
		std::getline(is >> std::ws, e.name);
		std::getline(is >> std::ws, e.description);
		is >> e.loc_lat >> e.loc_long >> e.date;

		return is;
	}
	bool operator==(const Event& other) {
		return organizer == other.getOrganizer() && name == other.getcName();
	}
};

class Person {
private:
	std::string name;
	int loc_lat;
	int loc_long;
	bool status;
public:
	Person() :name{ "" }, loc_lat{ 0 }, loc_long{ 0 }, status{ false } {}
	Person(const std::string& _name, int _lat, int _long, bool _status):name{_name}, loc_lat{_lat}, loc_long{_long}, status{_status}{}

	void setName(const std::string& _name);
	void setLat(int _lat);
	void setLong(int _long);
	void setStatus(bool _sta);

	std::string const getcName() const;

	std::string getName() const;
	int getLatitude() const;
	int getLongitude() const;
	bool getStatus() const;

	friend std::ostream& operator<<(std::ostream& os, Person& e) {
		os << e.name << "\n" << e.loc_lat << "\n" << e.loc_long << "\n" << e.status << "\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Person& e) {
		std::getline(is >> std::ws, e.name);
		is >> e.loc_lat >> e.loc_long >> e.status;

		return is;
	}

	bool operator==(const Person& other) {
		return name == other.getcName();
	}

};

