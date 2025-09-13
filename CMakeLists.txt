cmake_minimum_required(VERSION 3.21)
set(PROJECT_NAME "Application")

project(${PROJECT_NAME} LANGUAGES CXX)
add_executable(${PROJECT_NAME} src/main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}  PRIVATE fmt::fmt)
