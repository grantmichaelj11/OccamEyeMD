#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
using namespace std;

vector<tuple<string, double, double, double>> read_xyz(string filename);

// Scan until we find "ATOM"
// I'll need to take care for missing columns
//vector<tuple<std::string, int, string, string, string, int, double, double, double, double, double, string>> read_pdb();

string read_pdb(string filename);





