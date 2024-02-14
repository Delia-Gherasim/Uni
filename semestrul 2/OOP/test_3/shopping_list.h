#pragma once
#include "header.h"
#include <string>
#include <iostream>
class shopping_list
{
private:
	std::string category;
	std::string name;
	int quantity;

public:
	shopping_list();
    shopping_list(std::string& category, std::string& name, int quantity);
      

    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;

    void setName(std::string newName);
    void setCategory(std::string newCategory);
    void setQuantity(int newQuantity);

    bool operator==(const shopping_list& other) const;

    friend std::ostream& operator<<(std::ostream& os, const shopping_list& shopping_list)
    {
        os << shopping_list.category << std::endl
            << shopping_list.name << std::endl
            << shopping_list.quantity << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, shopping_list& shopping_list)
    {
        std::getline(is >> std::ws, shopping_list.category);
        std::getline(is >> std::ws, shopping_list.name);
        is >> shopping_list.quantity;

        return is;
    }
    
};

