#include "a.h"
#include <QApplication>
#include "model.h"
#include "view.h"
#include "team.h"
#include "service.h"
#include "header.h"
#include "repository.h"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    std::ifstream fileIn("team.txt");
    if (!fileIn)
    {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }

    repository repo{};
    teamMember member;
    while (fileIn >> member)
    {
        repo.addTeamMember(member);
    }
    fileIn.close();

    std::ifstream filein("issue.txt");
    if (!filein)
    {
        std::cerr << "Error opening file for reading!\n";
        return 1;
    }
    Issue issue;
    while (filein >> issue)
    {
        repo.addIssue(issue);
    }
    filein.close();

    service service{ repo };
    teamModel teamModel{ service };
    issuesModel issuesModel{ service };

    QVector<View*> views; // Store pointers to views

    for (teamMember member : service.getAllTeam())
    {
        QString memberName = QString::fromStdString(member.getName());
        QString memberType = QString::fromStdString(member.getType());
        View* view = new View(teamModel, issuesModel, memberName, memberType);
        view->show();
        views.append(view); // Add view pointer to the vector
    }

    int result = a.exec();

    // Cleanup and close all windows
    for (auto& window : views) {
        window->close();
        delete window;
    }

    std::ofstream fileOut("issue.txt");
    if (fileOut)
    {
        for (Issue& issue_ : service.getAllIssues())
        {
            fileOut << issue_;
        }
        fileOut.close();
    }
    else
    {
        std::cerr << "Error opening file for writing!\n";
    }
    return result;
}
