/********************************************************************************
** Form generated from reading UI file 't3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T3_H
#define UI_T3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_t3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *t3Class)
    {
        if (t3Class->objectName().isEmpty())
            t3Class->setObjectName("t3Class");
        t3Class->resize(600, 400);
        menuBar = new QMenuBar(t3Class);
        menuBar->setObjectName("menuBar");
        t3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(t3Class);
        mainToolBar->setObjectName("mainToolBar");
        t3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(t3Class);
        centralWidget->setObjectName("centralWidget");
        t3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(t3Class);
        statusBar->setObjectName("statusBar");
        t3Class->setStatusBar(statusBar);

        retranslateUi(t3Class);

        QMetaObject::connectSlotsByName(t3Class);
    } // setupUi

    void retranslateUi(QMainWindow *t3Class)
    {
        t3Class->setWindowTitle(QCoreApplication::translate("t3Class", "t3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class t3Class: public Ui_t3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T3_H
