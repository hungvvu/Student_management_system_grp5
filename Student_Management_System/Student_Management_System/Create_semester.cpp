#include "Declarations.h"

void New_Semester() {
	ifstream fin;
	fin.open("Semester.txt");
	if (!fin.is_open()) {
		cout << "cannot open file" << endl;
	}
	else {
		ofstream fout;
		fout.open("semester.txt");
		if (!fout.is_open()) {
			cout << "cannot open file" << endl;
		}
		else {

		}
	}
}