#include "t3.h"
#include <fstream>
#include <QtWidgets/QApplication>
#include "repository.h"
#include "service.h"
#include "shopping_list.h"
#include "header.h"


int main(int argc, char* argv[])
{
	std::ifstream fileIn("shopping_list.txt");
	if (!fileIn)
	{
		std::cerr << "error opening file for reading!\n";
		return 1;
	}

	Repository repo{};
	shopping_list shopping_list;
	while (fileIn >> shopping_list)
	{
		repo.addShopping_list(shopping_list);
	}
	fileIn.close();

	repo.sortByCategoryAndName();
	
	Service service{ repo };
	QApplication a(argc, argv);
	t3 t3{ service, nullptr };
	t3.run_options();
	return a.exec();
}
