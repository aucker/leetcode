cmake_minimum_required(VERSION 3.10)

project(cpp_algorithm_solutions)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Test
add_subdirectory(third_party/googletest)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")
foreach(SOURCE ${SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE})
endforeach()

# Add tests
add_subdirectory(tests)

# Specify a build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
