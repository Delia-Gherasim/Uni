#pragma once
#include "Repository.h"

class Service
{
private:
	Repository& repo;

public:
	Service(Repository& _repo);
	//~Service() = default;
	int addTutorialService(const Tutorials& t);
	int deleteTutorialService(const Tutorials& t);
	int updateTutorialService(const Tutorials& t);
	int getSize() const;
	DynamicVector<Tutorials> getTutorialsOfAPresenter(const std::string presenter)const;
	DynamicVector<Tutorials> get_all_tutorials();
};


