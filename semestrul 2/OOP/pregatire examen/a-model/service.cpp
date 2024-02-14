#include "service.h"
#include <qtmetamacros.h>
#include "model.h"
service::service(repository& repo) : repo{ repo }
{

}
bool service::addIssue(Issue& issue)
{
    if (this->repo.findIssue(issue) == true)
        return false;
    else
    {
        return this->repo.addIssue(issue);
    }
}

bool service::addTeamMember(teamMember& member)
{
    if (this->repo.findTeamMember(member) == true)
        return false;
    else
        return this->repo.addTeamMember(member);
}

bool service::removeIssue(Issue& issue)
{
    if (this->repo.findIssue(issue) == false)
        return false;
    else
        return this->repo.removeIssue(issue);
}

bool service::resolveIssue(Issue& issue, std::string solver)
{
    if (this->repo.findIssue(issue) == false)
        return false;
    else
        return this->repo.resolveIssue(issue, solver);
}

std::vector<teamMember> service::getAllTeam()
{
    return this->repo.getAllTeams();
}

std::vector<Issue> service::getAllIssues()
{
    return this->repo.getAllIsues();
}

int service::getTeamSize()
{
    return this->repo.getAllTeams().size();
}

int service::getIssuesSize()
{
    return this->repo.getAllIsues().size();
}