cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "seventh_laba")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)


include_directories("inc/")

add_executable(${PROJECT_NAME} seventh.cpp
				inc/func.hpp
				src/func.cpp)