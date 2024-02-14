#pragma once
#include "Screenwritter.h"
#include<vector>

class Repository
{
private:
	std::vector<Screenwriter> writers;
	std::vector<Idea> ideas;

public:

	std::vector<Idea> getIdeas();
	std::vector<Screenwriter> getWriters();

	bool addWriter(Screenwriter& writer);
	bool findWriter(Screenwriter& writer);
	bool findIdea(Idea& idea);
	bool addIdea(const Idea& newIdea);
	bool removeIdea(const Idea& idea);
	bool updateIdea(Idea& updatedIdea);
	bool savePlot();

    void loadWritersFromFile(const std::string& filename);
    void loadIdeasFromFile(const std::string& filename);

};

