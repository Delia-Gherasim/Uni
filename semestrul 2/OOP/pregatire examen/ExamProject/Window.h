#pragma once
#include "qlistwidget.h"
#include "qcheckbox.h"
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


class Window : public QWidget, public Observer{
    Q_OBJECT
private:
    Person person;
    Service& service;
    QLineEdit* descriptionLineEdit;
    QLineEdit* dateLineEdit;
    QLineEdit* nameLineEdit;
    QLineEdit* latLineEdit;
    QLineEdit* longLineEdit;
   // QLabel* label;
    QCheckBox* checkBox;
    QPushButton* addButton;
    QPushButton* goingButton;
    QPushButton* updateButton;
    QTableWidget* TableWidget;
    QListWidget* list;
public:
   explicit Window(const Person& _person, Service& _service, QWidget* parent = nullptr);
   void update(const std::vector<Event>& events) override;

private slots:
    void addButtonClicked();
    void goingButtonClicked();
  // void updateButtonClicked();
    void checkBoxClicked();
signals:
    void modified();

};







class Logger : public Observer {
public:
    void update(const std::vector<Event>& events) override {
        std::cout << "Logger received an update:\n";
        /*for (const Event& e : ) {
            std::cout << " - " << e.getDescription() << "\n";
        }*/
        std::cout << std::endl;
    }
};

class Counter : public Observer {
public:
    void update(const std::vector<Event>& events) override {
        std::cout << "Counter received an update. Total number of events: " << events.size() << "\n\n";
    }
};
