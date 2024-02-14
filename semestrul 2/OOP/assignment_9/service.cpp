#include "service.h"
#include <algorithm>
#include "exceptions.h"

Service::Service(Repository& repo) : repo{ repo }
{
	this->repo = repo;
}

int Service::addTutorialService(const Tutorials& tutorial)
{
	try {
		this->repo.addTutorial(tutorial);
		return 0;
	}
	catch (const DuplicateTutorialException& error)
	{
		return 1;
	}

}

int Service::deleteTutorialService(const Tutorials& tutorial)
{
	try {
		this->repo.deleteTutorial(tutorial);
		return 0;
	}
	catch (const TutorialNotFoundException& error)
	{
		return 1;
	}
}

int Service::updateTutorialService(const Tutorials& tutorial)
{
	try {
		this->repo.updateTutorial(tutorial);
		return 0;
	}
	catch (const TutorialNotFoundException& error) {
		return 1;
	}
}

int Service::getSize() const
{
	return this->repo.getSize();
}

std::vector<Tutorials> Service::getTutorialsOfAPresenter(const std::string presenter) const
{
	return this->repo.getaCertainPresenterRepo(presenter);
}

std::vector<Tutorials> Service::get_all_tutorials() const
{
	return this->repo.getAll();
}

//Service Service::create_a_presenter_service()
//{
//	Repository repo_for_presenter{};
//	Service service_for_presenter{ repo_for_presenter };
//	return service_for_presenter;
//}
