#pragma once

#include <vector>
#include <string>
#include "tutorials.h"

class Repository {
private:
    std::vector<Tutorials> tutorials;

public:
    Repository();
    void addTutorial(const Tutorials& tutorial);
    void deleteTutorial(const Tutorials& tutorial);
    void updateTutorial(const Tutorials& tutorial);
    std::vector<Tutorials> getaCertainPresenterRepo(std::string presenter);
    bool check_if_tutorial_exists(const Tutorials& tutorial);
    std::vector<Tutorials> getAll() const;
    int getSize() const;
};