#!/bin/bash
# buildAndRun.sh

# Optional: remove old build
# rm -rf build

cmake -S . -B build \
  -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build build -j

# Run the application
./build/Application
