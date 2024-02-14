#include "service.h"
#include "repository.h"
#include "tutorials.h"
 
#include <vector>
#include <cstdlib>

class UI {
private:
	Service& service;
	Service& service_watch_list;

public:

	UI(Service& service, Service& service_watch_list);

	void add_a_tutorial_ui();

	void delete_a_tutorial_ui();

	void update_a_tutorial_ui();

	void see_all_tutorials();

	void see_next_tutorial(int& number_of_times_see_next_tutorial_was_called, std::string presenter);

	void add_tutorial_to_watch_list(const std::string mode);

	void delete_tutorial_from_watch_list(const std::string mode);

	void see_watch_list();

	void view_watch_list(const std::string mode);

	void print_administrator_mode_options();

	void run_administrator_console();

	void print_user_mode_options();

	void run_user_console();

	void choose_user_or_administrator_mode();

};
