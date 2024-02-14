#include "a8v3.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "exceptions.h"
#include "file format.h"
#include "service.h"
#include "tutorial validator.h"
#include "tutorials.h"
#include "header.h"


int main(int argc, char* argv[])
{
	{
		QApplication app(argc, argv);

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

		a8v3 Gui(service, service_watch_list, nullptr);
		Gui.choose_user_or_administrator_mode();

		return app.exec();
	}
	_CrtDumpMemoryLeaks();
}
