cmake_minimum_required(VERSION 2.6.4)
project(checkReservedKeywords C)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_BUILD_TYPE Debug)

OPTION(ENABLE_COVERAGE "Enable GCov coverage analysis (defines a 'coverage'
target and enforces static build of miind)" ON)

set (EXTRA_LIBRARIES "")

IF (ENABLE_COVERAGE)
    MESSAGE(STATUS "Coverage enabled")
    add_compile_options("--coverage") 
    set (EXTRA_LIBRARIES 
        ${EXTRA_LIBRARIES}
        gcov
        )

    #equivalent to: add_compile_options("--coverage") 
    #set(CMAKE_CXX_FLAGS "-ggdb3 -Wall -fprofile-arcs -ftest-coverage -fPIC -O0 -Wno-deprecated-declarations")
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb3 -Wall -Wno-deprecated-declarations")
    #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}  -Wno-deprecated-declarations ")
ELSE()
    MESSAGE(STATUS "Coverage disabled")
ENDIF()

MESSAGE(STATUS "EXTRA_LIBRARIES : ${EXTRA_LIBRARIES}")



add_executable(test test/test.c src/checkReservedKeyword.c)
target_link_libraries(test ${EXTRA_LIBRARIES})