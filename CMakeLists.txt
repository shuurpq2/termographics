cmake_minimum_required(VERSION 3.28)

project(termographics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(a.out
    src/camera.cpp
    src/vector3i.cpp
    src/main.cpp)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../ftxui" "${CMAKE_CURRENT_BINARY_DIR}/ftxui_build")

target_include_directories(a.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)