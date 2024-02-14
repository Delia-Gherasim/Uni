#include "Window.h"

Window::Window(const Screenwriter& _writer, Service& _service, QWidget* parent) :  writer(_writer), service(_service), QWidget{parent}
{
  //  service.attachObserver(this);
    setWindowTitle(QString::fromStdString(writer.getName()));

    QVBoxLayout* mainLayout = new QVBoxLayout();

    QHBoxLayout* inputLayout = new QHBoxLayout();
    descriptionLineEdit = new QLineEdit();
    actSpinBox = new QSpinBox();
    actSpinBox->setMinimum(1);
    actSpinBox->setMaximum(3);

    addButton = new QPushButton("Add");
    inputLayout->addWidget(new QLabel("Description:"));
    inputLayout->addWidget(descriptionLineEdit);
    inputLayout->addWidget(new QLabel("Act:"));
    inputLayout->addWidget(actSpinBox);
    inputLayout->addWidget(addButton);

    acceptButton = new QPushButton("Accept");
    acceptButton->setEnabled(false);

    removeButton = new QPushButton("Remove");
    saveButton = new QPushButton("Save");
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(acceptButton);
    mainLayout->addWidget(removeButton);
    mainLayout->addWidget(saveButton);

    TableWidget = new QTableWidget();
    TableWidget->setColumnCount(4);
    QStringList headerLabels;
    headerLabels << "Description" << "Status" << "Creator" << "Act";
    TableWidget->setHorizontalHeaderLabels(headerLabels);
    TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    mainLayout->addWidget(TableWidget);
    setLayout(mainLayout);

    QObject::connect(addButton, &QPushButton::clicked, this, &Window::addButtonClicked);
    QObject::connect(acceptButton, &QPushButton::clicked, this, &Window::acceptButtonClicked);
    QObject::connect(removeButton, &QPushButton::clicked, this, &Window::removeButtonClicked);
    QObject::connect(saveButton, &QPushButton::clicked, this, &Window::saveButtonClicked);
}

void Window::update(const std::vector<Idea>& events)
{
        TableWidget->clearContents();
        TableWidget->setRowCount(events.size());

        int row = 0;
        for (const Idea& idea : events) {
            QTableWidgetItem* descriptionItem = new QTableWidgetItem(QString::fromStdString(idea.getDescription()));
            QTableWidgetItem* statusItem = new QTableWidgetItem(QString::fromStdString(idea.getStatus()));
            QTableWidgetItem* Item = new QTableWidgetItem(QString::fromStdString(idea.getCreator()));
            QTableWidgetItem* actItem = new QTableWidgetItem(QString::number(idea.getAct()));

            TableWidget->setItem(row, 0, descriptionItem);
            TableWidget->setItem(row, 1, statusItem);
            TableWidget->setItem(row, 2, Item);
            TableWidget->setItem(row, 3, actItem);

            ++row;
        }

        acceptButton->setEnabled(false);
}

void Window::acceptButtonClicked()
{
    QList<QTableWidgetItem*> selectedItems = TableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(nullptr, "No Idea Selected", "Please select an idea to accept.");
        return;
    }

    int selectedRow = selectedItems.first()->row();
    Idea selectedIdea = service.getIdeas()[selectedRow];
    if (selectedIdea.getStatus() == "proposed" && writer.getExpertize()=="senior") {
        selectedIdea.setStatus("accepted");
        service.updateIdea(selectedIdea);
        update(service.getIdeas());
    }
    else {
        QMessageBox::warning(nullptr, "Unable to accept", "esti pr");
    }
 }

void Window::removeButtonClicked()
{
    QList<QTableWidgetItem*> selectedItems = TableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(nullptr, "No Idea Selected", "Please select an idea to accept.");
        return;
    }
    int selectedRow = selectedItems.first()->row();
    Idea selectedIdea = service.getIdeas()[selectedRow];
    if ((selectedIdea.getStatus() != "accepted") && writer.getExpertize() == "senior") {
        service.removeIdea(selectedIdea);
        update(service.getIdeas());
    }
    else {
        QMessageBox::warning(nullptr, "Unable to remove", "esti pr");
    }
}

void Window::saveButtonClicked()
{
    if (service.savePlot()) {
        QMessageBox::information(nullptr, "Succes", "Plot saved");
    }
    else
        QMessageBox::warning(nullptr, "failed", "plm");
}

void Window::addButtonClicked() {
    {
        QString description = descriptionLineEdit->text();
        std::string descriptionString = description.toStdString();
        int act = actSpinBox->value();

        if (description.isEmpty() || act < 1 || act > 3) {
            QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid description and act (1, 2, or 3).");
            return;
        }

        Idea newIdea(descriptionString, "proposed", writer.getName(), act);
        if (service.addIdea(newIdea)) {
            descriptionLineEdit->clear();
            actSpinBox->setValue(1);
            update(service.getIdeas());
        }
        else {
            QMessageBox::warning(nullptr, "Duplicate Idea", "An idea with the same description in the same act already exists.");
        }
    }
}