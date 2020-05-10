#include "Declarations.h"

void Profile(string user, string pass)
{
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
			{
				cout << "Username: " << StaffArr[i].Username << endl;
				cout << "Full Name: " << StaffArr[i].Name << endl;
				cout << "Position: " << "STAFF" << endl;
				return;
			}

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
			{
				cout << "Username: " << LectArr[i].Username << endl;
				cout << "Full name: " << LectArr[i].Name << endl;
				cout << "Degree: " << LectArr[i].Degree << endl;
				cout << "Position: " << "LECTURER" << endl;
				return;
			}
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
			{
				cout << "Username: " << StuArr[i].ID << endl;
				cout << "Full name: " << StuArr[i].Fullname << endl;
				cout << "Class: " << StuArr[i].Class << endl;
				cout << "Date of Birth: " << StuArr[i].DoB << endl;
				cout << "Position: " << "STUDENT" << endl;
				return;
			}
		}

		delete[] StuArr;
	}
}

