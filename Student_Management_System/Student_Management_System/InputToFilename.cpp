#include "Declarations.h"

void OpenInputedClassFile() {// function to test file open
	string Class;
	cout << "enter class: ";
	cin >> Class;

	ifstream fin;
	fin.open(FileName_Stu_Classes(Class).c_str());// open the student file of the inputed class,
												  // need .c_str to convert from string to const char*
	if (!fin.is_open()) {
		cout << "can't find class";
	}
	else {
		cout << "open file successfull";
		fin.close();
	}
}

string FileName_Stu_Classes(string Class) {// function to convert a class name to valid file name for class
	return "Student-" + Class + ".txt";// turn the inputed class to the file name, "Student-<Class>.txt"
}