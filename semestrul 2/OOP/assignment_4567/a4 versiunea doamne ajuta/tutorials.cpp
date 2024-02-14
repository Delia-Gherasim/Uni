#include "tutorials.h"

Tutorials::Tutorials() :title{ "" }, presenter{ "" }, link{ "" }, durationMinutes{ 0 }, durationSeconds{ 0 }, numberOfLikes{ 0 }
{

}
Tutorials::Tutorials(const std::string& _title, const std::string& _presenter, const std::string& _link, int _durationMinutes, int _durationSeconds, int _numberOfLikes) : title{ _title },
presenter{ _presenter },
link{ _link },
durationMinutes{ _durationMinutes },
durationSeconds{ _durationSeconds },
numberOfLikes{ _numberOfLikes }
{
}
std::string Tutorials::getTitle()const
{
    return this->title;
}
std::string Tutorials::getPresenter()const
{
    return this->presenter;
}
std::string Tutorials::getLink() const
{
    return this->link;
}
int Tutorials::getDurationMinutes() const
{
    return this->durationMinutes;
}
int Tutorials::getDurationSeconds()const
{
    return this->durationSeconds;
}
int Tutorials::getNumberOfLikes() const
{
    return this->numberOfLikes;
}


void Tutorials::setTitle(const std::string& title)
{
    this->title = title;
}
void Tutorials::setPresenter(const std::string& presenter)
{
    this->presenter = presenter;
}
void Tutorials::setLink(const std::string& link)
{
    this->link = link;
}
void Tutorials::setDurationMinutes(int durationMinutes)
{
    this->durationMinutes = durationMinutes;
}
void Tutorials::setDurationSeconds(int durationSeconds)
{
    this->durationSeconds = durationSeconds;
}
void Tutorials::setNumberOfLikes(int numberOfLikes)
{
    this->numberOfLikes = numberOfLikes;
}