#pragma once
#include <string>
#include <iostream>
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

    friend std::ostream& operator<<(std::ostream& os, const Tutorials& tutorial)
    {
        os << tutorial.title << std::endl
            << tutorial.presenter << std::endl
            << tutorial.link << std::endl
            << tutorial.durationMinutes << std::endl
            << tutorial.durationSeconds << std::endl
            << tutorial.numberOfLikes << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Tutorials& tutorial)
    {
        std::getline(is >> std::ws, tutorial.title);
        std::getline(is >> std::ws, tutorial.presenter);
        std::getline(is >> std::ws, tutorial.link);
        is >> tutorial.durationMinutes >> tutorial.durationSeconds >> tutorial.numberOfLikes;
        return is;
    }

};

