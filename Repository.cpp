#include "includes/Repository.h"
#include "includes/File.h"
#include <fstream>
#include <iostream>

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
            committedFiles[fileName] = NULL;
            std::cout << "Added: " << fileName << std::endl;
        } else {
            std::cout << "File already added to the repository: " << fileName << std::endl;
        }
    } else {
        std::cout << "File does not exist in the repository. Cannot add." << std::endl;
    }
}

void Repository::commit(const std::string& fileName) {
    if (std::ifstream(repoPath + "/" + fileName)) {
        auto it = committedFiles.find(fileName);

        if (it != committedFiles.end()) {
            File file(repoPath + "/" + fileName);
            file.calculateHash();
            size_t currentHash = file.getHash();

            if (currentHash != it->second || it->second == NULL) {
                committedFiles[fileName] = currentHash;
                saveCommittedFiles();
                std::cout << "Committed changes for file: " << fileName << std::endl;
            } else {
                std::cout << "No changes to commit for file: " << fileName << std::endl;
            }
        } else {
            std::cout << "File not found in committed files. Add the file first." << std::endl;
        }
    } else {
        std::cout << "File does not exist in the repository. Cannot commit." << std::endl;
    }
}

void Repository::log() const {
    std::ifstream logFile(logFilePath);
    std::string operation;

    std::cout << "Repository Log:" << std::endl;
    while (logFile >> operation) {
        std::cout << operation << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

void Repository::loadCommittedFiles() {
    std::ifstream filesFile(filesPath);
    std::string fileName;
    size_t hash;

    while (filesFile >> fileName >> hash) {
        committedFiles[fileName] = hash;
    }
}

void Repository::saveCommittedFiles() const {
    std::ofstream filesFile(filesPath);

    overwriteFilesFile();

    std::ofstream logFile(logFilePath, std::ios::app);
    logFile << "add" << std::endl;
}
void Repository::overwriteFilesFile() const {
    std::ofstream filesFile(filesPath, std::ios::trunc);

    if (!filesFile.is_open()) {
        std::cerr << "Error opening file for overwriting: " << filesPath << std::endl;
        return;
    }

    for (const auto& entry : committedFiles) {
        if (entry.second != NULL) {
            filesFile << entry.first << " " << entry.second << std::endl;
        }
    }
}

void Repository::Status() const {
    std::cout << "Repository Status:" << std::endl;
    
    for (const auto& entry : committedFiles) {
        std::string filePath = repoPath + "/" + entry.first;
        if (std::ifstream(filePath)) {
            File file(filePath);
            file.calculateHash();
            size_t currentHash = file.getHash();

            if (entry.second != currentHash) {
                std::cout << entry.first << " has been modified." << std::endl;
            } else {
                std::cout << entry.first << " is up to date." << std::endl;
            }
        } else {
            std::cout << entry.first << " does not exist." << std::endl;
        }
    }

    std::cout << "-------------------" << std::endl;
}

