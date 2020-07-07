cmake_minimum_required(VERSION 3.10)

# set the project name
project(
    QuickSort
    DESCRIPTION "QuickSort using parallel STL algorithms"
)

# set the project name and version
project(QuickSort VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add the executable
add_executable(qsort src/main.cpp)
target_compile_features(qsort PUBLIC cxx_std_17)

# features and libraries
option(DO_PARALLEL "Build with parallel STL support" OFF)
if(DO_PARALLEL)
    add_definitions(-DPARALLEL)
    target_link_libraries (qsort -ltbb)
endif()

# Documentation - require dot, treat the other components as optional
find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
         message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_OUTPUT_DIRECTORY docs)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)

    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate html pages"
    )
endif()
