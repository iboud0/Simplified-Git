#include "includes/File.h"
#include <fstream>
#include <functional>

using namespace std;

File::File(const string& name) : name(name) {
    readContent();
    calculateHash();
}

const string& File::getName() const {
    return name;
}

const string& File::getContent() const {
    return content;
}

size_t File::getHash() const {
    return hash;
}

void File::readContent() {
    ifstream file(name);
    content.assign((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    file.close();
}

void File::calculateHash() {
    hash<string> hasher;
    hash = hasher(content);
}
