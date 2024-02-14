#include "service.h"

Service::Service(Repository& repository) : repository{ repository }
{
    this->repository = repository;
}

Service::~Service()
{
}

bool Service::addShopping_list(const shopping_list& shopping_list)
{
    if (this->repository.check_if_shopping_item_exists(shopping_list))
        return false;
    this->repository.addShopping_list(shopping_list);
    return true;
}

std::vector<shopping_list> Service::getAll()
{
    return this->repository.getAll();
}

std::vector<shopping_list> Service::getAllcategory(std::string category)
{
    return this->repository.getAllCategory(category);
}
