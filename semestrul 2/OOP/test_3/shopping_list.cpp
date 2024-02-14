#include "shopping_list.h"


shopping_list::shopping_list() : category{ "" }, name{ "" }, quantity(0)
{
}

shopping_list::shopping_list(std::string& category, std::string& name, int quantity)
{
	this->category = category;
	this->name = name;
	this->quantity = quantity;
}

std::string shopping_list::getName() const
{
	return this->name;
}

std::string shopping_list::getCategory() const
{
	return this->category;
}

int shopping_list::getQuantity() const
{
	return this->quantity;
}
void shopping_list::setName(std::string newName)
{
	this->name = newName;
}
void shopping_list::setCategory(std::string newCategory)
{
	this->category = newCategory;
}
void shopping_list::setQuantity(int newQuantity)
{
	this->quantity = newQuantity;
}
bool shopping_list::operator==(const shopping_list& other) const
{
	return this->name == other.name && this->category == other.category;
}
