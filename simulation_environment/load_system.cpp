#include "load_system.hpp"
using namespace std;


// .xyz files will be used for DFT inputs or AIMD
vector<tuple<string, double, double, double>> read_xyz(string filename) { //Need to add a string as an argument!
	// Open file and store variable for the current line
	string currentLine;
	fstream MyFile(filename);

	// Read first line -> save number of atoms
	getline(MyFile, currentLine);

	//tuple = <ATOM, X, Y, Z>
	vector<tuple<string, double, double, double>> atoms;

	// Skip second line
	getline(MyFile, currentLine);
	
	string atomType;
	double x, y, z;
	// Read each line and save atom information to vector
	while (getline (MyFile, currentLine)) {
		istringstream iss(currentLine);
		iss >> atomType >> x >> y >> z;

		if (iss) {
			atoms.push_back(make_tuple(atomType, x, y, z));
		}

	}

	//int vectorSize = atoms.size();
	//string currentAtom;
	//for (int i=0; i < vectorSize; i++){
	//	currentAtom = get<0>(atoms[i]);
	//	x = get<1>(atoms[i]);
	//	y = get<2>(atoms[i]);
	//	z = get<3>(atoms[i]);

	//	cout << currentAtom << " " << x << " " << y << " " << z << "\n";
	//}
	
	//close the file
	MyFile.close();


	//return the vector
	return atoms;

}

//std::vector<std::tuple<std::string, int, string, string, string, int, double, double, double, double, double, string>> read_pdb(string filename) {

//For running MD or AIMD
string read_pdb(string filename, string simulation_package) {
	try {
		if (simulation_package == "amber" || "aimd") {
			cout << "amber";
		} else {
				throw exception;
			}
	}

	catch (...) {
		return "Error - invalid simulation package"
	}
	
	// if amber do the conversion
	// I don't need to copy Amber's exact parameter file because I am running it from my system
	//

	// if aimd do the conversion

	return filename;
}


PYBIND11_MODULE(load_atoms, m) {
	m.def("read_xyz", &read_xyz, "Load an XYZ file into simulation");
	m.def("read_pdb", &read_pdb, "Load a PDB file into simulation");
}









