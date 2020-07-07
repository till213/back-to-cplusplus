cmake_minimum_required(VERSION 3.10)

# includes
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")
include(Common)

# set the project name
project(HelloWorld)

# set the project name and version
project(HelloWorld VERSION 1.0)

# add the executable
add_executable(hello src/main.cpp)

configure_file(src/HelloWorldConfig.h.in generated/HelloWorldConfig.h)
target_include_directories(hello PUBLIC
                           "${PROJECT_SOURCE_DIR}/generated"
                           )