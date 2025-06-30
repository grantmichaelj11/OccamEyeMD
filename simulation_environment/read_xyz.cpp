#include "read_xyz.hpp"
using namespace std;

vector<tuple<string, double, double, double>> read_xyz() { //Need to add a string as an argument!
	// Open file and store variable for the current line
	string currentLine;
	fstream MyFile("SQOH2ME.xyz");

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

PYBIND11_MODULE(load_atoms, m) {
	m.def("read_xyz", &read_xyz, "Load an XYZ File into Vector format");
}









