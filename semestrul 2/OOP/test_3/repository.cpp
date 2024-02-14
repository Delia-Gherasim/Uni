#include "repository.h"

Repository::Repository()
{
}

void Repository::addShopping_list(const shopping_list& newShoppingListItem)
{
	this->shopping_lists.push_back(newShoppingListItem);
}

void Repository::sortByCategoryAndName()
{
	std::sort(this->shopping_lists.begin(), this->shopping_lists.end(), [](const shopping_list& item1, const shopping_list& item2) {
		return item1.getName() < item2.getName() && item1.getCategory()<item2.getCategory();
		});
}

bool Repository::check_if_shopping_item_exists(const shopping_list& shopping_list)
{
	return false;
}

std::vector<shopping_list> Repository::getAll()
{
	return this->shopping_lists;
}

std::vector<shopping_list> Repository::getAllCategory(std::string category)
{
	std::vector<shopping_list> byCategory;
	for (const auto item : this->shopping_lists)
	{
		if (item.getCategory() == category)
			byCategory.push_back(item);

	}
	return byCategory;
}
std::vector<shopping_list> Repository::getAllName(std::string name)
{
	std::vector<shopping_list> byCategory;
	for (const auto item : this->shopping_lists)
	{
		if (item.getName() == name)
			byCategory.push_back(item);

	}
	return byCategory;
}
int Repository::getSize() const
{
	return this->shopping_lists.size();
}
