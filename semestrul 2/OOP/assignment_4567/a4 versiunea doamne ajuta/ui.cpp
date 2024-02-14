#include <string>
#include <iostream>
#include "Service.h"
#include "tutorials.h"
#include "Repository.h"
#include "ui.h"
#include "DynamicVector.h"
#include <vector>
#include <cstdlib>

const int MINIMUM_OPTION_ADMINISTRATOR = 1;
const int MAXIMUM_OPTION_ADMINISTRATOR = 5;
const int OPTION_FOR_EXIT = 3;
const int MINIMUM_OPTION_USER = 1;
const int MAXIMUM_OPTION_USER = 5;
const int MODE_FOR_USER = 2;
const int MODE_FOR_ADMINISTRATOR = 1;

UI::UI(Service& service, Service& service_watch_list) : service{ service }, service_watch_list{ service_watch_list }
{}
void UI::add_a_tutorial_ui()
{
	std::string title, presenter, link;
	int duration_minutes, duration_seconds, number_of_likes;
	std::cout << "Please write the title, presenter, link, duration and number of likes of the new tutorial" << std::endl;
	getchar();
	std::cout << " The title is? ";
	getline(std::cin, title);
	std::cout << " The presenter is? ";
	getline(std::cin, presenter);
	std::cout << " The link is? ";
	getline(std::cin, link);
	std::cout << " The duration is? Please first write the minutes ";
	std::cin >> duration_minutes;
	std::cout << "Now write the remaining seconds ";
	std::cin >> duration_seconds;
	std::cout << " The number of likes is? ";
	std::cin >> number_of_likes;
	Tutorials tutorial{ title, presenter, link, duration_minutes, duration_seconds, number_of_likes };
	if (this->service.addTutorialService(tutorial) == 0)
		std::cout << "Tutorial added." << "\n";
	else
		std::cout << "Tutorial already exists. " << "\n";
}

void UI::delete_a_tutorial_ui()
{
	std::string title, presenter;
	std::cout << "please write the title and presenter of the tutorial you want to delete" << std::endl;
	getchar();
	std::cout << " The title is? ";
	getline(std::cin, title);
	std::cout << " The presenter is? ";
	getline(std::cin, presenter);
	

	Tutorials tutorial{ title, presenter, "", 0, 0, 0};
	if (this->service.deleteTutorialService(tutorial) == 0)
		std::cout << "Tutorial deleted." << "\n";
	else
		std::cout << " Tutorial doesn't exist. There is nothing to delete " << "\n";
}

void UI::update_a_tutorial_ui()
{
	std::string title, presenter, link;
	int duration_minutes, duration_seconds, number_of_likes;
	std::cout << "Please write the title of the tutorial you want to update" << std::endl;
	getchar();
	std::cout << " The title is? ";
	getline(std::cin, title);
	std::cout << " Write the old presenter if you do not wish to update it or the new one otherwise " << std::endl;
	getline(std::cin, presenter);
	std::cout << " Write the old link if you do not wish to update it or the new one otherwise ";
	getline(std::cin, link);
	std::cout << " Write the old duration in minutes if you do not wish to update it or the new one otherwise ";
	std::cin >> duration_minutes;
	std::cout << " Write the old duration in seconds if you do not wish to update it or the new one otherwise ";
	std::cin >> duration_seconds;
	std::cout << " Write the old number of likes if you do not wish to update it or the new one otherwise ";
	std::cin >> number_of_likes;
	Tutorials tutorial{ title, presenter, link, duration_minutes, duration_seconds, number_of_likes };
	if (this->service.updateTutorialService(tutorial) == 0)
		std::cout << "Tutorial updated" << "\n";
	else
		std::cout << "There is no tutorial with this name to update. " << "\n";
}

void UI::see_all_tutorials()
{
	std::cout << std::endl;
	
	Tutorials tutorial;
	DynamicVector<Tutorials> list = this->service.get_all_tutorials();
	for (int i = 0; i < list.getSize(); i++)
	{
		tutorial = list.getElement(i);
		std::cout << " " << tutorial.getTitle() << "  " << tutorial.getPresenter() << "  " << tutorial.getLink() << "  " << tutorial.getDurationMinutes() << "  " << tutorial.getDurationSeconds() << "  " << tutorial.getNumberOfLikes() << std::endl;
	}

}

void UI::see_next_tutorial(int& number_of_times_see_next_tutorial_was_called, std::string presenter)
{
	std::string command;
	//Repository repo{};
	//repo = service.getRepo();
	DynamicVector<Tutorials> list = this->service.get_all_tutorials();
	Tutorials tutorial;
	//DynamicVector<Tutorials> list = repo.getAll();
	if (number_of_times_see_next_tutorial_was_called < list.getSize())
	{
		tutorial = list.getElement(number_of_times_see_next_tutorial_was_called);
		std::cout << " " << tutorial.getTitle() << "  " << tutorial.getPresenter() << "  " << tutorial.getLink() << "  " << tutorial.getDurationMinutes() << "  " << tutorial.getDurationSeconds() << "  " << tutorial.getNumberOfLikes() << std::endl;
		command = "start " + tutorial.getLink();
		std::system(command.c_str());
		number_of_times_see_next_tutorial_was_called++;
	}
	else
	{
		number_of_times_see_next_tutorial_was_called = 0;
		tutorial = list.getElement(number_of_times_see_next_tutorial_was_called);
		std::cout << " " << tutorial.getTitle() << "  " << tutorial.getPresenter() << "  " << tutorial.getLink() << "  " << tutorial.getDurationMinutes() << "  " << tutorial.getDurationSeconds() << "  " << tutorial.getNumberOfLikes() << std::endl;
		command = "start " + tutorial.getLink();
		std::system(command.c_str());
		number_of_times_see_next_tutorial_was_called++;
	}

}

void UI::add_tutorial_to_watch_list()
{
	std::string title, presenter, link;
	int duration_minutes, duration_seconds, number_of_likes;
	std::cout << "Please write the title, presenter, link, duration and number of likes of the new tutorial" << std::endl;
	getchar();
	std::cout << " The title is? ";
	getline(std::cin, title);
	std::cout << " The presenter is? ";
	getline(std::cin, presenter);
	std::cout << " The link is? ";
	getline(std::cin, link);
	std::cout << " The duration is? Please first write the minutes ";
	std::cin >> duration_minutes;
	std::cout << "Now write the remaining seconds ";
	std::cin >> duration_seconds;
	std::cout << " The number of likes is? ";
	std::cin >> number_of_likes;
	Tutorials tutorial{ title, presenter, link, duration_minutes, duration_seconds, number_of_likes };
	if (this->service_watch_list.addTutorialService(tutorial) == 0)
		std::cout << "Tutorial added." << "\n";
	else
		std::cout << "Tutorial already exists in the watch list. " << "\n";
}

void UI::delete_tutorial_from_watch_list()
{
	std::string title, presenter;

	std::cout << "please write the title and presenter of the tutorial you want to delete" << std::endl;
	getchar();
	std::cout << " The title is? ";
	getline(std::cin, title);
	std::cout << " The presenter is? ";
	getline(std::cin, presenter);

	Tutorials tutorial{ title, presenter, " ", 0, 0, 0};

	if (this->service_watch_list.deleteTutorialService(tutorial) == 0)
		std::cout << "Tutorial deleted." << "\n";
	else
		std::cout << " Tutorial isn't in the watch list. There is nothing to delete " << "\n";
	
}

void UI::see_watch_list()
{
	std::cout << std::endl;
	Tutorials tutorial;
	DynamicVector<Tutorials> list = this->service_watch_list.get_all_tutorials();
	for (int i = 0; i < list.getSize(); i++)
	{
		tutorial = list.getElement(i);
		std::cout << " " << tutorial.getTitle() <<" " << tutorial.getPresenter() << "  " << tutorial.getLink() << " " << tutorial.getDurationMinutes() << "  " << tutorial.getDurationSeconds() << "  " << tutorial.getNumberOfLikes() << std::endl;
	}

}

void UI::print_administrator_mode_options()
{
	std::cout << std::endl << std::endl;
	std::cout << "Here are the administrator options: " << std::endl;
	std::cout << " 1. Add a tutorial " << std::endl;
	std::cout << " 2. Delete a tutorial " << std::endl;
	std::cout << " 3. Update a tutorial " << std::endl;
	std::cout << " 4. See all tutorials" << std::endl;
	std::cout << " 5. Go back and choose another mode" << std::endl;

	std::cout << " Your option is? " << std::endl << " > ";
}

void UI::run_administrator_console()
{

	print_administrator_mode_options();
	int option;
	std::cin >> option;
	std::cout << std::endl << std::endl;
	while (option != MAXIMUM_OPTION_ADMINISTRATOR)
	{
		if (option == MINIMUM_OPTION_ADMINISTRATOR)
			add_a_tutorial_ui();
		else
			if (option == MINIMUM_OPTION_ADMINISTRATOR+1)
				delete_a_tutorial_ui();
			else
				if (option == MINIMUM_OPTION_ADMINISTRATOR+2)
					update_a_tutorial_ui();
				else
					if (option == MINIMUM_OPTION_ADMINISTRATOR+3)
						see_all_tutorials();
					else
						std::cout << "Invalid input" << std::endl;
		print_administrator_mode_options();
		std::cin >> option;

	}
}

void UI::print_user_mode_options()
{
	std::cout << "Here are the user options" << std::endl;
	std::cout << "1. Show tutorial of a certain presenter" << std::endl;
	std::cout << "2. Add tutorial to watchlist" << std::endl;
	std::cout << "3. Delete a tutorial from the watchlist" << std::endl;
	std::cout << "4. See the watchlist" << std::endl;
	std::cout << "5. Go back and choose another mode" << std::endl;
	std::cout << "Your option is?";
}

void UI::run_user_console()
{
	print_user_mode_options();
	int option, number_of_times_see_next_tutorial_was_called = 0;
	std::cin >> option;
	std::string presenter;
	int was_already_called_once = 0;
	
	DynamicVector<Tutorials> list = service.get_all_tutorials();
	DynamicVector<Tutorials> service_for_presenter;
	Tutorials tutorial;
	while (option != MAXIMUM_OPTION_USER)
	{
		if (option == MINIMUM_OPTION_USER)
		{
			if (was_already_called_once == 0)
			{
				std::cout << "For which presenter would you like to see the tutorials? ";
				getchar();
				getline(std::cin, presenter);

				if (!presenter.empty())
					for (int i = 0; i < list.getSize(); i++)
					{
						if (list.getElement(i).getPresenter() == presenter)
						{
							tutorial = list.getElement(i);
							service_for_presenter.add(tutorial);
						}
					}
				else
				{
					for (int i = 0; i < list.getSize(); i++)
					{
						tutorial = list.getElement(i);
						service_for_presenter.add(tutorial);
					}
				}
				was_already_called_once ++;
				see_next_tutorial( number_of_times_see_next_tutorial_was_called, presenter);
			
			}
			else
				see_next_tutorial( number_of_times_see_next_tutorial_was_called, presenter);
		}

		else
			if (option == MINIMUM_OPTION_USER+1)
				add_tutorial_to_watch_list();
			else
				if (option == MINIMUM_OPTION_USER+2)
				{
					delete_tutorial_from_watch_list();
				}
				else
					if (option == MINIMUM_OPTION_USER+3)
						see_watch_list();

					else
						std::cout << "Invalid input" << std::endl;

		print_user_mode_options();
		std::cin >> option;

	}
}

void UI::choose_user_or_administrator_mode()
{
	std::cout << "Which mode would you like to use? " << std::endl;
	std::cout << "1. Administrator " << std::endl;
	std::cout << "2. User " << std::endl;
	std::cout << "3. Exit " << std::endl;
	int mode;
	std::cout << " > ";
	std::cin >> mode;
	while (mode != OPTION_FOR_EXIT)
	{
		if (mode == MODE_FOR_ADMINISTRATOR)
			run_administrator_console();
		else
			if (mode == MODE_FOR_USER)
				run_user_console();
			else
				std::cout << "Invalid option" << std::endl;
		std::cout << std::endl << std::endl;
		std::cout << "Which mode would you like to use? " << std::endl;
		std::cout << "1. Administrator " << std::endl;
		std::cout << "2. User " << std::endl;
		std::cout << "3. Exit " << std::endl;
		std::cout << " > ";
		std::cin >> mode;
	}

}


