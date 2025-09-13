cmake_minimum_required(VERSION 3.16)
project(Application)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------
# Raylib (via pkg-config)
# ----------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})

# ----------------------
# fmt (modern CMake)
# ----------------------
find_package(fmt REQUIRED)

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
# rlImGui (external)
# ----------------------
add_library(rlImGui STATIC external/rlImGui/rlImGui.cpp)
target_include_directories(rlImGui PUBLIC external/rlImGui external/rlImGui/extras)
target_link_libraries(rlImGui PUBLIC imgui ${RAYLIB_LIBRARIES})

# ----------------------
# Application
# ----------------------
file(GLOB SOURCES "src/*.cpp")
add_executable(Application ${SOURCES})

target_include_directories(Application PRIVATE
    external/imgui
    external/rlImGui
    external/rlImGui/extras
)

target_link_libraries(Application
    rlImGui
    imgui
    ${RAYLIB_LIBRARIES}
    fmt::fmt
    m pthread dl
)
