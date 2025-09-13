cmake_minimum_required(VERSION 3.21)

project(Application LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find vcpkg-installed packages
find_package(fmt CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt::fmt
    raylib
    glfw
)

# Platform-specific system libraries
if(UNIX AND NOT APPLE)
    # Linux static build needs X11, GL, etc.
    target_link_libraries(${PROJECT_NAME} PRIVATE
        X11 Xrandr Xi Xxf86vm Xinerama Xcursor GL m pthread dl
    )
elseif(WIN32)
    # Windows static build needs OpenGL + GDI
    target_link_libraries(${PROJECT_NAME} PRIVATE
        opengl32 gdi32
    )
endif()
