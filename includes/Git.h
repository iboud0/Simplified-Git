#pragma once

#include "Repository.h"

using namespace std;

class Git {
public:
    Git(Repository& repo);

    void add(const string& fileName, const string& content);

    void commit(const string& message);

    void displayLog() const;

private:
    Repository& repository;
};
