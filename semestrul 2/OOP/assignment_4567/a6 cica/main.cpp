#include <iostream>
#include <vector>
#include <algorithm>
#include <crtdbg.h>
#include "repository.h"
#include "service.h"
#include "ui.h"
#include "tests.h"

using namespace std;

int main()
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
    // UI.choose_user_or_administrator_mode();

    run_all_tests();
    _CrtDumpMemoryLeaks();

    return 0;
}