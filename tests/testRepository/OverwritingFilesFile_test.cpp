#include "../../includes/Repository.h"
#include <iostream>
#include <fstream>
#include <vector>

void createTestFiles(const std::string& repoPath) {
    const std::vector<std::string> fileNames = {"file1.txt", "file2.txt", "file3.txt"};
    for (const auto& fileName : fileNames) {
        std::ofstream testFile(repoPath + "/" + fileName);
        testFile << "Initial content for " << fileName;
        testFile.close();
    }
}

void modifyTestFiles(const std::string& repoPath) {
    const std::vector<std::string> fileNames = {"file1.txt", "file2.txt"};
    for (const auto& fileName : fileNames) {
        std::ofstream testFile(repoPath + "/" + fileName, std::ios::app);
        testFile << "\nModified content for " << fileName;
        testFile.close();
    }
}

void displayFileContents(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void testOverwriteFilesFile() {
    std::string repoPath = "repositoryTest";
    Repository repo(repoPath);

    // Create and add initial files
    createTestFiles(repoPath);
    repo.add("file1.txt");
    repo.add("file2.txt");
    repo.add("file3.txt");

    // Commit the initial files
    repo.commit("file1.txt");
    repo.commit("file2.txt");
    repo.commit("file3.txt");

    // Display initial file contents
    std::cout << "Initial files content:" << std::endl;
    displayFileContents(repoPath + "/git/files");

    // Modify and commit the changes
    modifyTestFiles(repoPath);
    repo.commit("file1.txt");
    repo.commit("file2.txt");
    repo.commit("file3.txt");

    // Display modified file contents
    std::cout << "Modified files content:" << std::endl;
    displayFileContents(repoPath + "/git/files");
}

int main() {
    testOverwriteFilesFile();

    return 0;
}
