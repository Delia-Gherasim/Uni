#pragma once
#include <vector>
#include "team.h"

class repository
{
private:
	std::vector<teamMember> teams;
	std::vector<Issue> issues;

public:
	//repository(teamMember& teams, Issue& issues);
	bool findTeamMember(teamMember& member);
	bool addTeamMember(teamMember& member);

	bool findIssue(Issue& issue);
	bool addIssue(Issue& newIssue);
	bool removeIssue(Issue& issue);
	bool resolveIssue(Issue& issue, std::string& solver);

	bool compareIssues(Issue& issue1, Issue& issue2);

	std::vector<Issue> sortAllIssues();
	std::vector<teamMember> getAllTeams();
	std::vector<Issue> getAllIsues();

};
