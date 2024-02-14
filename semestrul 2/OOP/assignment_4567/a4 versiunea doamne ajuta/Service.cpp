#include "Service.h"

Service::Service(Repository& _repo) : repo{ _repo }
{
	this->repo = repo;
}

int Service::addTutorialService(const Tutorials& tutorial)
{
	if (this->repo.check_if_tutorial_exists(tutorial) == 0)
		this->repo.addTutorial(tutorial);
	else
		return 1;
	return 0;
}

int Service::deleteTutorialService(const Tutorials& tutorial)
{
	if (this->repo.check_if_tutorial_exists(tutorial) == 1)
		this->repo.deleteTutorial(tutorial);
	else
		return 1;
	return 0;
}

int Service::updateTutorialService(const Tutorials& tutorial)
{
	if (this->repo.check_if_tutorial_exists(tutorial) == 1)
		this->repo.updateTutorial(tutorial);
	else
		return 1;
	return 0;
}

int Service::getSize() const
{
	return this->repo.getSize();
}

DynamicVector<Tutorials> Service::getTutorialsOfAPresenter(const std::string presenter)const
{
	return this->repo.getaCertainPresenterRepo(presenter);
}

DynamicVector<Tutorials> Service::get_all_tutorials()
{
	DynamicVector<Tutorials> list = this->repo.getAll();
	return list;
}
