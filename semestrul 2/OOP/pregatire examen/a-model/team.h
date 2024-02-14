#pragma once
#include "header.h"


class teamMember
{
private:
	std::string name;
	std::string type;

public:
	teamMember();
	teamMember(std::string& name, std::string& type);
	std::string getName();
	std::string getType();

	void setName(std::string name);
	void setType(std::string type);

	std::string toString();

	/*bool operator==(teamMember& other) {
		return (this->name == other.name && this->type == other.type);
	}*/

	friend std::ostream& operator<<(std::ostream& os, teamMember& member)
	{
		os << member.name << std::endl
			<< member.type << std::endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, teamMember& member)
	{
		std::getline(is >> std::ws, member.name);
		std::getline(is >> std::ws, member.type);
		return is;
	}
	std::string const getConstName() const {
		std::string name =name; 
		return name;
	}

	std::string const getConstType() const {
		return type;
	}

	bool operator==(teamMember& other) {
		return getConstName() == other.getConstName() && getConstType() == other.getConstType();
	}
};

class Issue
{
private:
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;

public:
	Issue();
	Issue(std::string& description, std::string status, std::string& reporter, std::string& solver);
	void setDescription(std::string description);
	void setStatus(std::string status);
	void setReporter(std::string reporter);
	void setSolver(std::string solver);

	std::string getDescription();
	std::string getReporter();
	std::string getSolver();
	std::string getStatus();

	std::string toString();

	/*bool operator==(Issue& other)
	{
		return this->description == other.getDescription() && this->reporter == other.getReporter();
	}*/

	bool operator==(const Issue& other) {
		return getConstDescription() == other.getConstDescription() && getConstReporter() == other.getConstReporter();
	}
	friend std::ostream& operator<<(std::ostream& os, Issue& issue)
	{
		os << issue.description << std::endl
			<< issue.status << std::endl
			<< issue.reporter << std::endl
			<< issue.solver << std::endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Issue& issue)
	{
		std::getline(is >> std::ws, issue.description);
		std::getline(is >> std::ws, issue.status);
		std::getline(is >> std::ws, issue.reporter);
		std::getline(is >> std::ws, issue.solver);
		return is;
	}

	std::string const getConstDescription() const{
		return description;
	}

	std::string const getConstStatus() const {
		return status;
	}

	std::string const getConstReporter() const {
		return reporter;
	}
};