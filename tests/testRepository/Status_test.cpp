#include "../../includes/Repository.h"
#include <iostream>
#include <fstream>

void createTestFile(const std::string& filePath, const std::string& content) {
    std::ofstream testFile(filePath);
    testFile << content;
    testFile.close();
}

void modifyTestFile(const std::string& filePath, const std::string& content) {
    std::ofstream testFile(filePath, std::ios::app);
    testFile << content;
    testFile.close();
}

void testGitStatus() {
    std::string repoPath = "repositoryTest";
    Repository repo(repoPath);

    std::string testFileName = "testStatusFile.txt";

    // Create and add initial file
    createTestFile(repoPath + "/" + testFileName, "Initial content");
    repo.add(testFileName);
    repo.commit(testFileName);

    // Check status after initial commit
    std::cout << "Checking status after initial commit:" << std::endl;
    repo.Status();

    // Modify the file
    modifyTestFile(repoPath + "/" + testFileName, "\nModified content");

    // Check status after modification
    std::cout << "Checking status after modification:" << std::endl;
    repo.Status();

    // Commit the modified file
    repo.commit(testFileName);

    // Check status after second commit
    std::cout << "Checking status after second commit:" << std::endl;
    repo.Status();

    // Clean up: Uncomment these lines if you want to remove test file and clear logs
    // remove((repoPath + "/" + testFileName).c_str());
    // clearFiles(repoPath + "/git/log", repoPath + "/git/files");
}

int main() {
    testGitStatus();
    return 0;
}
