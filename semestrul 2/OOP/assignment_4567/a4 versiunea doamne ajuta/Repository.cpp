#include "Repository.h"
#include "DynamicVector.h"
#include <iostream>

//
//Repository::Repository(): tutorials(tutorials)
//{}

void Repository::addTutorial(const Tutorials& tutorial)
{
    this->tutorials.add(tutorial);
}

void Repository::deleteTutorial(const Tutorials& tutorial)
{
    this->tutorials.delete_(tutorial);
}

void Repository::updateTutorial(const Tutorials& tutorial)
{
    this->tutorials.update(tutorial);
}


int Repository::check_if_tutorial_exists(const Tutorials& tutorial)
{
    DynamicVector<Tutorials> list = Repository::getAll();
    int size_of_array_of_tutorials = list.getSize();
    Tutorials tutorial_in_array;
    for (int i = 0; i <= size_of_array_of_tutorials; i++)
    {
        tutorial_in_array = list.getElement(i);
        if (tutorial.getTitle() == tutorial_in_array.getTitle())
            return 1;
    }
    return 0;
}
DynamicVector<Tutorials> Repository::getaCertainPresenterRepo(std::string presenter)
{
    DynamicVector<Tutorials> list = Repository::getAll();
    int size_of_array_of_tutorials = list.getSize();
    Tutorials tutorial_in_array;
    
    for (int i = 0; i <= size_of_array_of_tutorials; i++)
    {
        tutorial_in_array = list.getElement(i);
        if (tutorial_in_array.getPresenter() != presenter)
            list.delete_(tutorial_in_array);
    }
    return list;
}
DynamicVector<Tutorials> Repository::getAll() const
{
    return this->tutorials;
}

int Repository::getSize() const
{
    return this->tutorials.getSize();
}
