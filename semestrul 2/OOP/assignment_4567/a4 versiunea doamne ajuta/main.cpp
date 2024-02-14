/*ex 4 c++
Administrator mode: The application will have a database , which holds all the tutorials. You must be able to
the database, meaning: add a new tutorial, delete a tutorial and update the information of a tutorial. Each Tutorial has a title, a presenter (name of the presenter person), a duration (minutes and seconds), a number of likes and a link towards the online resource containing the tutorial. The administrators will also have the option to see all the tutorials in the database.
User mode: A user can create a watch list with the tutorials that he/she wants to watch. The application will allow the user to:

See the tutorials in the database having a given presenter (if the presenter name is empty, see all the tutorials), one by one. When the user chooses this option, the data of the first tutorial (title, presenter, duration, number of likes) is displayed and the tutorial is played in the browser.
If the user likes the tutorial, he/she can choose to add it to his/her tutorial watch list.
If the tutorial seems uninteresting, the user can choose not to add it to the watch list and continue to the next. In this case, the information corresponding to the next tutorial is shown and the user is again offered the possibility to add it to the watch list. This can continue as long as the user wants, as when arriving to the end of the list of tutorials with the given presenter, if the user chooses next, the application will again show the first tutorial.
Delete a tutorial from the watch list, after the user watched the tutorial. When deleting a tutorial from the watch list, the user can also rate the tutorial (with a like), and in this case, the number of likes for the tutorial will be increased.
See the watch list.*/
//#include "Header.h"
//#include <iostream>
//#include "DynamicVector.h"
#include <crtdbg.h>
//#include "Service.h"
//#include <assert.h>
#include "ui.h"
#include "tests.h"

using namespace std;

int main()
{
	{
		Repository repo{};

		Tutorials t1{ "Learn C++ Programming for Beginners", "John Smith", "https://youtu.be/vNShGL3PB3M", 120, 0, 500 };
		Tutorials t2{ "Object-Oriented Programming in C++", "Emma Johnson", "https://youtu.be/BuqX__VVkW8", 90, 20, 800 };
		Tutorials t3{ "Advanced C++ Programming", "John Smith", "https://youtu.be/d_lv8HZgAHw", 60, 50, 400 };
		Tutorials t4{ "Data Structures and Algorithms in C++", "Sarah Kim", "https://youtu.be/QZE0P5MRsnU", 150, 15, 600 };
		Tutorials t5{ "Memory Management in C++", "John Smith", "https://www.youtube.com/watch?v=K6crd1jzqYg", 45, 30, 300 };
		Tutorials t6{ "STL Containers in C++", "Lisa Wang", "https://www.youtube.com/watch?v=Chol6jest_w", 80, 10, 700 };
		Tutorials t7{ "C++ Programming Best Practices", "John Smith", "https://www.youtube.com/watch?v=kEUkWeWYzbU", 120, 45, 900 };
		Tutorials t8{ "Functional Programming in C++", "Daniel Kim", "https://youtu.be/FfTwGW81B0I", 60, 0, 550 };
		Tutorials t9{ "Concurrency and Parallelism in C++", "Sophie Liu", "https://www.youtube.com/watch?v=k1jNas-J9-8", 100, 5, 750 };
		Tutorials t10{ "Debugging C++ Programs", "Kevin Zhang", "https://youtu.be/JmHXXf3p9lI", 45, 15, 350 };
		repo.addTutorial(t1);
		repo.addTutorial(t2);
		repo.addTutorial(t3);
		repo.addTutorial(t4);
		repo.addTutorial(t5);
		repo.addTutorial(t6);
		repo.addTutorial(t7);
		repo.addTutorial(t8);
		repo.addTutorial(t9);
		repo.addTutorial(t10);

		Service service{ repo };

		Repository repo_watch_list{};
		Service service_watch_list{ repo_watch_list };
		UI UI{ service, service_watch_list };
		UI.choose_user_or_administrator_mode();


		run_all_tests();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}