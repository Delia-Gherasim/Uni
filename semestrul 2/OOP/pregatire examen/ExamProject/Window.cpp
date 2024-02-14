#include "Window.h"

Window::Window(const Person& _person, Service& _service, QWidget* parent): person{_person}, service{_service}
{
	setWindowTitle(QString::fromStdString(person.getName()));
	QVBoxLayout* mainLayout = new QVBoxLayout();
	QHBoxLayout* inputLayout = new QHBoxLayout();
	descriptionLineEdit = new QLineEdit();
	dateLineEdit = new QLineEdit();
	nameLineEdit = new QLineEdit();
	latLineEdit = new QLineEdit();
	longLineEdit = new QLineEdit();


	QCheckBox* checkBox = new QCheckBox("Events near");
	QLabel* label = new QLabel("Checkbox state: Unchecked");
	//label= new QLabel("Checkbox state: Unchecked");
	/*QObject::connect(&checkBox, &QCheckBox::stateChanged, [&](int state) {
		QString stateText = (state == Qt::Checked) ? "Checked" : "Unchecked";
		label.setText("Checkbox state: " + stateText);
		Window::checkBoxClicked();
		});*/
	QObject::connect(checkBox, &QCheckBox::stateChanged, this, &Window::checkBoxClicked);

	addButton = new QPushButton("Add");
	inputLayout->addWidget(new QLabel("Name: "));
	inputLayout->addWidget(nameLineEdit);
	inputLayout->addWidget(new QLabel("Description:"));
	inputLayout->addWidget(descriptionLineEdit);
	inputLayout->addWidget(new QLabel("Latitude: "));
	inputLayout->addWidget(latLineEdit);
	inputLayout->addWidget(new QLabel("Longitude"));
	inputLayout->addWidget(longLineEdit);
	inputLayout->addWidget(new QLabel("date:"));
	inputLayout->addWidget(dateLineEdit);

	goingButton = new QPushButton("Going");

	TableWidget = new QTableWidget();
	TableWidget->setColumnCount(5);
	QStringList headerLabels;
	headerLabels << "Organizer" << "Name" << "langitude" << "longitude"<<"Day";
	TableWidget->setHorizontalHeaderLabels(headerLabels);
	TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

	mainLayout->addWidget(TableWidget);
	mainLayout->addWidget(addButton);
	mainLayout->addLayout(inputLayout);

	mainLayout->addWidget(goingButton);
	//mainLayout->addWidget(&checkBox);
	//mainLayout->addWidget(&label);

	mainLayout->addWidget(checkBox);
	mainLayout->addWidget(label);

	setLayout(mainLayout);
	setLayout(mainLayout);

	QObject::connect(addButton, &QPushButton::clicked, this, &Window::addButtonClicked);
//	QObject::connect(updateButton, &QPushButton::clicked, this, &Window::updateButtonClicked);
	QObject::connect(goingButton, &QPushButton::clicked, this, &Window::goingButtonClicked);

}


void Window::update(const std::vector<Event>& events)
{
	TableWidget->clearContents();
	TableWidget->setRowCount(events.size());

	int row = 0;
	for (const Event& e : events) {
		QTableWidgetItem* organizerItem = new QTableWidgetItem(QString::fromStdString(e.getOrganizer()));
		QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(e.getName()));

		QTableWidgetItem* latItem = new QTableWidgetItem(QString::number(e.getLat()));
		QTableWidgetItem* longItem = new QTableWidgetItem(QString::number(e.getLong()));
		QTableWidgetItem* dayItem = new QTableWidgetItem(QString::number(e.getDate()));

		TableWidget->setItem(row, 0, organizerItem);
		TableWidget->setItem(row, 1, nameItem);
		TableWidget->setItem(row, 2, latItem);
		TableWidget->setItem(row, 3, longItem);
		TableWidget->setItem(row, 4, dayItem);

		++row;
	}

	QList<QTableWidgetItem*> selectedItems = TableWidget->selectedItems();
	if (selectedItems.isEmpty()) {
		
	}
	else {

	/*	int selectedRow = selectedItems.first()->row();
		Event selectedEvent = service.getEvents()[selectedRow];
		QHBoxLayout* inputLayout = new QHBoxLayout();
		inputLayout->addWidget(new QLabel(selectedEvent.getDescr());*/
		
	}

}


void Window::goingButtonClicked()
{
	QList<QTableWidgetItem*> selectedItems = TableWidget->selectedItems();
	if (selectedItems.isEmpty()) {
		QMessageBox::warning(nullptr, "No Event Selected", "Please select .");
		return;
	}

	int selectedRow = selectedItems.first()->row();
	Event selectedEvent = service.getEvents()[selectedRow];

	if (person.getStatus()==false) {
		service.personIsGoing(person, selectedEvent);
		update(service.getEvents());

		goingButton->setEnabled(false);
	}
	else {
		QMessageBox::warning(nullptr, "Unable", "");
	}
}

void Window::checkBoxClicked()
{
	TableWidget->clearContents();
	std::vector<Event> events = service.getAlleventsNearPerson(person);
	TableWidget->setRowCount(events.size());

	int row = 0;
	for (const Event& e : events) {
		QTableWidgetItem* organizerItem = new QTableWidgetItem(QString::fromStdString(e.getOrganizer()));
		QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(e.getName()));

		QTableWidgetItem* latItem = new QTableWidgetItem(QString::number(e.getLat()));
		QTableWidgetItem* longItem = new QTableWidgetItem(QString::number(e.getLong()));
		QTableWidgetItem* dayItem = new QTableWidgetItem(QString::number(e.getDate()));

		TableWidget->setItem(row, 0, organizerItem);
		TableWidget->setItem(row, 1, nameItem);
		TableWidget->setItem(row, 2, latItem);
		TableWidget->setItem(row, 3, longItem);
		TableWidget->setItem(row, 4, dayItem);

		++row;
	}
}



void Window::addButtonClicked() {
	QString description = descriptionLineEdit->text();
	std::string descriptionString = description.toStdString();

	QString dayStr = dateLineEdit->text();
	std::string da = dayStr.toStdString();
	int day = std::stoi(da); 

	if (person.getStatus()) {
		if (description.isEmpty() || dayStr.isEmpty()) {
			QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid description and day.");
			return;
		}
		
		QString lat = latLineEdit->text();
		QString log = longLineEdit->text();
		QString namele = nameLineEdit->text();

		std::string name = person.getcName();

		Event newEvent(name,namele.toStdString(), descriptionString, std::stoi(lat.toStdString()), std::stoi(log.toStdString()), day);
		if (service.addEvent(newEvent)) {
			descriptionLineEdit->clear();
			nameLineEdit->clear();
			dateLineEdit->clear();
			longLineEdit->clear();
			latLineEdit->clear();
			update(service.getEvents());
		}
		else {
			QMessageBox::warning(nullptr, "Duplicate Event", "");
		}
	}
	else {
		QMessageBox::warning(nullptr, "No", "You're not an organizer");
	}
}
