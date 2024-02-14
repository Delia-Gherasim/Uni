#pragma once
#include "repository.h"
class service
{
private:
	repository& repo;

public:
	service(repository& repo);

	bool addIssue(Issue& issue);
	bool addTeamMember(teamMember& member);
	bool removeIssue(Issue& issue);
	bool resolveIssue(Issue& issue, std::string solver);
	std::vector<teamMember> getAllTeam();
	std::vector<Issue> getAllIssues();
	int getTeamSize();
	int getIssuesSize();
};

