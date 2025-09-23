cmake_minimum_required(VERSION 3.15)
project(corelink_sample_binding LANGUAGES CXX)
find_package(pybind11 CONFIG REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Ensure Python3_EXECUTABLE matches the Python used to run pip
if(NOT DEFINED Python3_EXECUTABLE)
    set(Python3_EXECUTABLE "${Python3_EXECUTABLE}" CACHE FILEPATH "Python3 interpreter" FORCE)
endif()

message(STATUS "Using Python executable: ${Python3_EXECUTABLE}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(bindings)