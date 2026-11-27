
# Summary

Implementations of fundamental tree data structures in C++, developed for learning and practice.

## Data Structures Implemented

- Binary Search Tree (BST)
- Trie (Prefix Tree)
- Binary Heap

## Requirements

- C++20 or higher
- CMake 3.20 or higher

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run Tests

```bash
ctest --test-dir build --output-on-failure
```

## Project Structure

```text
.
├── include/
│   ├── bst.hpp
│   ├── tries.hpp
│   └── binHeaps.hpp
├── tests/
│   └── main.cpp
└── CMakeLists.txt
```
