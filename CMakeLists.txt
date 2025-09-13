cmake_minimum_required(VERSION 3.21)

project(Application LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use vcpkg-installed packages
find_package(fmt CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries
# Raylib config from vcpkg automatically links GLFW in the correct order
target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt::fmt
    raylib
    glfw
)

# Only link system libraries if needed (mostly for static builds)
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        X11 Xrandr Xi Xxf86vm Xinerama Xcursor GL m pthread dl
    )
endif()
