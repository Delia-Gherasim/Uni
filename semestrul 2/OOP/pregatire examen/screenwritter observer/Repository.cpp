#include "Repository.h"
#include <algorithm>
#include <iostream>

std::vector<Idea> Repository::getIdeas()
{
    std::sort(ideas.begin(), ideas.end(), []( Idea& idea1,  Idea& idea2) {
        if (idea1.getAct() < idea2.getAct())
            return true;
        if (idea1.getAct() > idea2.getAct())
            return false;
        return idea1.getCreator() < idea2.getCreator();
        });

    return ideas;
}


std::vector<Screenwriter> Repository::getWriters()
{
    return writers;
}


bool Repository::addWriter(Screenwriter& writer)
{
    if (findWriter(writer))
        return false;
    writers.push_back(writer);
    return true;
}
bool Repository::findWriter(Screenwriter& writer)
{
    for (auto i : writers) {
        if (writer == i)
            return true;
    }
    return false;
}

bool Repository::addIdea(const Idea& newIdea)
{
    for (const Idea& idea : ideas) {
        if (idea.getDescription() == newIdea.getDescription() && idea.getAct() == newIdea.getAct()) {
            return false; 
        }
    }

    ideas.push_back(newIdea);
  //  notifyObservers();
    return true;
}

bool Repository::findIdea(Idea& idea)
{
    for (auto i : ideas) {
        if (idea == i)
            return true;
    }
    return false;
}
bool Repository::removeIdea(const Idea& idea)
{
    auto it = std::find(ideas.begin(), ideas.end(), idea);
    if (it != ideas.end()) {
        ideas.erase(it);
      //  notifyObservers();
        return true;
    }
    return false;
}
bool Repository::updateIdea(Idea& updatedIdea)
{
    auto it = std::find(ideas.begin(), ideas.end(), updatedIdea);
    if (it != ideas.end()) {
        *it = updatedIdea;
    //    notifyObservers();
        return true;
    }
    return false;
}

bool Repository::savePlot()
{
    std::ofstream file("savedplot.txt");
    if (!file) {
        std::cerr << "error opening file ";
        return false;
    }

    int lastAct = 0;
    for (auto i : ideas) {
        if (i.getAct() != lastAct) {
            lastAct++;
            file << "Act " << lastAct << "\n";
        }
        if (i.getStatus()=="accepted")
            file << i.toString() << "\n";
    }
    return true;
}

void Repository::loadWritersFromFile(const std::string& filename)
{
    std::ifstream fileIn(filename);
    if (!fileIn) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    Screenwriter writer;
    while (fileIn >> writer) {
        writers.push_back(writer);
    }
    fileIn.close();
}


void Repository::loadIdeasFromFile(const std::string& filename)
{
    std::ifstream fileIn(filename);
    if (!fileIn) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    Idea idea;
    while (fileIn >> idea) {
        ideas.push_back(idea);
    }
    fileIn.close();
    
}

//void Repository::addObserver(Observer* observer)
//{
//    observers.push_back(observer);
//}
//
//void Repository::removeObserver(Observer* observer)
//{
//    auto it = std::find(observers.begin(), observers.end(), observer);
//    if (it != observers.end()) {
//        observers.erase(it);
//    }
//}
//
//void Repository::notifyObservers()
//{
//    for (Observer* observer : observers) {
//        observer->update(ideas);
//    }
//}

