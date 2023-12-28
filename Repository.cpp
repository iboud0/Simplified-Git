#include "includes/Repository.h"
#include "includes/File.h"
#include <fstream>
#include <iostream>

using namespace std;

Repository::Repository(const string& repoPath) : repoPath(repoPath) {
    gitFolderPath = repoPath + "/git";
    logFilePath = gitFolderPath + "/log";
    filesPath = gitFolderPath + "/files";

    loadCommittedFiles();
}

void Repository::add(const string& fileName) {
    if (ifstream(repoPath + "/" + fileName)) {
        auto it = committedFiles.find(fileName);

        if (it == committedFiles.end()) {
            committedFiles[fileName] = NULL;
            cout << "Added: " << fileName << endl;
        } else {
            cout << "File already added to the repository: " << fileName << endl;
        }
    } else {
        cout << "File does not exist in the repository. Cannot add." << endl;
    }
}

void Repository::commit(const string& fileName) {
    if (ifstream(repoPath + "/" + fileName)) {
        auto it = committedFiles.find(fileName);

        if (it != committedFiles.end()) {
            File file(repoPath + "/" + fileName);
            file.calculateHash();
            size_t currentHash = file.getHash();

            if (currentHash != it->second || it->second == NULL) { // TODO: comparison between int and null???
                committedFiles[fileName] = currentHash;
                saveCommittedFiles();
                cout << "Committed changes for file: " << fileName << endl;
            } else {
                cout << "No changes to commit for file: " << fileName << endl;
            }
        } else {
            cout << "File not found in committed files. Add the file first." << endl;
        }
    } else {
        cout << "File does not exist in the repository. Cannot commit." << endl;
    }
}

void Repository::log() const {
    ifstream logFile(logFilePath);
    string operation;

    cout << "Repository Log:" << endl;
    while (logFile >> operation) {
        cout << operation << endl;
    }
    cout << "-------------------" << endl;

    logFile.close();
}

void Repository::loadCommittedFiles() {
    ifstream filesFile(filesPath);
    string fileName;
    size_t hash;

    // TODO: first clear committedfiles map?
    while (filesFile >> fileName >> hash) {
        committedFiles[fileName] = hash;
    }
}

<<<<<<< HEAD
void Repository::saveCommittedFiles() const {
    std::ofstream filesFile(filesPath);
    
    for (const auto& entry : committedFiles) {
        filesFile << entry.first << " " << entry.second << std::endl;
=======
// TODO: handle exceptions (try catch) everywhere

void Repository::saveCommittedFiles() const {
    overwriteFilesFile();

    ofstream logFile(logFilePath, ios::app);
    logFile << "add" << endl;

    logFile.close();
}
void Repository::overwriteFilesFile() const {
    ofstream filesFile(filesPath, ios::trunc);

    if (!filesFile.is_open()) {
        cerr << "Error opening file for overwriting: " << filesPath << endl;
        return;
>>>>>>> e2c854df1b21d6ae84bce06feba13917120611b1
    }

    for (const auto& entry : committedFiles) {
        if (entry.second != NULL) {
            filesFile << entry.first << " " << entry.second << endl;
        }
    }

    filesFile.close();
}

void Repository::Status() const {
    cout << "Repository Status:" << endl;
    
    for (const auto& entry : committedFiles) {
        string filePath = repoPath + "/" + entry.first;
        if (ifstream(filePath)) {
            File file(filePath);
//            file.calculateHash();
            size_t currentHash = file.getHash();

            if (entry.second != currentHash) {
                cout << entry.first << " has been modified." << endl;
            } else {
                cout << entry.first << " is up to date." << endl;
            }
        } else {
            cout << entry.first << " does not exist." << endl;
        }
    }

    cout << "-------------------" << endl;
}

