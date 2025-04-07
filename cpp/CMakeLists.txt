cmake_minimum_required(VERSION 3.10)

project(cpp_algorithm_solutions)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Test
add_subdirectory(third_party/googletest)

# Add tests
add_subdirectory(tests)

# Specify a build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to specify which files to build
option(BUILD_ALL "Build all files" OFF)
if(NOT BUILD_ALL)
    set(BUILD_TARGET "" CACHE STRING "Specific target to build (e.g., 25-Apr6_test)")
endif()
