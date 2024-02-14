#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a.h"

class a : public QMainWindow
{
    Q_OBJECT

public:
    a(QWidget *parent = nullptr);
    ~a();

private:
    Ui::aClass ui;
};
