#include "includes/Git.h"

Git::Git(Repository& repo) : repository(repo) {}

void Git::add(const std::string& fileName, const std::string& content) {
    repository.addFile(fileName, content);
}

void Git::commit(const std::string& message) {
    repository.commit(message); // TODO: commit message or filename?!
}

void Git::displayLog() const {
    repository.displayLog();
}
