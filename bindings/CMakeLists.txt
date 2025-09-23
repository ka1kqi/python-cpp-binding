# Build the Python extension
pybind11_add_module(corelink pybind_module.cpp)

set(PY_PACKAGE_DIR ${CMAKE_SOURCE_DIR})

set_target_properties(corelink PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PY_PACKAGE_DIR}/corelink
    RUNTIME_OUTPUT_DIRECTORY ${PY_PACKAGE_DIR}/corelink
)

install(TARGETS corelink DESTINATION corelink)

# Link against corelink_cpp and pybind11
target_link_libraries(corelink PRIVATE corelink_cpp)

target_include_directories(corelink PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

#run stubgen if available
add_custom_command(
    TARGET corelink POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${PY_PACKAGE_DIR}
            ${Python3_EXECUTABLE} -m pybind11_stubgen corelink
            --output-dir ${PY_PACKAGE_DIR}
    COMMAND ${CMAKE_COMMAND} -E touch ${PY_PACKAGE_DIR}/corelink/py.typed
)