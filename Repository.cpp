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
            committedFiles[fileName] = '#';
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

            if (currentHash != it->second || it->second == '#') {
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
    
    for (const auto& entry : committedFiles) {
        filesFile << entry.first << " " << entry.second << std::endl;
    }

    std::ofstream logFile(logFilePath, std::ios::app);
    logFile << "add" << std::endl;
}
