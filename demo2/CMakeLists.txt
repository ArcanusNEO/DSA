cmake_minimum_required(VERSION 3.0)
project(demo2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
include_directories(inc)
link_directories(lib)
add_library(List STATIC src/List.cc)
add_library(RadixSort STATIC src/RadixSort.cc)
add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} List RadixSort)