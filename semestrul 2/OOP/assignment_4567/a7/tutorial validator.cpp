#include "tutorial validator.h"

bool TutorialValidator::validate(const Tutorials& tutorial) const
{
    if (tutorial.getTitle().empty()) {
        return false;
    }
    if (tutorial.getPresenter().empty()) {
        return false;
    }
    if (tutorial.getLink().empty()) {
        return false;
    }
    if (tutorial.getDurationMinutes() < 0) {
        return false;
    }
    if (tutorial.getDurationSeconds() < 0 || tutorial.getDurationSeconds() >= 60) {
        return false;
    }
    if (tutorial.getNumberOfLikes() < 0) {
        return false;
    }
    return true;
}