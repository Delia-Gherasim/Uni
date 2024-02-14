#pragma once
#include "tutorials.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Tutorials> tutorials;

public:
	//Repository();
	//~Repository() = default;

	void addTutorial(const Tutorials& tutorial);
	void deleteTutorial(const Tutorials& tutorial);
	void updateTutorial(const Tutorials& tutorial);
	void Tutorial(const Tutorials& tutorial);
	DynamicVector<Tutorials> getAll() const;
	int check_if_tutorial_exists(const Tutorials& tutorial);
	DynamicVector<Tutorials> getaCertainPresenterRepo(std::string presenter);
	int getSize() const;
};

