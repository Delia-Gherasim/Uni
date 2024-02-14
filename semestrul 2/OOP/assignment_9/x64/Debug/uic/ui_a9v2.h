/********************************************************************************
** Form generated from reading UI file 'a9v2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A9V2_H
#define UI_A9V2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_a9v2Class
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *UserButton;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *LinkLineEdit;
    QLineEdit *TitleLineEdit;
    QLabel *label_4;
    QLineEdit *MinutesLineEdit;
    QLabel *label_2;
    QLineEdit *PresenterLineEdit;
    QLineEdit *SecondsLineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *NumberLikesLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton_3;
    QPushButton *pushButton_4;
    QPushButton *UpdateButton_5;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *a9v2Class)
    {
        if (a9v2Class->objectName().isEmpty())
            a9v2Class->setObjectName("a9v2Class");
        a9v2Class->resize(658, 427);
        centralWidget = new QWidget(a9v2Class);
        centralWidget->setObjectName("centralWidget");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 410, 48));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        UserButton = new QPushButton(widget);
        UserButton->setObjectName("UserButton");

        horizontalLayout->addWidget(UserButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(20, 70, 521, 252));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget2 = new QWidget(widget1);
        widget2->setObjectName("widget2");
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label = new QLabel(widget2);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        LinkLineEdit = new QLineEdit(widget2);
        LinkLineEdit->setObjectName("LinkLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, LinkLineEdit);

        TitleLineEdit = new QLineEdit(widget2);
        TitleLineEdit->setObjectName("TitleLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, TitleLineEdit);

        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        MinutesLineEdit = new QLineEdit(widget2);
        MinutesLineEdit->setObjectName("MinutesLineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, MinutesLineEdit);

        label_2 = new QLabel(widget2);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        PresenterLineEdit = new QLineEdit(widget2);
        PresenterLineEdit->setObjectName("PresenterLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, PresenterLineEdit);

        SecondsLineEdit = new QLineEdit(widget2);
        SecondsLineEdit->setObjectName("SecondsLineEdit");

        formLayout->setWidget(8, QFormLayout::FieldRole, SecondsLineEdit);

        label_5 = new QLabel(widget2);
        label_5->setObjectName("label_5");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(widget2);
        label_6->setObjectName("label_6");

        formLayout->setWidget(10, QFormLayout::LabelRole, label_6);

        NumberLikesLineEdit = new QLineEdit(widget2);
        NumberLikesLineEdit->setObjectName("NumberLikesLineEdit");

        formLayout->setWidget(10, QFormLayout::FieldRole, NumberLikesLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AddButton_3 = new QPushButton(widget2);
        AddButton_3->setObjectName("AddButton_3");

        horizontalLayout_2->addWidget(AddButton_3);

        pushButton_4 = new QPushButton(widget2);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_2->addWidget(pushButton_4);

        UpdateButton_5 = new QPushButton(widget2);
        UpdateButton_5->setObjectName("UpdateButton_5");

        horizontalLayout_2->addWidget(UpdateButton_5);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(widget2);

        listWidget = new QListWidget(widget1);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        a9v2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(a9v2Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 658, 22));
        a9v2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(a9v2Class);
        mainToolBar->setObjectName("mainToolBar");
        a9v2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(a9v2Class);
        statusBar->setObjectName("statusBar");
        a9v2Class->setStatusBar(statusBar);

        retranslateUi(a9v2Class);

        QMetaObject::connectSlotsByName(a9v2Class);
    } // setupUi

    void retranslateUi(QMainWindow *a9v2Class)
    {
        a9v2Class->setWindowTitle(QCoreApplication::translate("a9v2Class", "a9v2", nullptr));
        UserButton->setText(QCoreApplication::translate("a9v2Class", "USER", nullptr));
        pushButton_2->setText(QCoreApplication::translate("a9v2Class", "ADMINISTRATOR", nullptr));
        label->setText(QCoreApplication::translate("a9v2Class", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("a9v2Class", "Link", nullptr));
        label_4->setText(QCoreApplication::translate("a9v2Class", "Minutes", nullptr));
        label_2->setText(QCoreApplication::translate("a9v2Class", "Presenter", nullptr));
        label_5->setText(QCoreApplication::translate("a9v2Class", "Seconds", nullptr));
        label_6->setText(QCoreApplication::translate("a9v2Class", "Number of likes", nullptr));
        AddButton_3->setText(QCoreApplication::translate("a9v2Class", "Add", nullptr));
        pushButton_4->setText(QCoreApplication::translate("a9v2Class", "Delete", nullptr));
        UpdateButton_5->setText(QCoreApplication::translate("a9v2Class", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class a9v2Class: public Ui_a9v2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A9V2_H
