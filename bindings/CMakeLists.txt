# Build the Python extension
pybind11_add_module(corelink_sample_binding pybind_module.cpp)

install(TARGETS corelink_sample_binding
        DESTINATION corelink_sample_binding)

# Link against corelink_cpp and pybind11
target_link_libraries(corelink_sample_binding PRIVATE corelink_cpp)

target_include_directories(corelink_sample_binding PRIVATE ${CMAKE_SOURCE_DIR}/include)