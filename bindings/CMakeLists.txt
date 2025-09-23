# Build the Python extension
pybind11_add_module(corelink_sample_binding pybind_module.cpp)

install(TARGETS corelink_sample_binding DESTINATION corelink_sample_binding)

# Link against corelink_cpp and pybind11
target_link_libraries(corelink_sample_binding PRIVATE corelink_cpp)

target_include_directories(corelink_sample_binding PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(PY_PACKAGE_DIR ${CMAKE_SOURCE_DIR}/corelink_sample_binding)

# Run stubgen only if available
add_custom_command(
    TARGET corelink_sample_binding POST_BUILD
    COMMAND ${Python3_EXECUTABLE} -m pybind11_stubgen corelink_sample_binding
            --output-dir ${CMAKE_CURRENT_BINARY_DIR}/stubs
    # try copying from both possible stubgen layouts
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_BINARY_DIR}/stubs/corelink_sample_binding/corelink_sample_binding.pyi
            ${PY_PACKAGE_DIR}/corelink_sample_binding.pyi || true
    COMMAND ${CMAKE_COMMAND} -E touch ${PY_PACKAGE_DIR}/py.typed
)