#include "Screenwritter.h"
std::string Screenwriter::getName() const
{
    return name;
}

std::string Screenwriter::getExpertize() const
{
    return expertize;
}

void Screenwriter::setExpertize(const std::string& newExpertize)
{
    expertize = newExpertize;
}

void Screenwriter::setName(const std::string& newName)
{
    name = newName;
}

std::string Idea::getDescription() const
{
    return description;
}

std::string Idea::getStatus() const
{
    return status;
}

std::string Idea::getCreator() const
{
    return creator;
}

int Idea::getAct()const
{
    return act;
}

void Idea::setDescription(const std::string& newDescription)
{
    description = newDescription;
}

void Idea::setStatus(const std::string& newStatus)
{
    status = newStatus;
}

void Idea::setCreator(const std::string& newCreator)
{
    creator = newCreator;
}

void Idea::setAct(int newAct)
{
    act = newAct;
}

std::string Idea::toString()
{
    return description + " " + status + " " + creator + " " + std::to_string(act);
}
