#pragma once
#include <QObject>
#include <QModelIndex>
#include <QVariant>
#include <QAbstractListModel>
#include <vector>
#include "service.h"

class teamModel :public QAbstractListModel
{
	Q_OBJECT
public:
	teamModel(service& teamService, QObject* parent = nullptr);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void setTeam(std::vector<teamMember>& member);

	void addMember(teamMember& member);

private:
	std::vector<teamMember>team;
	service& teamService;

};

class issuesModel :public QAbstractListModel
{
	Q_OBJECT
signals:
	void issuesModified();
public:
	issuesModel(service& issuesService, QObject* parent = nullptr);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	std::vector<Issue> getAll();
	void setIssue(std::vector<Issue>& issue);
	bool addIssue(Issue& issue);
	Issue getIssue(int index);
	//bool updateIssue(Issue& issue, std::string solver);
	bool resolveIssue(Issue& issue, std::string solver);
	bool removeIssue(Issue& issue);

private:
	std::vector<Issue> issues;
	service& issuesService;

};
