#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <map>
#include <optional>

enum class Operation {
    Add,
    Commit
};

class Repository {
public:
    Repository(const std::string& repoPath);

    void add(const std::string& fileName);
    void commit(const std::string& fileName);
    void log(Operation operation, const std::string& message) const;
    void Status() const;


private:
    std::string repoPath;
    std::string gitFolderPath;
    std::string logFilePath;
    std::string filesPath;

    std::map<std::string, std::optional<size_t>> committedFiles;

    void loadCommittedFiles();
    void saveCommittedFiles() const;
    void overwriteFilesFile() const;
};

#endif // REPOSITORY_H
