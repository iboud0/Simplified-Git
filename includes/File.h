#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
    File(const std::string& name);

    const std::string& getName() const;
    const std::string& getContent() const;
    size_t getHash() const;

    void readContent();
    void calculateHash();

private:
    std::string name;
    std::string content;
    size_t hash;
};

#endif // FILE_H
