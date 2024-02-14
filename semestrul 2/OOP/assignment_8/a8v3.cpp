#include "a8v3.h"

a8v3::a8v3(Service& service, Service& service_watch_list, QWidget *parent):service{ service }, service_watch_list{ service_watch_list }, QMainWindow(parent)
{
    ui.setupUi(this);
    centralWidget = new QWidget(this);
}

a8v3::~a8v3()
{}

void a8v3::add_a_tutorial_gui()
{
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    QHBoxLayout* formLayout = new QHBoxLayout();

    QLabel* titleLabel = new QLabel{ "&Title:" };
    QLineEdit* titleTextBox = new QLineEdit();
    titleLabel->setBuddy(titleTextBox);
    formLayout->addWidget(titleLabel);
    formLayout->addWidget(titleTextBox);

    QLabel* presenterLabel = new QLabel{ "&Presenter:" };
    QLineEdit* presenterTextBox = new QLineEdit();
    presenterLabel->setBuddy(presenterTextBox);
    formLayout->addWidget(presenterLabel);
    formLayout->addWidget(presenterTextBox);

    QLabel* linkLabel = new QLabel{ "&Link:" };
    QLineEdit* linkTextBox = new QLineEdit();
    linkLabel->setBuddy(linkTextBox);
    formLayout->addWidget(linkLabel);
    formLayout->addWidget(linkTextBox);

    QLabel* likesLabel = new QLabel{ "&Number of Likes:" };
    QLineEdit* likesTextBox = new QLineEdit();
    likesLabel->setBuddy(likesTextBox);
    formLayout->addWidget(likesLabel);
    formLayout->addWidget(likesTextBox);

    QLabel* minutesLabel = new QLabel{ "&Duration (minutes):" };
    QLineEdit* minutesTextBox = new QLineEdit();
    minutesLabel->setBuddy(minutesTextBox);
    formLayout->addWidget(minutesLabel);
    formLayout->addWidget(minutesTextBox);

    QLabel* secondsLabel = new QLabel{ "&Duration (seconds):" };
    QLineEdit* secondsTextBox = new QLineEdit();
    secondsLabel->setBuddy(secondsTextBox);
    formLayout->addWidget(secondsLabel);
    formLayout->addWidget(secondsTextBox);

    layout->addLayout(formLayout);

    QPushButton* submitButton = new QPushButton("Submit");
    layout->addWidget(submitButton);

    QWidget* wnd = new QWidget{};
    wnd->setLayout(layout); 
    wnd->show();

    connect(submitButton, &QPushButton::clicked, [this, titleTextBox, presenterTextBox, linkTextBox, likesTextBox, minutesTextBox, secondsTextBox, layout]() {
        QString title = titleTextBox->text();
        std::string titleStr = title.toStdString();
        QString presenter = presenterTextBox->text();
        std::string presenterStr = presenter.toStdString();
        QString link = linkTextBox->text();
        std::string linkStr = link.toStdString();
        int likes = likesTextBox->text().toInt();
        int minutes = minutesTextBox->text().toInt();
        int seconds = secondsTextBox->text().toInt();

        Tutorials tutorial{ titleStr, presenterStr, linkStr, minutes, seconds, likes };
        TutorialValidator validator;
        if (validator.validate(tutorial)) {
            if (this->service.addTutorialService(tutorial) == 0) {
                QLabel* successLabel = new QLabel{ "Tutorial added." };
                layout->addWidget(successLabel);
            }
            else {
                QLabel* duplicateLabel = new QLabel{ "Tutorial already exists." };
                layout->addWidget(duplicateLabel);
            }
        }

        std::vector<Tutorials> tutorials_list = this->service.get_all_tutorials();
        TXT txt;
        txt.set_filename("tutorials.txt");
        txt.write(tutorials_list);
        });
}

void a8v3::delete_a_tutorial_gui()
{
    QFormLayout* formlayout = new QFormLayout{};

    QLineEdit* titleTextBox = new QLineEdit{};
    QLabel* titleLabel = new QLabel{ "&Title:" };
    titleLabel->setBuddy(titleTextBox);
    formlayout->addRow(titleLabel, titleTextBox);

    QLineEdit* presenterTextBox = new QLineEdit{};
    QLabel* presenterLabel = new QLabel{ "&Presenter:" };
    presenterLabel->setBuddy(presenterTextBox);
    formlayout->addRow(presenterLabel, presenterTextBox);

    QWidget* wnd = new QWidget{};
    wnd->setLayout(formlayout);
    wnd->show();

    QPushButton* submitButton = new QPushButton("Submit");
    formlayout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, [this, titleTextBox, presenterTextBox, formlayout]() {
        QString title = titleTextBox->text();
        std::string titleStr = title.toStdString();
        QString presenter = presenterTextBox->text();
        std::string presenterStr = presenter.toStdString();

        Tutorials tutorial{ titleStr, presenterStr, "", 0, 0, 0 };
        if (this->service.deleteTutorialService(tutorial) == 0) {
            QLabel* successLabel = new QLabel{ "Tutorial deleted." };
            formlayout->addWidget(successLabel);
        }
        else {
            QLabel* failLabel = new QLabel{ "Tutorial doesn't exist. There is nothing to delete." };
            formlayout->addWidget(failLabel);
        }

        std::vector<Tutorials> tutorials_list = this->service.get_all_tutorials();
        TXT txt;
        txt.set_filename("tutorials.txt");
        txt.write(tutorials_list);
        });
}

void a8v3::update_a_tutorial_gui()
{
    QFormLayout* formlayout = new QFormLayout{};

    QLineEdit* titleTextBox = new QLineEdit{};
    QLabel* titleLabel = new QLabel{ "&Title:" };
    titleLabel->setBuddy(titleTextBox);
    formlayout->addRow(titleLabel, titleTextBox);

    QLineEdit* presenterTextBox = new QLineEdit{};
    QLabel* presenterLabel = new QLabel{ "&Presenter:" };
    presenterLabel->setBuddy(presenterTextBox);
    formlayout->addRow(presenterLabel, presenterTextBox);

    QLineEdit* linkTextBox = new QLineEdit{};
    QLabel* linkLabel = new QLabel{ "&Link:" };
    linkLabel->setBuddy(linkTextBox);
    formlayout->addRow(linkLabel, linkTextBox);

    QLineEdit* durationMinutesTextBox = new QLineEdit{};
    QLabel* durationMinutesLabel = new QLabel{ "&Duration in minutes:" };
    durationMinutesLabel->setBuddy(durationMinutesTextBox);
    formlayout->addRow(durationMinutesLabel, durationMinutesTextBox);

    QLineEdit* durationSecondsTextBox = new QLineEdit{};
    QLabel* durationSecondsLabel = new QLabel{ "&Duration in seconds:" };
    durationSecondsLabel->setBuddy(durationSecondsTextBox);
    formlayout->addRow(durationSecondsLabel, durationSecondsTextBox);

    QLineEdit* numberOfLikesTextBox = new QLineEdit{};
    QLabel* numberOfLikesLabel = new QLabel{ "&Number of likes:" };
    numberOfLikesLabel->setBuddy(numberOfLikesTextBox);
    formlayout->addRow(numberOfLikesLabel, numberOfLikesTextBox);

    QWidget* wnd = new QWidget{};
    wnd->setLayout(formlayout);
    wnd->show();

    QPushButton* submitButton = new QPushButton("Submit");
    formlayout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, [this, titleTextBox, presenterTextBox, linkTextBox, durationMinutesTextBox, durationSecondsTextBox, numberOfLikesTextBox, formlayout]() {
        QString title = titleTextBox->text();
        std::string titleStr = title.toStdString();
        QString presenter = presenterTextBox->text();
        std::string presenterStr = presenter.toStdString();
        QString link = linkTextBox->text();
        std::string linkStr = link.toStdString();
        int durationMinutes = durationMinutesTextBox->text().toInt();
        int durationSeconds = durationSecondsTextBox->text().toInt();
        int numberOfLikes = numberOfLikesTextBox->text().toInt();

        Tutorials tutorial{ titleStr, presenterStr, linkStr, durationMinutes, durationSeconds, numberOfLikes };

        if (this->service.updateTutorialService(tutorial) == 0) {
            QLabel* successLabel = new QLabel{ "Tutorial updated." };
            formlayout->addWidget(successLabel);
        }
        else {
            QLabel* failLabel = new QLabel{ "There is no tutorial with this name to update." };
            formlayout->addWidget(failLabel);
        }

        std::vector<Tutorials> tutorials_list = this->service.get_all_tutorials();
        TXT txt;
        txt.set_filename("tutorials.txt");
        txt.write(tutorials_list);
        });
}

void a8v3::see_all_tutorials()
{
    Tutorials tutorial;
    std::vector<Tutorials> list = this->service.get_all_tutorials();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(centralWidget->layout());
    if (!layout) {
        return;
    }
    QListWidget* tutorialListWidget = new QListWidget(this);
    tutorialListWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(tutorialListWidget);

    for (const Tutorials& tutorial : list)
    {
        std::string title = tutorial.getTitle();
        std::string presenter = tutorial.getPresenter();
        std::string link = tutorial.getLink();

        std::ostringstream tutorialInfoStream{};
        tutorialInfoStream << title << " "
            << presenter << " "
            << link << " "
            << tutorial.getDurationMinutes() << " "
            << tutorial.getDurationSeconds() << " "
            << tutorial.getNumberOfLikes();

        std::string tutorialInfo = tutorialInfoStream.str();

        tutorialListWidget->addItem(QString::fromStdString(tutorialInfo));
    }

    tutorialListWidget->show();
}
void a8v3::see_next_tutorial(int next_tutorial_index, std::string presenter)
{
    std::vector<Tutorials> list = this->service.get_all_tutorials();
    Tutorials tutorial;

    tutorial = list[next_tutorial_index];
    QString link = QString::fromStdString(tutorial.getLink());
    QDesktopServices::openUrl(QUrl(link));
   
}
void a8v3::add_tutorial_to_watch_list()
{
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    QHBoxLayout* formLayout = new QHBoxLayout();

    QLabel* titleLabel = new QLabel{ "&Title:" };
    QLineEdit* titleTextBox = new QLineEdit();
    titleLabel->setBuddy(titleTextBox);
    formLayout->addWidget(titleLabel);
    formLayout->addWidget(titleTextBox);

    QLabel* presenterLabel = new QLabel{ "&Presenter:" };
    QLineEdit* presenterTextBox = new QLineEdit();
    presenterLabel->setBuddy(presenterTextBox);
    formLayout->addWidget(presenterLabel);
    formLayout->addWidget(presenterTextBox);

    QLabel* linkLabel = new QLabel{ "&Link:" };
    QLineEdit* linkTextBox = new QLineEdit();
    linkLabel->setBuddy(linkTextBox);
    formLayout->addWidget(linkLabel);
    formLayout->addWidget(linkTextBox);

    QLabel* likesLabel = new QLabel{ "&Number of Likes:" };
    QLineEdit* likesTextBox = new QLineEdit();
    likesLabel->setBuddy(likesTextBox);
    formLayout->addWidget(likesLabel);
    formLayout->addWidget(likesTextBox);

    QLabel* minutesLabel = new QLabel{ "&Duration (minutes):" };
    QLineEdit* minutesTextBox = new QLineEdit();
    minutesLabel->setBuddy(minutesTextBox);
    formLayout->addWidget(minutesLabel);
    formLayout->addWidget(minutesTextBox);

    QLabel* secondsLabel = new QLabel{ "&Duration (seconds):" };
    QLineEdit* secondsTextBox = new QLineEdit();
    secondsLabel->setBuddy(secondsTextBox);
    formLayout->addWidget(secondsLabel);
    formLayout->addWidget(secondsTextBox);

    layout->addLayout(formLayout);

    QPushButton* submitButton = new QPushButton("Submit");
    layout->addWidget(submitButton);

    QWidget* wnd = new QWidget{};
    wnd->setLayout(layout); 
    wnd->show();

    connect(submitButton, &QPushButton::clicked, [this, titleTextBox, presenterTextBox, linkTextBox, likesTextBox, minutesTextBox, secondsTextBox, layout]()
        {
            QString title = titleTextBox->text();
            std::string titleStr = title.toStdString();
            QString presenter = presenterTextBox->text();
            std::string presenterStr = presenter.toStdString();
            QString link = linkTextBox->text();
            std::string linkStr = link.toStdString();
            int likes = likesTextBox->text().toInt();
            int minutes = minutesTextBox->text().toInt();
            int seconds = secondsTextBox->text().toInt();


            Tutorials tutorial{ titleStr, presenterStr, linkStr, minutes, seconds, likes };
            TutorialValidator validator;
            if (validator.validate(tutorial)) {
                if (this->service_watch_list.addTutorialService(tutorial) == 0)
                {
                    if (this->mode == "CSV")
                    {
                        std::vector<Tutorials> watch_list = this->service_watch_list.get_all_tutorials();
                        CSV csv;
                        csv.set_filename("tutorials.csv");
                        csv.write(watch_list);
                    }
                    if (this->mode == "HTML")
                    {
                        std::vector<Tutorials> watch_list = this->service_watch_list.get_all_tutorials();
                        HTML html;
                        html.set_filename("tutorials.html");
                        html.write(watch_list);

                    }
                    QLabel* successLabel = new QLabel{ "Tutorial added." };
                    layout->addWidget(successLabel);
                }
                else
                {
                    QLabel* duplicateLabel = new QLabel{ "Tutorial already exists." };
                    layout->addWidget(duplicateLabel);
                }
            }

            QWidget* wnd = new QWidget{};
            wnd->setLayout(layout);
            wnd->show();
        });
}

void a8v3::delete_tutorial_from_watch_list()
{
    QFormLayout* formlayout = new QFormLayout{};

    QLineEdit* titleTextBox = new QLineEdit{};
    QLabel* titleLabel = new QLabel{ "&Title:" };
    titleLabel->setBuddy(titleTextBox);
    formlayout->addRow(titleLabel, titleTextBox);

    QLineEdit* presenterTextBox = new QLineEdit{};
    QLabel* presenterLabel = new QLabel{ "&Presenter:" };
    presenterLabel->setBuddy(presenterTextBox);
    formlayout->addRow(presenterLabel, presenterTextBox);

    QWidget* wnd = new QWidget{};
    wnd->setLayout(formlayout);
    wnd->show();

    QPushButton* submitButton = new QPushButton("Submit");
    formlayout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, [this, titleTextBox, presenterTextBox, formlayout]() {
        QString title = titleTextBox->text();
        std::string titleStr = title.toStdString();
        QString presenter = presenterTextBox->text();
        std::string presenterStr = presenter.toStdString();

        Tutorials tutorial{ titleStr, presenterStr, "", 0, 0, 0 };
        if (this->service_watch_list.deleteTutorialService(tutorial) == 0) {
            if (this->mode == "CSV") {
                std::vector<Tutorials> watch_list = this->service_watch_list.get_all_tutorials();
                CSV csv;
                csv.set_filename("tutorials.csv");
                csv.write(watch_list);
            }
            if (this->mode == "HTML") {
                std::vector<Tutorials> watch_list = this->service_watch_list.get_all_tutorials();
                HTML html;
                html.set_filename("tutorials.html");
                html.write(watch_list);
            }
            QLabel* successLabel = new QLabel{ "Tutorial deleted." };
            formlayout->addWidget(successLabel);
        }
        else {
            QLabel* failLabel = new QLabel{ "Tutorial isn't in the watch list. There is nothing to delete." };
            formlayout->addWidget(failLabel);
        }
        });
}

void a8v3::view_watch_list()
{

    if (this->mode == "CSV" || this->mode == "HTML") {
        std::string filename;
        if (this->mode == "CSV") {
            filename = "tutorials.csv";
        }
        else {
            //ShellExecuteA(NULL, NULL, "chrome.exe", "C:\Facultation\sem2\oop\lab\a8v3\tutorials.html", NULL, SW_SHOWMAXIMIZED )
            filename = "tutorials.html";
            std::string pathToOpen = "start \"\" \"" + filename + "\"";
            QDesktopServices::openUrl(QUrl::fromLocalFile("tutorials.html"));
            system(pathToOpen.c_str());
        }
        std::string command = "start " + filename;
        system(command.c_str());

    }

}

void a8v3::run_administrator_console()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(centralWidget->layout());
    if (!layout) {
        return;
    }
    QWidget* qlistW = new QWidget(this);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);

    QLabel* label = new QLabel("Welcome, Administrator!");
    layout->addWidget(label);

    QPushButton* button1 = new QPushButton("Add a tutorial");
    connect(button1, &QPushButton::clicked, this, &a8v3::add_a_tutorial_gui);
    layout->addWidget(button1);

    QPushButton* button2 = new QPushButton("Delete a tutorial");
    connect(button2, &QPushButton::clicked, this, &a8v3::delete_a_tutorial_gui);
    layout->addWidget(button2);

    QPushButton* button3 = new QPushButton("Update a tutorial");
    QObject::connect(button3, &QPushButton::clicked, this, &a8v3::update_a_tutorial_gui);
    layout->addWidget(button3);

    QPushButton* button4 = new QPushButton("Sell all tutorials");
    QObject::connect(button4, &QPushButton::clicked, this, &a8v3::see_all_tutorials);
    layout->addWidget(button4);

    QPushButton* button5 = new QPushButton("Go back and choose another mode");
    QObject::connect(button5, &QPushButton::clicked, this, &a8v3::choose_user_or_administrator_mode);
    layout->addWidget(button5);
    
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    qlistW->show();
}

void a8v3::run_user_console()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(centralWidget->layout());
    if (!layout) {
        return;
    }
    QWidget* qlistW = new QWidget(this);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);

    int option, number_of_times_see_next_tutorial_was_called = 0;
    std::cin >> option;
    std::string presenter;
    int was_already_called_once = 0;


    QLabel* formatLabel = new QLabel("Choose the type of file to store your watch list into:");
    QComboBox* formatComboBox = new QComboBox();
    formatComboBox->addItem("CSV");
    formatComboBox->addItem("HTML");
    QPushButton* chooseFormatButton = new QPushButton("Choose Format");
    layout->addWidget(formatLabel);
    layout->addWidget(formatComboBox);
    layout->addWidget(chooseFormatButton);
    connect(chooseFormatButton, &QPushButton::clicked, this, [formatComboBox, this]()
        {
            QString mode = formatComboBox->currentText();
            this->mode = mode.toStdString();
        });

    
    QLabel* optionsLabel = new QLabel("Here are the user options:");
    layout->addWidget(optionsLabel);

    QPushButton* option1Button = new QPushButton("1. Show tutorial of a certain presenter");
    QObject::connect(option1Button, &QPushButton::clicked, [this, presenter, was_already_called_once]() {
        QFormLayout* formlayout = new QFormLayout{};
        QLineEdit* presenterTextBox = new QLineEdit{};
        QLabel* presenterLabel = new QLabel{ "&Presenter:" };
        presenterLabel->setBuddy(presenterTextBox);
        formlayout->addRow(presenterLabel, presenterTextBox);

        QPushButton* submitButton = new QPushButton("Submit");
        formlayout->addWidget(submitButton);

        QDialog dialog;
        dialog.setLayout(formlayout);

        QObject::connect(submitButton, &QPushButton::clicked, [this, presenterTextBox]() {
            std::string presenterStr = presenterTextBox->text().toStdString();
            std::vector<Tutorials> list = service.get_all_tutorials();
            std::vector<Tutorials> service_for_presenter;

            if (!presenterStr.empty()) {
                for (const Tutorials& tutorial : list) {
                    if (tutorial.getPresenter() == presenterStr) {
                        service_for_presenter.push_back(tutorial);
                    }
                }
            }
            else {
                service_for_presenter = list;
            }

            if (!service_for_presenter.empty())
            {
                if (this->number_of_times_submit_clicked < service_for_presenter.size())
                {
                    see_next_tutorial(this->number_of_times_submit_clicked, presenterStr);
                }
                else
                {
                    this->number_of_times_submit_clicked = 0;  
                    see_next_tutorial(0, presenterStr);
                }
                this->number_of_times_submit_clicked++;
            }
            });
         dialog.exec();  
         });
    layout->addWidget(option1Button);


    QPushButton* option2Button = new QPushButton("2. Add tutorial to watchlist");
    connect(option2Button, &QPushButton::clicked, this, &a8v3::add_tutorial_to_watch_list);
    layout->addWidget(option2Button);

    QPushButton* option3Button = new QPushButton("3. Delete a tutorial from the watchlist");
    QObject::connect(option3Button, &QPushButton::clicked, this, &a8v3::delete_tutorial_from_watch_list);
    layout->addWidget(option3Button);

    QPushButton* option4Button = new QPushButton("4. See the watchlist");
    QObject::connect(option4Button, &QPushButton::clicked, this, &a8v3::view_watch_list);
    layout->addWidget(option4Button);

    QPushButton* button5 = new QPushButton("Go back and choose another mode");
    QObject::connect(button5, &QPushButton::clicked, this, &a8v3::choose_user_or_administrator_mode);
    layout->addWidget(button5);

    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    qlistW->show();
}

void a8v3::choose_user_or_administrator_mode()
{
    this->number_of_times_submit_clicked = 0;

    centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QPushButton* userButton = new QPushButton("User Mode", centralWidget);
    connect(userButton, &QPushButton::clicked, this, &a8v3::run_user_console);
    layout->addWidget(userButton);

    QPushButton* adminButton = new QPushButton("Administrator Mode", centralWidget);
    connect(adminButton, &QPushButton::clicked, this, &a8v3::run_administrator_console);
    layout->addWidget(adminButton);

    
    QListWidget* qlistW = new QListWidget(centralWidget);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);
  
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    show();

}



