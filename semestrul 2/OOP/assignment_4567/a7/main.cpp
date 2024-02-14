#include "header.h"
#include <iostream>
#include <crtdbg.h>
#include "service.h"
#include <assert.h>
#include "ui.h"
#include "tests.h"
#include <fstream>
#include <filesystem>

using namespace std;

int main()
{
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

		run_all_tests();

		UI ui(service, service_watch_list);
		ui.choose_user_or_administrator_mode(); 
	}
	_CrtDumpMemoryLeaks();

	return 0;
}