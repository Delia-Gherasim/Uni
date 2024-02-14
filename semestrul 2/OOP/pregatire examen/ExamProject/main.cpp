#include "ExamProject.h"
#include <QtWidgets/QApplication>
#include "Observer.h"
#include "Repository.h"
#include "Service.h"
#include "Window.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Repository repo;
    Service service(repo);

    std::ifstream fileIn("event.txt");
    if (!fileIn)
    {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }
    Event e;
    while (fileIn >> e) {
        repo.addEvent(e);
    }
    fileIn.close();
    std::ifstream filein("persons.txt");
    if (!filein)
    {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }
    Person p;
    while (filein >> p)
    {
        repo.addPerson(p);
    }
    filein.close();
    Logger logger;
    Counter counter;

    service.attachObserver(&logger);
    service.attachObserver(&counter);

    std::vector<Window*> Windows;

    for (const auto& per : service.getPersons() ) {
        Window* window = new Window(per, service);
        service.attachObserver(window);
        window->show();
        window->update(service.getEvents());

        Windows.push_back(window);
    }

    int result = a.exec();

    for (auto& window : Windows) {
        window->close();
        delete window;
    }
    std::ofstream fileOut("event.txt");
    if (fileOut) {
        for (auto& p : service.getEvents()) {
            fileOut << p;
        }
        fileOut.close();
    }

    return result;
    ExamProject w;
    w.show();
    return a.exec();
}
