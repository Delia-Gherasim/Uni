#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_t3.h"
#include "service.h"

class t3 : public QMainWindow
{
    Q_OBJECT

public:
    
    t3(Service& service, QWidget* parent);
    ~t3();

    void display_all();

    void display_category();

    void search_item();

    void run_options();

private:
    Service& service;
    Ui::t3Class ui;
    QWidget* centralWidget;
};
