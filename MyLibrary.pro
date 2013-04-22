#CONFIG += shared
TEMPLATE = lib

QMAKE_CXXFLAGS += -fPIC

SOURCES += src/my_class.cpp

HEADERS += include/my_class.h

OTHER_FILES += \
    README \
    LibraryConfig.cmake.in \
    Library.pc.cmake \
    CMakeLists.txt \
    bin/CMakeLists.txt \
    bin/main.cpp \
    test/CMakeLists.txt \
    unitTesting/CMakeLists.txt \
    unitTesting/TestPass.cpp \
    unitTesting/TestFail.cpp
