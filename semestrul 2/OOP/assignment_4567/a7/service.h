#pragma once
#include "repository.h"

class Service
{
private:
	Repository& repo;

public:
	Service(Repository& repo);
	int addTutorialService(const Tutorials& tutorial);

	int deleteTutorialService(const Tutorials& tutorial);

	int updateTutorialService(const Tutorials& tutorial);

	int getSize() const;

	std::vector<Tutorials> getTutorialsOfAPresenter(const std::string presenter) const;

	std::vector<Tutorials> get_all_tutorials() const;

	Service create_a_presenter_service();
};