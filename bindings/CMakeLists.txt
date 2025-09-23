# Build the Python extension
pybind11_add_module(corelink pybind_module.cpp)

set(PY_PACKAGE_DIR ${CMAKE_SOURCE_DIR}/corelink)

set_target_properties(corelink PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PY_PACKAGE_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${PY_PACKAGE_DIR}
)

install(TARGETS corelink DESTINATION ${PY_PACKAGE_DIR})

# Link against corelink_cpp and pybind11
target_link_libraries(corelink PRIVATE corelink_cpp)

target_include_directories(corelink PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(PY_PACKAGE_DIR ${CMAKE_SOURCE_DIR}/corelink)
set(STUBS_DIR ${CMAKE_CURRENT_BINARY_DIR}/.stubs)

#run stubgen if available
add_custom_command(
    TARGET corelink POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}/bindings
            ${Python3_EXECUTABLE} -m pybind11_stubgen corelink
            --output-dir ${STUBS_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${STUBS_DIR}/corelink-stubs/corelink.pyi
            ${PY_PACKAGE_DIR}/corelink.pyi || true
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${STUBS_DIR}/corelink-stubs/__init__.pyi
            ${PY_PACKAGE_DIR}/corelink.pyi || true
    COMMAND ${CMAKE_COMMAND} -E touch ${PY_PACKAGE_DIR}/py.typed
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${STUBS_DIR}
)