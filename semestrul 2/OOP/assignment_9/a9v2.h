#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a9v2.h"

class a9v2 : public QMainWindow
{
    Q_OBJECT

public:
    a9v2(QWidget *parent = nullptr);
    ~a9v2();

private:
    Ui::a9v2Class ui;
};
