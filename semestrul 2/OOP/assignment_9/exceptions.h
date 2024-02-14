#pragma once

#include <exception>
#include <string>

class RepositoryException : public std::exception {
public:
    RepositoryException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

class DuplicateTutorialException : public RepositoryException {
public:
    DuplicateTutorialException() : RepositoryException("tutorial already exists") {}
};

class TutorialNotFoundException : public RepositoryException {
public:
    TutorialNotFoundException() : RepositoryException("tutorial not found") {}
};
