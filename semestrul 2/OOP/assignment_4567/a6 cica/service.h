#pragma once
#include "Repository.h"

class Service
{
private:
	Repository& repo;
public:
	Service(Repository& _repo);

	int addTutorialService(const Tutorials& tutorial);

	int deleteTutorialService(const Tutorials& tutorial);

	int updateTutorialService(const Tutorials& tutorial);

	int getSize() const;

	std::vector<Tutorials> getTutorialsOfAPresenter(const std::string presenter) const;

	std::vector<Tutorials> get_all_tutorials() const;
};
