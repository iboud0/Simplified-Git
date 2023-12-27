#include "Repository.h"
#include "Git.h"

int main() {
    // Specify the file path where the log should be stored
    const std::string logFilePath = "git_log.txt";

    Repository myRepo(logFilePath);
    Git myGit(myRepo);

    myGit.add("file1.txt", "Content of file 1");
    myGit.add("file2.txt", "Content of file 2");

    myGit.commit("Initial commit");
    myGit.displayLog();

    myGit.add("file3.txt", "Content of file 3");
    myGit.commit("Add file3.txt");
    myGit.displayLog();

    return 0;
}
