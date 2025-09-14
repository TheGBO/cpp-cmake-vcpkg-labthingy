cmake_minimum_required(VERSION 3.16)
project(Application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------
# Raylib (via vcpkg or custom find script)
# ----------------------
find_package(raylib CONFIG REQUIRED)

# ----------------------
# fmt (modern CMake)
# ----------------------
find_package(fmt CONFIG REQUIRED)

# ----------------------
# imgui (external)
# ----------------------
add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_demo.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC external/imgui)

# ----------------------
# imgui-knobs (external)
# ----------------------
add_library(imgui-knobs STATIC
    external/imgui-knobs/imgui-knobs.cpp
)
target_include_directories(imgui-knobs PUBLIC external/imgui-knobs)
target_link_libraries(imgui-knobs PUBLIC imgui)

# ----------------------
# rlImGui (external)
# ----------------------
add_library(rlImGui STATIC external/rlImGui/rlImGui.cpp)
target_include_directories(rlImGui PUBLIC external/rlImGui external/rlImGui/extras)
target_link_libraries(rlImGui PUBLIC imgui raylib)

# ----------------------
# Application
# ----------------------
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Application ${SOURCES})

target_include_directories(Application PRIVATE
    src
    external/imgui
    external/rlImGui
    external/rlImGui/extras
    external/imgui-knobs
)

target_link_libraries(Application
    rlImGui
    imgui
    imgui-knobs
    raylib
    fmt::fmt
)

# Only link POSIX stuff on Linux
if(UNIX)
    target_link_libraries(Application m pthread dl)
endif()
