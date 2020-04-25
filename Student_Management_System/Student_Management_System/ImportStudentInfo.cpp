#include "Declarations.h"

void ImportStudent(ifstream& fin, Stu*& a, int& NumofStu)
{
	fin >> NumofStu;

	if (NumofStu == 0) {
		return;
	}

	// alocate new array of student
	a = new Stu[NumofStu];

	fin.ignore();// get rid of the "\n"
	for (int i = 0; i < NumofStu; i++) {
		getline(fin, a[i].Fullname);
		getline(fin, a[i].Class);
		getline(fin, a[i].ID);
		getline(fin, a[i].DoB);
		fin.ignore();// skip the empty line
	}
}

void CSVStudent()
{
	ifstream fin;

	fin.open("Import_Student_Info.csv");
	if (!fin.is_open()) {
		cout << "can't open Student file" << endl;
	}
	else {
		Stu* StuArr;
		int n = 0;
		ImportStudent(fin, StuArr, n);
		fin.close();

		for (int i = 0; i < n; i++) 
		{
			cout << "STUDENT 1: " << endl;
			cout << "Name: " << StuArr[i].Fullname << endl;
			cout << "Class: " << StuArr[i].Class << endl;
			cout << "ID: " << StuArr[i].ID << endl;
			cout << "Date of Birth: " << StuArr[i].DoB << endl;
			cout << endl;
		}

		delete[] StuArr;
	}
}