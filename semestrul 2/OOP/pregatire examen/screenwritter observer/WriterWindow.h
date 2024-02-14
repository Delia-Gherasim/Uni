#pragma once
#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QTableWidget>
#include <QMessageBox>
#include <fstream>
#include "Service.h"
#include "Observer.h"
#include <iostream>
#include "Screenperson.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget,  public Observer{
    Q_OBJECT
private:
    Person writer;
    Service& service;
    QLineEdit* descriptionLineEdit;
    QSpinBox* actSpinBox;
    QPushButton* addButton;
    QPushButton* acceptButton;
    QPushButton* removeButton;
    QPushButton* saveButton;
    QTableWidget* TableWidget;
public:
   explicit  Window(const Person& _writer, Service& _service, QWidget* parent=nullptr);
   void update(const std::vector<Event>& events) override;

private slots:
    void addButtonClicked();
    void acceptButtonClicked();
    void removeButtonClicked();
    void saveButtonClicked();
signals:
    void modified();

};

class IdeaLogger : public Observer {
public:
    void update(const std::vector<Event>& events) override {
        std::cout << "Event Logger received an update:\n";
        for (const Event& event : events) {
            std::cout << " - " << event.getDescription() << "\n";
        }
        std::cout << std::endl;
    }
};

class IdeaCounter : public Observer {
public:
    void update(const std::vector<Event>& events) override {
        std::cout << "Event Counter received an update. Total number of events: " << events.size() << "\n\n";
    }
};
