#pragma once

#include "Repository.h"

class Git {
public:
    Git(Repository& repo);

    void add(const std::string& fileName, const std::string& content);

    void commit(const std::string& message);

    void displayLog() const;

private:
    Repository& repository;
};
