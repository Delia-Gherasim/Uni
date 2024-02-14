#pragma once
#include <string>

class Tutorials {
private:
    std::string title;
    std::string presenter;
    std::string link;
    int durationMinutes;
    int durationSeconds;
    int numberOfLikes;

public:
    Tutorials();
    ~Tutorials();
    Tutorials(const std::string& _title, const std::string& _presenter, const std::string& _link, int _durationMinutes, int _durationSeconds, int _numberOfLikes);

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
    void setDurationSeconds(int durationSeconds);
    void setNumberOfLikes(int numberOfLikes);

    bool operator==(const Tutorials& other) const;

};