#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamProject.h"

class ExamProject : public QMainWindow
{
    Q_OBJECT

public:
    ExamProject(QWidget *parent = nullptr);
    ~ExamProject();

private:
    Ui::ExamProjectClass ui;
};
