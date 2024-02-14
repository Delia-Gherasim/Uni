#include "t3.h"
#include "shopping_list.h"
#include <qlist.h>
#include <QtGlobal>
#include <qcolor.h>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>



t3::t3(Service& service, QWidget *parent)
    : service{ service }, QMainWindow(parent), centralWidget(nullptr)
{
    ui.setupUi(this);
}


t3::~t3()
{}

void t3::display_all()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(centralWidget->layout());
    if (!layout) {
        return;
    }
    QListWidget* qlistW = new QListWidget(this);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);

    std::vector<shopping_list> list = this->service.getAll();

    for (const shopping_list& shopping_list_item : list)
    {
        QString shopping_list_itemInfo = QString::fromStdString(shopping_list_item.getName() + " - " + shopping_list_item.getCategory());
        QListWidgetItem* item = new QListWidgetItem(shopping_list_itemInfo, qlistW);

    }
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    qlistW->show();

}


void t3::display_category()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(centralWidget->layout());
    if (!layout) {
        return;
    }

    QHBoxLayout* formLayout = new QHBoxLayout();
    QLabel* categoryLabel = new QLabel("&category: ");
    QLineEdit* categoryTextBox = new QLineEdit();
    categoryLabel->setBuddy(categoryTextBox);
    formLayout->addWidget(categoryLabel);
    formLayout->addWidget(categoryTextBox);
    layout->addLayout(formLayout);

    QPushButton* displayButton = new QPushButton("Show shopping list");
    displayButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(displayButton);

    QLabel* resultLabel = new QLabel();
    resultLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(resultLabel);

    QListWidget* qlistW = new QListWidget(this);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);

    QObject::connect(displayButton, &QPushButton::clicked, [this, categoryTextBox, qlistW, resultLabel]() {
        QString category = categoryTextBox->text();
        std::string categoryStr = category.toStdString();

        qlistW->clear();

        std::vector<shopping_list> list = this->service.getAllcategory(categoryStr);
        

        for (const shopping_list& shopping_list_item : list)
        {
            QString shopping_list_itemInfo = QString::fromStdString(shopping_list_item.getName() + " - " + shopping_list_item.getCategory());
            QListWidgetItem* item = new QListWidgetItem(shopping_list_itemInfo, qlistW);

        }
        });

    show();
}
void t3::search_item()
{

}
void t3::run_options()
{
    centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QPushButton* display_category = new QPushButton("Show the items, for a given category", centralWidget);
    display_category->setObjectName("displayCategoryButton");
    //QObject::connect(display_category, SIGNAL(clicked()), this, SLOT(display_category()));
    display_category->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(display_category);

    QPushButton* display_all = new QPushButton("Visualize all the items", centralWidget);
    display_all->setObjectName("displayAllButton");
    //QObject::connect(display_all, SIGNAL(clicked()), this, SLOT(display_all()));
    display_all->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(display_all);

    QPushButton* search_item = new QPushButton("Search for item", centralWidget);
    search_item->setObjectName("searchItemButton");
    //QObject::connect(search_item, SIGNAL(clicked()), this, SLOT(search_item())); 
    search_item->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    layout->addWidget(search_item);

    QListWidget* qlistW = new QListWidget(centralWidget);
    qlistW->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(qlistW);

    connect(display_category, &QPushButton::clicked, this, &t3::display_category);
    connect(display_all, &QPushButton::clicked, this, &t3::display_all);
    connect(search_item, &QPushButton::clicked, this, &t3::search_item);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    show();
}
