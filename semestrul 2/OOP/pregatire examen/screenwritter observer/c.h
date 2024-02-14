#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_c.h"

class c : public QMainWindow
{
    Q_OBJECT

public:
    c(QWidget *parent = nullptr);
    ~c();

private:
    Ui::cClass ui;
};
