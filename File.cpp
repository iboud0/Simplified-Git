#include "File.h"

File::File(const std::string& n, const std::string& c) : name(n), content(c) {}

const std::string& File::getName() const {
    return name;
}

const std::string& File::getContent() const {
    return content;
}
