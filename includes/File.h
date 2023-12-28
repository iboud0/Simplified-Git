#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File {
public:
    File(const string& name);

    const string& getName() const;
    const string& getContent() const;
    size_t getHash() const;

    void readContent();
    void calculateHash();

private:
    string name;
    string content;
    size_t hash;
};

#endif // FILE_H
