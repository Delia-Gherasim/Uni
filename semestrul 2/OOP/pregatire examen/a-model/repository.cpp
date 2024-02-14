#include "repository.h"
#include <algorithm>

bool repository::findTeamMember(teamMember& member)
{
	for (int i = 0; i < this->teams.size(); i++)
	{
		if (this->teams[i].getName() == member.getName() && this->teams[i].getType() == member.getType())
			return true;
	}

	return false;
}

bool repository::addTeamMember(teamMember& member)
{
	this->teams.push_back(member);
	return true;
}

bool repository::findIssue(Issue& issue)
{
	for (int i = 0; i < this->issues.size(); i++)
	{
		if (this->issues[i].getDescription() == issue.getDescription() && this->issues[i].getReporter() == issue.getReporter())
			return true;
	}

	return false;
}

bool repository::addIssue(Issue& newIssue)
{
	 this->issues.push_back(newIssue);
	 return true;
}

bool repository::removeIssue(Issue& issue)
{
	auto iterator_value = std::find(this->issues.begin(), this->issues.end(), issue);
	if (iterator_value != this->issues.end()) {
		this->issues.erase(iterator_value);
		return true;
	}
	return false;
}

bool repository::resolveIssue(Issue& issue, std::string& solver)
{
	for (int i = 0; i < this->issues.size(); i++)
	{
		if (this->issues[i].getDescription() == issue.getDescription() && this->issues[i].getReporter() == issue.getReporter())
		{
			this->issues[i].setStatus("closed");
			this->issues[i].setSolver(solver);
			return true;
		}
	}
	return false;
}
bool repository::compareIssues(Issue& issue1, Issue& issue2) {
	if (issue1.getStatus() < issue2.getStatus())
		return true;
	if (issue1.getStatus() > issue2.getStatus())
		return false;

	return issue1.getDescription() < issue2.getDescription();
}

std::vector<Issue> repository::sortAllIssues()
{
	std::sort(issues.begin(), issues.end(), []( Issue& issue1, Issue& issue2) {
		if (issue1.getStatus() < issue2.getStatus())
			return true;
		if (issue1.getStatus() > issue2.getStatus())
			return false;
		return issue1.getDescription() < issue2.getDescription();
		});

	return issues;
}

std::vector<teamMember> repository::getAllTeams()
{
	return this->teams;
}

std::vector<Issue> repository::getAllIsues()
{
	return this->sortAllIssues();
}