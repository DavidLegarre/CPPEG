#!/bin/bash

# Build the project
cmake -S . -B build
cmake --build build

# Run the executable if build succeeded
if [ -f build/GameEngine ]; then
    ./build/GameEngine
else
    echo "Build failed or GameEngine executable not found."
    exit 1
fi

# Cleanup build artifacts
echo "Cleaning up build artifacts..."
rm -rf build CMakeFiles CMakeCache.txt cmake_install.cmake Makefile