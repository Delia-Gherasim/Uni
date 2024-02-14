#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QListView>
#include <QMessageBox>
#include "model.h"

class View : public QWidget
{
    Q_OBJECT

public:
    View(teamModel& team_model, issuesModel& issues_model, QString& memberName, QString& memberType, QWidget* parent = nullptr);

private:
    teamModel& team_model;
    issuesModel& issues_model;
    QString memberName;
    QString memberType;
    QListWidget* listWidget;
    QLineEdit* descriptionLineEdit;
    QPushButton* addButton;
    QPushButton* resolveButton;
    QPushButton* removeButton;

    void setupUI();

private slots:
    void updateIssuesList();
    void addIssue();
    void resolveIssue();
    void removeIssue();

};