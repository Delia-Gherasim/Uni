#include "c.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include <fstream>
#include <iostream>
#include "Observer.h"
#include "WriterWindow.h"


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    Repository repo;
    Service service(repo);

    repo.loadWritersFromFile("writers.txt");
    repo.loadIdeasFromFile("ideas.txt");

    IdeaLogger logger;
    IdeaCounter counter;

    service.attachObserver(&logger);
    service.attachObserver(&counter);

    std::vector<Screenwriter> writers = service.getWriters();
    std::vector<Idea> ideas = service.getIdeas();

    std::vector<WriterWindow*> writerWindows;

    for (const auto& writer : writers) {
        WriterWindow* window = new WriterWindow(writer, service);
        service.attachObserver(window);
        window->show();
        window->update(ideas);
      
        writerWindows.push_back(window);
    }

    int result = a.exec();

    for (auto& window : writerWindows) {
        window->close();
        delete window;
    }
    std::ofstream fileOut("event.txt");
    if (fileOut) {
        for (auto& p : service.getIdeas()) {
            fileOut << p;
        }
        fileOut.close();
    }
    
    return result;
}