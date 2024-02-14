#pragma once
#include "repository.h"
#include <qlist.h>
class Service
{
private:
	Repository& repository;

public:
	Service(Repository& repository);
	~Service();
	bool addShopping_list(const shopping_list& shopping_list);
	std::vector<shopping_list> getAll();
	std::vector<shopping_list> getAllcategory(std::string category);
};

