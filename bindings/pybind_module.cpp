#include <pybind11/pybind11.h>
#include <hello_world.hpp>
#include <person.h>

void hello_world();

namespace py = pybind11;


PYBIND11_MODULE(corelink,m) {
    m.doc() = "Sample binding for hello_world()";

    m.def("hello_world", &hello_world, "prints hello world from cpp");

    py::class_<Person>(m, "Person")
        .def(py::init<>())
        .def(py::init<std::string, int>(),py::arg("name"), py::arg("age"),
         "Create a person with a name and age")
        .def("get_age", &Person::get_age,"get the person's age")
        .def("increment_age",&Person::increment_age, "increase the person's age by 1")
        .def("change_name", &Person::change_name, py::arg("new_name"), "change person's name")
        .def("get_person", &Person::get_person, "returns person as string");
}