# Corelink Sample Binding

Python bindings for the Corelink C++ client, built with [pybind11](https://github.com/pybind/pybind11) and [scikit-build-core](https://scikit-build-core.readthedocs.io/).

This package exposes selected Corelink C++ APIs to Python.

---

## 📦 Installation

### Requirements
- Python ≥ 3.8
- A C++17 compiler (Clang, GCC, or MSVC)
- [CMake ≥ 3.15](https://cmake.org/)
- `pip`, `setuptools`, and `wheel`

### Install from source

Clone this repository and install into your Python environment:

```bash
cd */sample_binding

# create & activate a venv (optional but recommended)
python3 -m venv venv
source venv/bin/activate

# build and install
pip install .
