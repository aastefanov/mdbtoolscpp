cmake_minimum_required(VERSION 3.13)
project(mdbtoolscpp)

set(HEADER_FILES
        include/schema/mdbenums.h
        include/schema/mdboperations.h
        include/schema/mdbschema.h
        include/schema/mdbtable.h
        include/MdbFile.h
        include/helpers/MdbFileHelpers.h
        include/func/endian.h
        include/mdbtools.h)

set(SRC_FILES
        src/MdbFile.cpp
        src/helpers/MdbFileHelpers.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 14)
add_library(mdbtoolscpp STATIC ${HEADER_FILES} ${SRC_FILES} )

#set_target_properties(mdbtoolscpp PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -c")

cmake_minimum_required(VERSION 3.13)
project(gosho)

add_executable(gosho
        library.cpp ${HEADER_FILES} ${SRC_FILES} )

target_link_libraries(gosho mdbtoolscpp)


if (WIN32)
    target_link_libraries(mdbtoolscpp wsock32)
endif (WIN32)

