#include "Declarations.h"

bool LoadStuScore(ifstream& fin, string username, string& midterm, string& Final, string& bonus, string& total) {
	string line;
	getline(fin, line);// skip the line that store number of students

	while (!fin.eof()) {
		getline(fin, line);// skip the name
		getline(fin, line);// get the ID

		if (line == username) {// check if this is the correct student
			getline(fin, line);
			getline(fin, line);
			getline(fin, line);
			fin >> midterm;
			fin >> Final;
			fin >> bonus;
			fin >> total;
			
			return true;// found the student
		}
		else {// skip until the separating line "\n"
			  // to begin checking next student
			do {
				getline(fin, line);
			} while (line != "");
		}
	}

	return false;// cannot find the student in this course
}

void View_Score(string username) {
	string year;
	string semester;
	string CourseClass;
	string CourseID;
	cout << "enter academic year(yyyy-yyyy): ";
	cin >> year;
	cout << "enter semester(Ex: HK2): ";
	cin >> semester;
	cout << "enter class: ";
	cin >> CourseClass;
	cout << "enter course ID: ";
	cin >> CourseID;

	string StuFile = year + "-" + semester + "-" + CourseClass + "-" + CourseID + "-Student.txt";

	ifstream fin;
	fin.open(StuFile.c_str());
	if (!fin.is_open()) {
		cout << "cannot find the entered course" << endl;
	}
	else {
		string midterm;
		string Final;
		string bonus;
		string total;

		if (!LoadStuScore(fin, username, midterm, Final, bonus, total)) {
			cout << "you weren't enrolled in this course" << endl;
			return;
		}

		cout << "midterm: " << midterm << endl;
		cout << "final: " << Final << endl;
		cout << "bonus: " << bonus << endl;
		cout << "---------" << endl;
		cout << "total: " << total << endl;

		fin.close();
	}
}
