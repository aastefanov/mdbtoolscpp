cmake_minimum_required(VERSION 3.13)
project(mdbtoolscpp)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_library(mdbtoolscpp
        library.cpp
        include/schema/mdbenums.h
        include/schema/mdboperations.h
        include/schema/mdbschema.h
        include/schema/mdbtable.h
        include/file.h
        include/func/endian.h
        include/mdbtools.h)

add_executable(gosho library.cpp include/func/endian.h src/MdbFile.cpp src/backends.cpp include/backends.h include/func/buffers.h)

if(WIN32)
    target_link_libraries(gosho wsock32)
endif(WIN32)
