#include "Declarations.h"


void LoadStudent(ifstream& fin, Stu* &a, int &NumofStu) {
	fin >> NumofStu;

	if (NumofStu == 0) {
		return;
	}

	// alocate new array of student
	a = new Stu[NumofStu];

	fin.ignore();// get rid of the "\n"
	for (int i = 0; i < NumofStu; i++) {
		getline(fin, a[i].Fullname);
		getline(fin, a[i].ID);
		getline(fin, a[i].Password);
		getline(fin, a[i].DoB);
		getline(fin, a[i].Class);
		fin.ignore();// skip the empty line
	}
}

void LoadLect(ifstream& fin, Lect*& a, int& NumofLect) {
	fin >> NumofLect;

	if (NumofLect == 0) {
		return;
	}

	a = new Lect[NumofLect];

	fin.ignore();// get rid of the "\n"
	for (int i = 0; i < NumofLect; i++) {
		getline(fin, a[i].Name);
		getline(fin, a[i].Username);
		getline(fin, a[i].Password);
		getline(fin, a[i].Degree);
		fin >> a[i].Sex;
		fin.ignore();// skip the empty line
	}
}

void LoadStaf(ifstream& fin, Staf*& a, int& NumofStaf) {
	fin >> NumofStaf;

	if (NumofStaf == 0) {
		return;
	}

	a = new Staf[NumofStaf];

	fin.ignore();
	for (int i = 0; i < NumofStaf; i++) {
		getline(fin, a[i].Name);
		getline(fin, a[i].Username);
		getline(fin, a[i].Password);
		fin >> a[i].Sex;
		fin.ignore();// skip the empty line
	}
}

string Login(string user, string pass) {
	bool found = false;
	
	ifstream fin;
	fin.open("Staff.txt");
	if (!fin.is_open()) {
		cout << "can't open staff file" << endl;
	}
	else {
		Staf* StaffArr;
		int n = 0;
		LoadStaf(fin, StaffArr, n);
		fin.close();

		for (int i = 0; i < n; i++) {
			if (user == StaffArr[i].Username && pass == StaffArr[i].Password)
				return "Staff";
		}

		delete[] StaffArr;
	}
	
	fin.open("Lecturer.txt");
	if (!fin.is_open()) {
		cout << "can't open Lecturer file" << endl;
	}
	else {
		Lect* LectArr;
		int n = 0;
		LoadLect(fin, LectArr, n);
		fin.close();

		for (int i = 0; i < n; i++) {
			if (user == LectArr[i].Username && pass == LectArr[i].Password)
				return "Lecturer";
		}

		delete[] LectArr;
	}

	fin.open("Student.txt");
	if (!fin.is_open()) {
		cout << "can't open Student file" << endl;
	}
	else {
		Stu* StuArr;
		int n = 0;
		LoadStudent(fin, StuArr, n);
		fin.close();

		for (int i = 0; i < n; i++) {
			if (user == StuArr[i].ID && pass == StuArr[i].Password)
				return "Lecturer";
		}

		delete[] StuArr;
	}

	// can't find the given username and password in the data base
	return "-1";
}
