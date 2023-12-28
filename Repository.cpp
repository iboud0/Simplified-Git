#include "includes/Repository.h"
#include "includes/File.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

Repository::Repository(const std::string& repoPath) : repoPath(repoPath) {
    gitFolderPath = repoPath + "/git";
    logFilePath = gitFolderPath + "/log";
    filesPath = gitFolderPath + "/files";

    loadCommittedFiles();
}

void Repository::add(const std::string& fileName) {
    if (std::ifstream(repoPath + "/" + fileName)) {
        auto it = committedFiles.find(fileName);

        if (it == committedFiles.end()) {
            committedFiles[fileName] = std::nullopt;
            log(Operation::Add, "File added successfully");
            std::cout << "Added: " << fileName << std::endl;
        } else {
            log(Operation::Add, "File already added to the repository");
            std::cout << "File already added to the repository: " << fileName << std::endl;
        }
    } else {
        log(Operation::Add, "File does not exist in the repository");
        std::cout << "File does not exist in the repository. Cannot add." << std::endl;
    }
}

void Repository::commit(const std::string& fileName) {
    if (std::ifstream(repoPath + "/" + fileName)) {
        auto it = committedFiles.find(fileName);

        if (it != committedFiles.end()) {
            File file(repoPath + "/" + fileName);
            file.calculateHash();
            std::optional<size_t> currentHash = file.getHash();

            if (!it->second.has_value() || currentHash != it->second.value()) {
                committedFiles[fileName] = currentHash;
                saveCommittedFiles();
                std::cout << "Committed changes for file: " << fileName << std::endl;
            } else {
                log(Operation::Commit, "No changes to commit for file");
                std::cout << "No changes to commit for file: " << fileName << std::endl;
            }
        } else {
            log(Operation::Commit, "File not found in committed files");
            std::cout << "File not found in committed files. Add the file first." << std::endl;
        }
    } else {
        log(Operation::Commit, "File does not exist in the repository");
        std::cout << "File does not exist in the repository. Cannot commit." << std::endl;
    }
}


void Repository::log(Operation operation, const std::string& message) const {
    std::ofstream logFile(logFilePath, std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Error opening log file: " << logFilePath << std::endl;
        return;
    }

    std::string operationStr;
    switch (operation) {
        case Operation::Add:
            operationStr = "Add";
            break;
        case Operation::Commit:
            operationStr = "Commit";
            break;
    }

    logFile << operationStr << ": " << message << std::endl;
    logFile << "--------------------------------" << std::endl;

    logFile.close();
}

void Repository::loadCommittedFiles() {
    std::ifstream filesFile(filesPath);
    std::string fileName;
    size_t hash;

    while (filesFile >> fileName >> hash) {
        committedFiles[fileName] = hash;
    }
}

void Repository::overwriteFilesFile() const {
    std::ofstream filesFile(filesPath, std::ios::trunc);

    if (!filesFile.is_open()) {
        std::cerr << "Error opening file for overwriting: " << filesPath << std::endl;
        return;
    }

    for (const auto& entry : committedFiles) {
        if (entry.second.has_value()) {
            filesFile << entry.first << " " << entry.second.value() << std::endl;
        }
    }

    filesFile.close();
}

void Repository::saveCommittedFiles() const {
    overwriteFilesFile();
    log(Operation::Commit, "Changes committed successfully");
}



void Repository::Status() const {

    std::cout << "Repository Status:" << std::endl;

    // Check for untracked, modified, and up-to-date files
    for (const auto& file : fs::directory_iterator(repoPath)) {
        std::string fileName = file.path().filename().string();
        auto it = committedFiles.find(fileName);

        if (it == committedFiles.end()) {
            // Untracked file
            std::cout << fileName << " is untracked." << std::endl;
        } else {
            File file(repoPath + "/" + fileName);
            auto currentHash = file.getHash();

            if (!it->second.has_value()) {
                // File added but not committed yet
                std::cout << fileName << " added but not committed." << std::endl;
            } else if (currentHash != it->second.value()) {
                // Modified file
                std::cout << fileName << " has been modified." << std::endl;
            } else {
                // Up-to-date file
                std::cout << fileName << " is up to date." << std::endl;
            }
        }
    }

    std::cout << "-------------------" << std::endl;
}
