cmake_minimum_required(VERSION 3.5)

project(a LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_library(AVUTIL_LIBRARY avutil REQUIRED)

add_executable(a main.cpp)

target_link_libraries( a PUBLIC ${AVUTIL_LIBRARY})
