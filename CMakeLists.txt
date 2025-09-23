cmake_minimum_required(VERSION 3.15)
project(corelink_sample_binding LANGUAGES CXX)
find_package(pybind11 CONFIG REQUIRED)

# Ensure modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(bindings)