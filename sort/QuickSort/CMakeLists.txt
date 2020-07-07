cmake_minimum_required(VERSION 3.10)

# set the project name
project(
    QuickSort
    DESCRIPTION "QuickSort using parallel STL algorithms"
)

# includes
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")
include(Common)

# set the project name and version
project(QuickSort VERSION 1.0)

# add the executable
add_executable(qsort src/main.cpp)
target_compile_features(qsort PUBLIC cxx_std_17)

# features and libraries
option(DO_PARALLEL "Build with parallel STL support" OFF)
if(DO_PARALLEL)
    add_definitions(-DPARALLEL)
    target_link_libraries (qsort -ltbb)
endif()

