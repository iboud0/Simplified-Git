cmake_minimum_required(VERSION 3.26)
project(Simplified_Git)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

add_executable(Simplified_Git
        includes/File.h
        includes/Git.h
        includes/Repository.h
        tests/testFile/File_test.cpp
        tests/testRepository/overwrite_test.cpp
        tests/testRepository/Repository_test.cpp
        tests/testRepository/Status_test.cpp
        File.cpp
        Git.cpp
        main.cpp
        Repository.cpp)
