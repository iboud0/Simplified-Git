QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
LIBS += -lstdc++fs

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    File.cpp \
    Git.cpp \
    Repository.cpp \
    main.cpp \
    mainwindow.cpp \
    # tests/testFile/File_test.cpp \
    # tests/testRepository/Init_test.cpp \
    # tests/testRepository/OverwritingFilesFile_test.cpp \
    # tests/testFile/File_test.cpp \
    # tests/testRepository/Init_test.cpp \
    # tests/testRepository/OverwritingFilesFile_test.cpp \
    # tests/testRepository/Repository_test.cpp

HEADERS += \
    includes/File.h \
    includes/Git.h \
    includes/Repository.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    LICENSE \
    README.md \
    tests/testFile/ReadMe \
    tests/testFile/test_file.txt \
    tests/testRepository/ReadMe \
    tests/testRepository/Repository/git/Files \
    tests/testRepository/Repository/git/log \
    tests/testRepository/repositoryTest/file1.txt \
    tests/testRepository/repositoryTest/file2.txt \
    tests/testRepository/repositoryTest/file3.txt \
    tests/testRepository/repositoryTest/git/files \
    tests/testRepository/repositoryTest/git/log \
    tests/testRepository/repository_test.exe
