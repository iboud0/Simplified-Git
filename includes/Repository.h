#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <map>
#include <optional>
#include <vector>

enum class Operation {
    Init,
    Add,
    Commit,
    Status
};

class Repository {
public:
    Repository(const std::string& repoPath);

    int init();
    std::string add(const std::string& fileName);
    std::string commit(const std::string& fileName, const std::string& message);
    void log(Operation operation, const std::string& message) const;
    std::vector<std::string> status() const;


private:
    std::string repoPath;
    std::string gitFolderPath;
    std::string logFilePath;
    std::string filesPath;

    std::map<std::string, std::optional<size_t>> committedFiles;

    void loadCommittedFiles();
    void saveCommittedFiles(const std::string& message) const;
    void overwriteFilesFile() const;
};

#endif // REPOSITORY_H
