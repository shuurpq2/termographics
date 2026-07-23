cmake_minimum_required(VERSION 3.28)

project(termographics_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("C:/Users/Public/MS VSCode/gtest" "${CMAKE_CURRENT_BINARY_DIR}/googletest_build")

add_executable(a.out
    ../src/camera.cpp
    ../src/vector3i.cpp
    camera_test.cpp)

target_include_directories(a.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(a.out PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(a.out)