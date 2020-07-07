cmake_minimum_required(VERSION 3.10)

# set the project name
project(
    LRUCache
    DESCRIPTION "A Least Recently Used Cache with fixed capacity"
)

# includes
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")
include(Common)

# set the project name and version
project(LRUCache VERSION 1.0)

# add the executable
add_executable(lruc src/main.cpp)
