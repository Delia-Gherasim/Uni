#include "a9v2.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "exceptions.h"
#include "file format.h"
#include "service.h"
#include "tutorial validator.h"
#include "tutorials.h"
#include "header.h"

int main(int argc, char *argv[])
{

	std::ifstream fileIn("tutorials.txt");
	if (!fileIn)
	{
		std::cerr << "error opening file for reading!\n";
		return 1;
	}

	Repository repo{};
	Tutorials tutorial;
	while (fileIn >> tutorial)
	{
		repo.addTutorial(tutorial);
	}
	fileIn.close();


	Service service{ repo };

	Repository repo_watch_list{};
	Service service_watch_list{ repo_watch_list };

	//(service, service_watch_list, nullptr);
	//Gui.choose_user_or_administrator_mode();

    QApplication a(argc, argv);
    a9v2 w;
    w.show();
    return a.exec();
}
