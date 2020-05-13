#include "Declarations.h"

bool New_Semester() {
	ifstream fin;
	fin.open("Semester.txt");
	if (!fin.is_open()) {
		cout << "cannot open file" << endl;
		return false;
	}
	else {
		ofstream temp;
		temp.open("temp.txt");

		if (!temp.is_open()) {
			cout << "cannot write in file" << endl;
			fin.close();
			return false;
		}
		else {
			string year;
			cout << "enter academic year(yyyy-yyyy): ";
			cin >> year;

			int sem;
			do {
				cout << "current semester(1,2 or 3): ";
				cin >> sem;
				if (sem <= 0 || sem > 3)
					cout << "invalid semester, please enter again" << endl;
			} while (sem <= 0 || sem > 3);

			int numOfsem;
			fin >> numOfsem;
			fin.ignore();

			temp << numOfsem + 1 << endl;
			string line;
			while (getline(fin, line)) {// copy past semesters to temp
				temp << line << endl;
			}

			// print out the new semester
			temp << year << endl;
			temp << sem << endl;
			temp << endl;

			temp.close();
		}
		fin.close();

		remove("Semester.txt");// remove old file
		rename("temp.txt", "Semester.txt");// rename the temp file
	}
	return true;
}

string Cur_Semester() {
	ifstream fin;
	fin.open("Semester.txt");
	if (!fin.is_open()) {
		cout << "cannot open file" << endl;
	}
	else {
		int numOfsem;
		fin >> numOfsem;
		fin.ignore();

		string year;
		int sem;

		while (numOfsem > 0) {// move to the latest semester
			getline(fin, year);// get the year
			fin >> sem;// get the semester
			fin.ignore();
			fin.ignore();// ignore the empty line

			--numOfsem;
		}
		fin.close();
		
		switch (sem) {
		case 1: {
			string semester = "-Sem1";
			return year + semester;
		}
		case 2: {
			string semester = "-Sem2";
			return year + semester;
		}
		case 3: {
			string semester = "-Sem3";
			return year + semester;
		}
		}
	}
	return "-1";// error
}