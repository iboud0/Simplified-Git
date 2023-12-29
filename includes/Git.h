#ifndef GIT_H
#define GIT_H

#include <iostream>
#include <string>
#include "Repository.h"

class Git {
public:
    enum class Command {
        Init,
        Add,
        Commit,
        Status,
        Exit,
        Unknown
    };

    Git(const std::string& repoPath);

    void repl();

private:
    Repository repository;

    Command parseCommand(const std::string& input);

    void handleAdd();

    void handleCommit();
};

#endif
