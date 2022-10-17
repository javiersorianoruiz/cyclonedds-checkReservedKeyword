cmake_minimum_required(VERSION 2.6.4)
project(checkReservedKeywords C CXX)

set(CMAKE_CPP_COMPILER "/usr/bin/g++")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_BUILD_TYPE Debug)

#get source files of function (C files)
add_subdirectory(src)
get_directory_property(sources_function DIRECTORY src DEFINITION sources_function)
MESSAGE(STATUS "sources_function : ${sources_function}")

#get source files of testing function (CXX files)
add_subdirectory(test) 
get_directory_property(sources_testing DIRECTORY test DEFINITION sources_testing)
MESSAGE(STATUS "sources_testing : ${sources_testing}")


enable_testing()

OPTION(ENABLE_COVERAGE "Enable GCov coverage analysis" ON)

set (EXTRA_LIBRARIES
    gtest
    pthread
    )

IF (ENABLE_COVERAGE)
    MESSAGE(STATUS "Coverage enabled")
    add_compile_options("--coverage") 
    set (EXTRA_LIBRARIES 
        ${EXTRA_LIBRARIES}
        gcov
        )

    #equivalent to: add_compile_options("--coverage") 
    #set(CMAKE_CXX_FLAGS "-std=gnu++17 -fno-exceptions -Wall -Werror -Wconversion -Wno-sign-conversion -Wno-sign-compare -pthread -g --coverage -pthread")
    #set(CMAKE_CXX_FLAGS "-ggdb3 -Wall -fprofile-arcs -ftest-coverage -fPIC -O0 -Wno-deprecated-declarations")
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb3 -Wall -Wno-deprecated-declarations")
    #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}  -Wno-deprecated-declarations ")

    #set(CMAKE_C_FLAGS "-ggdb3 -Wall -fprofile-arcs -ftest-coverage -fPIC -O0 -Wno-deprecated-declarations")
ELSE()
    MESSAGE(STATUS "Coverage disabled")
ENDIF()

MESSAGE(STATUS "EXTRA_LIBRARIES : ${EXTRA_LIBRARIES}")

add_executable(test_function ${sources_function} ${sources_testing})
target_link_libraries(test_function ${EXTRA_LIBRARIES})