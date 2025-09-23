#include <pybind11/pybind11.h>
#include <hello_world.hpp>


void hello_world();

namespace py = pybind11;


PYBIND11_MODULE(corelink_sample_binding,m) {
    m.doc() = "Sample binding for hello_world()";

    m.def("hello_world", &hello_world, "prints hello world from cpp");
    m.def("return_20", &return_20, "returns 20");
}