#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a8v3.h"

#include <QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QTableView>
#include <QApplication>
#include <QMessageBox>
#include <qobject.h>
#include <qformlayout.h>
#include <QDebug>
#include <qinputdialog.h>
#include <qmainwindow.h>
#include <qDesktopServices>
#include <QUrl>

#include "repository.h"
#include "exceptions.h"
#include "file format.h"
#include "service.h"
#include "tutorial validator.h"
#include "tutorials.h"
#include "header.h"

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>


#include<Windows.h>
#include<shellapi.h>

class a8v3 : public QMainWindow
{
    Q_OBJECT

public:
    a8v3(Service& service, Service& service_watch_list, QWidget *parent);
    ~a8v3();
	void add_a_tutorial_gui();

	void delete_a_tutorial_gui();

	void update_a_tutorial_gui();

	void see_all_tutorials();

	void see_next_tutorial(int next_tutorial_index, std::string presenter);

	void add_tutorial_to_watch_list();

	void delete_tutorial_from_watch_list();

	void view_watch_list();

	void run_administrator_console();

	void run_user_console();

	void choose_user_or_administrator_mode();
private:
	int number_of_times_submit_clicked;
	std::string mode;
	Service& service;
	Service& service_watch_list;
    Ui::a8v3Class ui;
	QWidget* centralWidget;
};
