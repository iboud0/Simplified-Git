#ifndef FILE_H
#define FILE_H

#include <string>
#include <optional>

class File {
public:
    File(const std::string& name);

    const std::string& getName() const;
    const std::string& getContent() const;
    std::optional<size_t> getHash() const;  // Updated return type

    void readContent();
    void calculateHash();

private:
    std::string name;
    std::string content;
    std::optional<size_t> hash;
};

#endif // FILE_H
