#pragma once
//#include "stlvector.h"
#include <vector>
#include <string>
#include "tutorials.h"

class Repository {
private:
    std::vector<Tutorials> tutorials;
    // STLVector<Tutorials>& stl_vector_tutorials;

public:
    Repository();
    void addTutorial(const Tutorials& tutorial);
    void deleteTutorial(const Tutorials& tutorial);
    void updateTutorial(const Tutorials& tutorial);
    std::vector<Tutorials> getaCertainPresenterRepo(std::string presenter);
    int check_if_tutorial_exists(const Tutorials& tutorial);
    std::vector<Tutorials> getAll() const;
    int getSize() const;
};