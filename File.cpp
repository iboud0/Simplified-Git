#include "includes/File.h"
#include <fstream>
#include <functional>

File::File(const std::string& name) : name(name) {
    readContent();
    calculateHash();
}

const std::string& File::getName() const {
    return name;
}

const std::string& File::getContent() const {
    return content;
}

size_t File::getHash() const {
    return hash;
}

void File::readContent() {
    std::ifstream file(name);
    content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void File::calculateHash() {
    std::hash<std::string> hasher;
    hash = hasher(content);
}
