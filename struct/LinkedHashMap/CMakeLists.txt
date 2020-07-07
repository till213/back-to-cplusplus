cmake_minimum_required(VERSION 3.10)

# set the project name
project(
    LinkedHashMap
    DESCRIPTION "A HashMap which keeps insertion order"
)

# includes
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")
include(Common)

# set the project name and version
project(LinkedHashMap VERSION 1.0)

# add the executable
add_executable(linkhm src/main.cpp)
