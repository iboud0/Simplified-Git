#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <map>

class Repository {
public:
    Repository(const std::string& repoPath);

    void add(const std::string& fileName);
    void commit(const std::string& fileName);
    void log() const;
    void Status() const;


private:
    std::string repoPath;
    std::string gitFolderPath;
    std::string logFilePath;
    std::string filesPath;

    std::map<std::string, size_t> committedFiles;

    void loadCommittedFiles();
    void saveCommittedFiles() const;
    void overwriteFilesFile() const;
};

#endif // REPOSITORY_H
