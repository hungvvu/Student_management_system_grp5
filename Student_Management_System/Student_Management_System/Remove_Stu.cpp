#include "Declarations.h"

bool Remove_Student() {
	// find the student
	string Class;
	cout << "enter student's class: ";
	cin >> Class;
	while (ClassPos(Class) == 0) {// wrong class code, enter again
		cout << "Incorrect class code, please re-enter: ";
		cin >> Class;
	}

	string ID;
	cout << "enter student ID: ";
	cin >> ID;
	Stu Student;

	if (Load_1Stu_Class(Class, ID, Student) == -1)// can't open file
		return false;
	while (Load_1Stu_Class(Class, ID, Student) == -2) {// can't find given student in the class
		cout << "cannot find the given student in this class" << endl;
		cout << "please re-enter student ID: ";
		cin >> ID;
	}

	// remove that student
	if (!RemoveFromClass(Student.Class, Student.ID))
		return false;
	if (!RemoveFromMainData(Student.ID))
		return false;
	return true;
}