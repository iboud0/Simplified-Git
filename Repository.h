#pragma once

#include <vector>
#include <string>
#include "File.h"

class Repository {
public:
    Repository(const std::string& logFilePath);

    ~Repository();

    void addFile(const std::string& fileName, const std::string& content);

    void commit(const std::string& message);

    void displayLog() const;

private:
    std::vector<File> files;
    std::vector<std::string> logEntries;
    std::string logFilePath;

    void log(const std::string& entry);

    void readLog();

    void writeLog() const;
};