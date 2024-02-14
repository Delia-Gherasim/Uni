#pragma once
#include <string>

class Tutorials
{
private:
    std::string title;
    std::string presenter;
    std::string link;
    int durationMinutes;
    int durationSeconds;
    int numberOfLikes;

public:
    Tutorials();
    Tutorials(const std::string& title, const std::string& presenter, const std::string& link, int durationMinutes, int durationSeconds, int numberOfLikes);

    std::string getTitle() const;
    std::string getPresenter() const;
    std::string getLink() const;
    int getDurationMinutes() const;
    int getDurationSeconds() const;
    int getNumberOfLikes() const;

    void setTitle(const std::string& title);
    void setPresenter(const std::string& presenter);
    void setLink(const std::string& link);
    void setDurationMinutes(int durationMinutes);
    void setDurationSeconds(int durationSEconds);
    void setNumberOfLikes(int numberOfLikes);
};