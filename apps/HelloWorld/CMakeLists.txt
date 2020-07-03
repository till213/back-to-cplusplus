cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloWorld)

# set the project name and version
project(HelloWorld VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add the executable
add_executable(hello src/main.cpp)

configure_file(src/HelloWorldConfig.h.in generated/HelloWorldConfig.h)
target_include_directories(hello PUBLIC
                           "${PROJECT_SOURCE_DIR}/generated"
                           )