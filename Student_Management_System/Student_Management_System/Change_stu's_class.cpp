#include "Declarations.h"

int Load_1Stu_Class(string Class, string ID, Stu& Student) {
	int Pos = ClassPos(Class);
	switch (Pos) {
	case 7: {
		ifstream fin;
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				getline(fin, Student.Class);
				//fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			
			fin.close();
		}
		return 0;
	}
	}
}

bool RemoveFromClass(string Class, string ID) {
	int Pos = ClassPos(Class);
	switch (Pos) {
	case 7: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					getline(fin, Student.Class);
					//fin.ignore();// skip the empty line
					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC5.txt");// remove old file
				rename("temp.txt", "Student-19CLC5.txt");// rename the temp file
			}
		}
	}
	}
}

bool ChangeStu2Class() {
	string C;
	cout << "enter the current class of the student: ";
	cin >> C;
	while (ClassPos(C) == 0) {// wrong class code, enter again
		cout << "Incorrect class code, please re-enter: ";
		cin >> C;
	}

	string ID;
	cout << "enter student ID: ";
	cin >> ID;
	Stu S;

	// remove that student from the current class
	if (Load_1Stu_Class(C, ID, S) == -1)// can't open file
		return false;
	while (Load_1Stu_Class(C, ID, S) == -2) {// can't find given student in the class
		cout << "cannot find the given student in this class" << endl;
		cout << "please re-enter student ID: ";
		cin >> ID;
	}
	if (!RemoveFromClass(C, ID))
		return false;

	// asign new class for that student
	string nC;
	cout << "enter the new class of the student: ";
	cin >> nC;
	while (ClassPos(nC) == 0 || nC == C) {// wrong class code, enter again
		cout << "Incorrect class code, please re-enter: ";
		cin >> nC;
	}
	S.Class = nC;

	if (AddToClass(nC, S) < 0)// add the student to the new class
		return false;
	return true;
}