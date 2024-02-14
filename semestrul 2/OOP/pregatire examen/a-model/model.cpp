#include "model.h"

teamModel::teamModel(service& teamService, QObject* parent) : teamService{ teamService }
{
}

int teamModel::rowCount(const QModelIndex& parent) const
{
	return this->teamService.getTeamSize();
}

QVariant teamModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	teamMember& t = this->teamService.getAllTeam()[row];
	if (role == Qt::DisplayRole)
		return QString::fromStdString(t.toString());

	return QVariant();
}

void teamModel::setTeam(std::vector<teamMember>& member)
{/*
	beginResetModel();
	for (auto& m : team) {
		this->teamService.addTeamMember(m);
	}
	endResetModel();*/

	beginResetModel();
	team = member;
	endResetModel();
}

void teamModel::addMember(teamMember& member)
{
	int n = this->teamService.getTeamSize();
	this->beginInsertRows(QModelIndex{}, n, n);
	this->teamService.addTeamMember(member);
	this->endInsertRows();
}

///////////////////////////////////////////////////

issuesModel::issuesModel(service& issuesService, QObject* parent) : issuesService{ issuesService }
{

}

int issuesModel::rowCount(const QModelIndex& parent) const
{
	return this->issuesService.getIssuesSize();
}

QVariant issuesModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	Issue i = this->issuesService.getAllIssues()[row];
	if (role == Qt::DisplayRole)
		return QString::fromStdString(i.toString());

	return QVariant();
}

std::vector<Issue> issuesModel::getAll()
{
	return issuesService.getAllIssues();
}

void issuesModel::setIssue(std::vector<Issue>& issue)
{
	beginResetModel();
	//this->issuesService.clearissues(); 
	for (auto& i : issue) {
		this->issuesService.addIssue(i);
	}
	endResetModel();
}

bool issuesModel::addIssue(Issue& issue)
{
	int n = this->issuesService.getIssuesSize();
	this->beginInsertRows(QModelIndex{}, n, n);
	bool result = this->issuesService.addIssue(issue);
	this->endInsertRows();
	return result;
}

Issue issuesModel::getIssue(int index)
{
	return this->issuesService.getAllIssues()[index];
}

bool issuesModel::resolveIssue(Issue& issue, std::string solver)
{
	return this->issuesService.resolveIssue(issue, solver);
}

bool issuesModel::removeIssue(Issue& issue)
{
	return this->issuesService.removeIssue(issue);
}