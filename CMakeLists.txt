cmake_minimum_required(VERSION 3.15)
project(corelink_sample_binding LANGUAGES CXX)
find_package(pybind11 CONFIG REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
set(Python3_EXECUTABLE "${CMAKE_SOURCE_DIR}/venv/bin/python3")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(bindings)