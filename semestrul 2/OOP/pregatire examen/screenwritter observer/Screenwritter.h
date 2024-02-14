#pragma once
#include <string>
#include<fstream>

class Screenwriter
{
private:
	std::string name;
	std::string expertize;
public:
	Screenwriter():name{""}, expertize{""}{}
	Screenwriter(std::string& _name, std::string& _expertize): name{_name}, expertize{_expertize}{}
	std::string getName() const;
	std::string getExpertize() const;

	void setExpertize(const std::string& newExpertize);
	void setName(const std::string& newName) ;

	friend std::ostream& operator<<(std::ostream& os, const Screenwriter& s) {
		os << s.name << "\n" << s.expertize;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Screenwriter& s) {
		std::getline(is >> std::ws, s.name);
		std::getline(is >> std::ws, s.expertize);
		return is;
	}

	bool operator==(const Screenwriter& other) {
		return name == other.getName() && expertize == other.getExpertize();
	}
};

class Idea {
private:
	std::string description;
	std::string status;
	std::string creator;
	int act;
public:
	Idea() :description{ "" }, status{ "" }, creator{ "" }, act{ 0 }{}
	Idea(const std::string& _description, const std::string& _status, const std::string& _creator, int _act)
		: description(_description), status(_status), creator(_creator), act(_act) {}

	Idea(std::string& _description, std::string& _status, std::string& _creator, int _act):
		description{_description}, status{_status}, creator{_creator}, act{_act}{}
	std::string getDescription()const;
	std::string getStatus()const;
	std::string getCreator()const;
	int getAct()const;

	void setDescription(const std::string& newDescription);
	void setStatus(const std::string& newStatus);
	void setCreator(const std::string& newCreator);
	void setAct(int newAct);


	std::string toString();
	friend std::ostream& operator<<(std::ostream& os, const Idea& i) {
		os << i.description << "\n" << i.status << "\n" << i.creator << "\n" << i.act << "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Idea& i) {
		std::getline(is >> std::ws, i.description);
		std::getline(is >> std::ws, i.status);
		std::getline(is >> std::ws, i.creator);

		is >> i.act;
		return is;
	}
	bool operator==(const Idea& other) {
		return description == other.getDescription() && creator == other.getCreator();
	}
};