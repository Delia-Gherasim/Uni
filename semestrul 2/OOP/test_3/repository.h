#pragma once
#include <vector>
#include "shopping_list.h"
#include <algorithm>
#include <iostream>

class Repository
{
private:
	std::vector<shopping_list> shopping_lists;

public:
	Repository();

	void addShopping_list(const shopping_list& newshopping_list);
	void sortByCategoryAndName();
	bool check_if_shopping_item_exists(const shopping_list& shopping_list);
	std::vector<shopping_list> getAll();
	std::vector<shopping_list> getAllCategory(std::string category);
	std::vector<shopping_list> getAllName(std::string name);
	int getSize() const;


};


