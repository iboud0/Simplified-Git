#include "includes/File.h"
#include <iostream>
#include <fstream>
#include <string>
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

std::optional<size_t> File::getHash() const {
    return hash;
}

void File::readContent() {
    std::ifstream file(name);
    
    if (file.is_open()) {
        content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
    } else {
        std::cerr << "Error opening file: " << name << std::endl;
    }
}

void File::calculateHash() {
    std::hash<std::string> hasher;
    hash = hasher(content);
}
