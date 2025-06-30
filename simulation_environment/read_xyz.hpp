#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

std::vector<std::tuple<std::string, double, double, double>> read_xyz();
