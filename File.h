#pragma once

#include <string>

class File {
public:
    File(const std::string& name, const std::string& content);

    const std::string& getName() const;
    const std::string& getContent() const;

private:
    std::string name;
    std::string content;
};
