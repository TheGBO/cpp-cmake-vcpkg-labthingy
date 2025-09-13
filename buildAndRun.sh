#!/bin/bash
set -e

# Check argument
if [ $# -lt 1 ]; then
    echo "Usage: $0 [linux|windowsAndWine]"
    exit 1
fi

TARGET=$1
BUILD_DIR="build_$TARGET"

# Remove old build
rm -rf "$BUILD_DIR"
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure CMake depending on target
if [ "$TARGET" == "linux" ]; then
    cmake -S .. -B . \
        -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

elif [ "$TARGET" == "windowsAndWine" ]; then
    cmake -S .. -B . \
    -DCMAKE_TOOLCHAIN_FILE="$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake" \
    -DCMAKE_SYSTEM_NAME=Windows \
    -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
    -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
    -DVCPKG_TARGET_TRIPLET=community/x64-windows-mingw \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
        

else
    echo "Unknown target: $TARGET"
    exit 1
fi

# Build
cmake --build . -j

# Run
if [ "$TARGET" == "linux" ]; then
    ./Application
elif [ "$TARGET" == "windowsAndWine" ]; then
    wine ./Application.exe
fi
