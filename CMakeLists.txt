###############################################################################
#  University of Hawaii, College of Engineering
#  Animal Farm - EE 205 - Spring 2024
#
## CMake manages the building of source code.
##
## @see https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
##
## @file   CMakeLists.txt
## @author Mark Nelson <marknels@hawaii.edu>
###############################################################################

cmake_minimum_required(VERSION 3.26)

project(ee205_animal_farm
        VERSION 1.0
        DESCRIPTION "All animals are equal, but some animals are more equal than others"
        LANGUAGES CXX)

message(STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(CMAKE_CXX_CLANG_TIDY
        clang-tidy -extra-arg=-std=c++17;
)

include(.doxygen/CMake_Doxygen.txt)

add_executable(main_hello src/main_hello.cpp)
