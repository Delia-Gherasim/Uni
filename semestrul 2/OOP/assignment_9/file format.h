#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "tutorials.h"


class FileFormat {
public:
    virtual void write(const std::vector<Tutorials>& tutorials) = 0;
    void set_filename(const std::string& filename) {
        filename_ = filename;
    }
protected:
    std::string filename_;
};

class CSV : public FileFormat {
public:
    void write(const std::vector<Tutorials>& tutorials) override;
};

class HTML : public FileFormat {
public:
    void write(const std::vector<Tutorials>& tutorials) override;
};

class TXT : public FileFormat {
public:
    void write(const std::vector<Tutorials>& tutorials) override;
};
