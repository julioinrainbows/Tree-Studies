cmake_minimum_required(VERSION 3.20)

project(TreeDataStructures
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only library
add_library(TreeDataStructures INTERFACE)

target_include_directories(TreeDataStructures
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(TreeDataStructures
    INTERFACE
        cxx_std_20
)

# Tests executable
add_executable(TreeDataStructuresTests
    tests/main.cpp
)

target_link_libraries(TreeDataStructuresTests
    PRIVATE TreeDataStructures
)

# Enable CTest
enable_testing()

add_test(
    NAME TreeDataStructuresTests
    COMMAND TreeDataStructuresTests
)
