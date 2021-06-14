cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)

project(hw2pt2 VERSION 0.1.0 LANGUAGES CXX)

# set(CMAKE_VERBOSE_MAKEFILE ON)

set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})

# Add the names of your source files here
set(CPP_FILES Exceptions.cpp gameTest.cpp Character.cpp Game.cpp Medic.cpp Sniper.cpp Soldier.cpp Board.cpp Auxiliaries.cpp)

add_executable(hw2pt2 ${CPP_FILES})