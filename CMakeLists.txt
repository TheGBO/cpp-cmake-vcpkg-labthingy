cmake_minimum_required(VERSION 3.16)
project(Application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})

# Find fmt using modern CMake
find_package(fmt REQUIRED)

# Source files
file(GLOB SOURCES "src/*.cpp")
add_executable(Application ${SOURCES})

# Link libraries
target_link_libraries(Application ${RAYLIB_LIBRARIES} fmt::fmt)
