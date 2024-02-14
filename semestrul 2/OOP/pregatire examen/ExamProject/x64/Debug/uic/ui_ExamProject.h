/********************************************************************************
** Form generated from reading UI file 'ExamProject.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPROJECT_H
#define UI_EXAMPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamProjectClass)
    {
        if (ExamProjectClass->objectName().isEmpty())
            ExamProjectClass->setObjectName("ExamProjectClass");
        ExamProjectClass->resize(600, 400);
        menuBar = new QMenuBar(ExamProjectClass);
        menuBar->setObjectName("menuBar");
        ExamProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamProjectClass);
        mainToolBar->setObjectName("mainToolBar");
        ExamProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamProjectClass);
        centralWidget->setObjectName("centralWidget");
        ExamProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamProjectClass);
        statusBar->setObjectName("statusBar");
        ExamProjectClass->setStatusBar(statusBar);

        retranslateUi(ExamProjectClass);

        QMetaObject::connectSlotsByName(ExamProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamProjectClass)
    {
        ExamProjectClass->setWindowTitle(QCoreApplication::translate("ExamProjectClass", "ExamProject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamProjectClass: public Ui_ExamProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPROJECT_H
