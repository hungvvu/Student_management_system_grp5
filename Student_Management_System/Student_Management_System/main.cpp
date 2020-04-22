#include "Declarations.h"

int main() {

	/*************
		I use this just to test the Load function,
		this will be delete when merge to master branch
	**************/
	//Stu* StudentList;
	//int NumofStu;
	//ifstream fin;
	//fin.open("Student.txt");
	//if (!fin.is_open()) {
	//	cout << "can not open file" << endl;
	//}
	//else {
	//	LoadStudent(fin, StudentList, NumofStu);
	//	fin.close();

	//	// for testing the Load function, will be deleted when merge to master
	//	for (int i = 0; i < NumofStu; i++) {
	//		cout << StudentList[i].Fullname << endl;
	//		cout << StudentList[i].ID << endl;
	//		cout << StudentList[i].Password << endl;
	//		cout << StudentList[i].DoB << endl;
	//		cout << StudentList[i].Class << endl;
	//	}

	//	delete[] StudentList;// dealocate
	//}

	int choice1, choice2;
	string Position = "Student";//Position will get it from files
	choice1 = 0;
	choice2 = 0;
	showmenu(choice1, choice2, Position);
	if (choice2 == 1)
		cout << "Success";//place to perform Attendance...

	return 0;
}