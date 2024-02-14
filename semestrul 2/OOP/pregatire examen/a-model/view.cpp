#include "view.h"
#include <qstyleditemdelegate.h>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>


View::View(teamModel& team_model, issuesModel& issues_model, QString& memberName, QString& memberType, QWidget* parent) : QWidget(parent), team_model(team_model), issues_model(issues_model), memberName(memberName), memberType(memberType)
{
    setupUI();
    connect(&issues_model, &issuesModel::issuesModified, this, &View::updateIssuesList);
}

void View::updateIssuesList()
{
    // Clear the list widget
    listWidget->clear();

    // Add the updated issues to the list widget
    std::vector<Issue> allIssues = issues_model.getAll();
    for (Issue& issue : allIssues)
    {
        std::string item = issue.toString();
        QListWidgetItem* listItem = new QListWidgetItem(QString::fromStdString(item));
        listWidget->addItem(listItem);
    }
}
void View::setupUI()
{
    std::vector<Issue> allIssues = issues_model.getAll();
    listWidget = new QListWidget;
    for (int i = 0; i < allIssues.size(); i++)
    {
        std::string item = allIssues[i].toString();
        QListWidgetItem* listItem = new QListWidgetItem(QString::fromStdString(item));
        listWidget->addItem(listItem);
    }
    descriptionLineEdit = new QLineEdit(this);

    addButton = new QPushButton("Add", this);
    resolveButton = new QPushButton("Resolve", this);
    removeButton = new QPushButton("Remove", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);  // Add the QListWidget to the layout
    layout->addWidget(descriptionLineEdit);
    layout->addWidget(addButton);
    layout->addWidget(resolveButton);
    layout->addWidget(removeButton);

    setLayout(layout);

    connect(addButton, &QPushButton::clicked, this, &View::addIssue);
    connect(resolveButton, &QPushButton::clicked, this, &View::resolveIssue);
    connect(removeButton, &QPushButton::clicked, this, &View::removeIssue);

    setWindowTitle(memberName + " - " + memberType);
}


void View::addIssue()
{
    QString description = descriptionLineEdit->text();
    if (!description.isEmpty())
    {
        Issue newIssue;
        newIssue.setDescription(description.toStdString());
        newIssue.setReporter(memberName.toStdString());
        newIssue.setStatus("open");

        if (issues_model.addIssue(newIssue))
        {
            descriptionLineEdit->clear();
            std::string item = newIssue.toString();
            QListWidgetItem* listItem = new QListWidgetItem(QString::fromStdString(item));
            listWidget->addItem(listItem);
            emit issues_model.issuesModified();

        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to add the issue.");
        }
    }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to add the issue.");
        }
    
}

void View::resolveIssue()
{
    QListWidgetItem* selectedItem = listWidget->currentItem();
    if (selectedItem)
    {
        int index = listWidget->row(selectedItem);
        Issue selectedIssue = issues_model.getIssue(index);

        if (selectedIssue.getStatus() == "open" && memberType == "programmer")
        {
            if (issues_model.resolveIssue(selectedIssue, memberName.toStdString()))
            {
                QMessageBox::information(this, "OK", "Issue resolved");
                emit issues_model.issuesModified();
            }
        }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to resolve the issue.");
            }
        
    }
}

void View::removeIssue()
{
    QListWidgetItem* selectedItem = listWidget->currentItem();
    if (selectedItem)
    {
        int index = listWidget->row(selectedItem);
        Issue selectedIssue = issues_model.getIssue(index);

        if (selectedIssue.getStatus() == "closed")
        {
            if (issues_model.removeIssue(selectedIssue))
            {
                emit issues_model.issuesModified();
            }
        }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to remove the issue.");
            }
        
    }
}