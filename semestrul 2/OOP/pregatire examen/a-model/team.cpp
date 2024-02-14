#include "team.h"

teamMember::teamMember() : name{ "" }, type{ "" }
{

}
teamMember::teamMember(std::string& name, std::string& type)
{
	this->name = name;
	this->type = type;
}

std::string teamMember::getName()
{
	return this->name;
}

std::string teamMember::getType()
{
	return this->type;
}

void teamMember::setName(std::string name)
{
	this->name = name;
}

void teamMember::setType(std::string type)
{
	this->type = type;
}

std::string teamMember::toString()
{

	return this->name + " " + this->type;
}

Issue::Issue() :description{ "" }, status{ "" }, reporter{ "" }, solver{ "" }
{

}
Issue::Issue(std::string& description, std::string status, std::string& reporter, std::string& solver)
{
	this->description = description;
	this->status = status;
	this->reporter = reporter;
	this->solver = solver;
}

void Issue::setDescription(std::string description)
{
	this->description = description;
}

void Issue::setStatus(std::string status)
{
	this->status = status;
}

void Issue::setReporter(std::string reporter)
{
	this->reporter = reporter;
}

void Issue::setSolver(std::string solver)
{
	this->solver = solver;
}

std::string Issue::getDescription()
{
	return this->description;
}

std::string Issue::getReporter()
{
	return this->reporter;
}

std::string Issue::getSolver()
{
	return this->solver;
}

std::string Issue::getStatus()
{
	return this->status;
}

std::string Issue::toString()
{
	std::string theString = this->description + " " + " " + this->status + " " + this->reporter + " " + this->solver;
	return theString;
}
