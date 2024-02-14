/********************************************************************************
** Form generated from reading UI file 'a.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A_H
#define UI_A_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *aClass)
    {
        if (aClass->objectName().isEmpty())
            aClass->setObjectName("aClass");
        aClass->resize(600, 400);
        menuBar = new QMenuBar(aClass);
        menuBar->setObjectName("menuBar");
        aClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(aClass);
        mainToolBar->setObjectName("mainToolBar");
        aClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(aClass);
        centralWidget->setObjectName("centralWidget");
        aClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(aClass);
        statusBar->setObjectName("statusBar");
        aClass->setStatusBar(statusBar);

        retranslateUi(aClass);

        QMetaObject::connectSlotsByName(aClass);
    } // setupUi

    void retranslateUi(QMainWindow *aClass)
    {
        aClass->setWindowTitle(QCoreApplication::translate("aClass", "a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aClass: public Ui_aClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A_H
