#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <map>
#include <optional>

using namespace std;

class Repository {
public:
    Repository(const string& repoPath);

    void add(const string& fileName);
    void commit(const string& fileName);
    void log() const;
    void Status() const;


private:
    string repoPath;
    string gitFolderPath;
    string logFilePath;
    string filesPath;

    map<string, std::optional<size_t>> committedFiles;

    void loadCommittedFiles();
    void saveCommittedFiles() const;
    void overwriteFilesFile() const;
};

#endif // REPOSITORY_H
