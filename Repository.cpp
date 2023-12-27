#include "Repository.h"
#include <iostream>
#include <fstream>

Repository::Repository(const std::string& logFilePath) : logFilePath(logFilePath) {
    readLog(); // Read existing log if available
}

Repository::~Repository() {
    writeLog(); // Save log to disk on destruction
}

void Repository::addFile(const std::string& fileName, const std::string& content) {
    files.emplace_back(fileName, content);
    log("Added file: " + fileName);
}

void Repository::commit(const std::string& message) {
    // In a real-world scenario, you would perform actual commit actions here.
    // For simplicity, we log the commit message.
    log("Committed: " + message);
}

void Repository::displayLog() const {
    std::cout << "Commit Log:\n";
    for (const auto& entry : logEntries) {
        std::cout << "- " << entry << "\n";
    }
    std::cout << std::endl;
}

void Repository::log(const std::string& entry) {
    logEntries.push_back(entry);
}

void Repository::readLog() {
    std::ifstream logFile(logFilePath);
    std::string entry;
    while (std::getline(logFile, entry)) {
        logEntries.push_back(entry);
    }
}

void Repository::writeLog() const {
    std::ofstream logFile(logFilePath, std::ios::app);
    for (const auto& entry : logEntries) {
        logFile << entry << "\n";
    }
}
