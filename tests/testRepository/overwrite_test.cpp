// void testOverwriteFilesFile() {
//     std::string repoPath = "repositoryTest";
//     Repository repo(repoPath);

//     std::string testFileName = "testFile.txt";

//     // Create the test file with initial content
//     createTestFile(repoPath + "/" + testFileName);

//     // Add and commit the file
//     repo.add(testFileName);
//     repo.commit(testFileName);

//     // Modify the file
//     std::ofstream testFile(repoPath + "/" + testFileName, std::ios::app);
//     testFile << "\nModified content.";
//     testFile.close();

//     // Commit the modified file
//     repo.commit(testFileName);

//     // Clean up
//     // remove((repoPath + "/" + testFileName).c_str());
//     // clearFiles(repoPath + "/git/log", repoPath + "/git/files");
// }



// int main() {
//     testOverwriteFilesFile();
//     return 0;
// }


// #include "../../includes/Repository.h"
// #include <iostream>
// #include <fstream>

// void createTestFiles(const std::string& repoPath) {
//     const std::string fileNames[] = {"file1.txt", "file2.txt", "file3.txt"};
//     for (const auto& fileName : fileNames) {
//         std::ofstream testFile(repoPath + "/" + fileName);
//         testFile << "Initial content for " << fileName;
//         testFile.close();
//     }
// }

// void modifyTestFiles(const std::string& repoPath) {
//     const std::string fileNames[] = {"file1.txt", "file2.txt", "file3.txt"};
//     for (const auto& fileName : fileNames) {
//         std::ofstream testFile(repoPath + "/" + fileName, std::ios::app);
//         testFile << "\nModified content for " << fileName;
//         testFile.close();
//     }
// }

// void testOverwriteFilesFile() {
//     std::string repoPath = "repositoryTest";
//     Repository repo(repoPath);

//     // Create and add initial files
//     createTestFiles(repoPath);
//     repo.add("file1.txt");
//     repo.add("file2.txt");
//     repo.add("file3.txt");

//     // Commit the initial files
//     repo.commit("file1.txt");
//     repo.commit("file2.txt");
//     repo.commit("file3.txt");

//     // Modify and commit the changes
//     modifyTestFiles(repoPath);
//     repo.commit("file1.txt");
//     repo.commit("file2.txt");
//     repo.commit("file3.txt");

//     // Here you should verify the content of the files file to ensure it is correct
//     // This might involve reading the file and verifying its contents.

//     // Clean up: Uncomment these lines if you want to remove test files and clear logs
//     // clearFiles(repoPath + "/git/log", repoPath + "/git/files");
// }

// int main() {
//     testOverwriteFilesFile();
//     return 0;
// }
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
    const std::vector<std::string> fileNames = {"file1.txt", "file2.txt", "file3.txt"};
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
    std::cout << "Initial file contents:" << std::endl;
    displayFileContents(repoPath + "/file1.txt");
    displayFileContents(repoPath + "/file2.txt");
    displayFileContents(repoPath + "/file3.txt");

    // Modify and commit the changes
    modifyTestFiles(repoPath);
    repo.commit("file1.txt");
    repo.commit("file2.txt");
    repo.commit("file3.txt");

    // Display modified file contents
    std::cout << "Modified file contents:" << std::endl;
    displayFileContents(repoPath + "/file1.txt");
    displayFileContents(repoPath + "/file2.txt");
    displayFileContents(repoPath + "/file3.txt");

    // Here you should verify the content of the files file to ensure it is correct
    // This might involve reading the file and verifying its contents.

    // Clean up: Uncomment these lines if you want to remove test files and clear logs
    // clearFiles(repoPath + "/git/log", repoPath + "/git/files");
}

int main() {
    testOverwriteFilesFile();
    return 0;
}
