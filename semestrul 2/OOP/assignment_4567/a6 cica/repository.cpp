#include "Repository.h"
#include <iostream>
//#include "stlvector.h"
#include <vector>
#include <algorithm>

Repository::Repository() :  tutorials(tutorials) {
}


void Repository::addTutorial(const Tutorials& tutorial)
{
	this->tutorials.push_back(tutorial);
}

void Repository::deleteTutorial(const Tutorials& tutorial)
{
	auto iterator_value = std::find(this->tutorials.begin(), this->tutorials.end(), tutorial);
	if (iterator_value != this->tutorials.end()) {
		this->tutorials.erase(iterator_value);
	}
}

void Repository::updateTutorial(const Tutorials& tutorial)
{
	auto iterator_value = std::find_if(this->tutorials.begin(), this->tutorials.end(), [tutorial](const Tutorials& tutorial_to_check) {
		return tutorial_to_check.getTitle() == tutorial.getTitle();
		});

	if (iterator_value != this->tutorials.end()) {
		*iterator_value = tutorial;
	}
}

int Repository::check_if_tutorial_exists(const Tutorials& tutorial)
{
	auto iterator_value = std::find(this->tutorials.begin(), this->tutorials.end(), tutorial);

	if (iterator_value != this->tutorials.end())
		return 1;
	return 0;
}

std::vector<Tutorials> Repository::getaCertainPresenterRepo(std::string presenter)
{

	std::vector<Tutorials> tutorials_of_a_presenter;
	for (auto tutorial:tutorials)
	{
		Tutorials tutorial_to_be_checked = tutorial;
		if (tutorial_to_be_checked.getPresenter() == presenter)
			tutorials_of_a_presenter.push_back(tutorial_to_be_checked);
	}

	return tutorials_of_a_presenter;

}

std::vector<Tutorials> Repository::getAll() const
{
	return this->tutorials;
}

int Repository::getSize() const
{
	return static_cast<int>(this->tutorials.size());
}