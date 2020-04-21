#include "Declarations.h"

int main() {

	//int choice1, choice2;
	//string Position = "Student";//Position will get it from files
	//choice1 = 0;
	//choice2 = 0;
	//showmenu(choice1, choice2, Position);
	//if (choice2 == 1)
	//	cout << "Success";//place to perform Attendance...

	Stu* StudentList;
	int NumofStu;

	ifstream fin;
	fin.open("Student.txt");
	if (!fin.is_open()) {
		cout << "can not open file" << endl;
	}
	else {
		LoadStudent(fin, StudentList, NumofStu);
		fin.close();

		for (int i = 0; i < NumofStu; i++) {
			cout << StudentList[i].Fullname << endl;
			cout << StudentList[i].Username << endl;
			cout << StudentList[i].Password << endl;
			cout << StudentList[i].Class << endl;
			cout << StudentList[i].ID << endl;
			cout << StudentList[i].DoB << endl;
		}

		delete[] StudentList;// dealocate
	}
	return 0;
}