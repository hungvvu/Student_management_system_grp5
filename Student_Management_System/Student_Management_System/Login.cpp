#include "Declarations.h"


void LoadStudent(ifstream& fin, Stu* &a, int &NumofStu) {
	fin >> NumofStu;

	if (NumofStu == 0) {
		return;
	}
	else {
		// alocate new array of student
		a = new Stu[NumofStu];

		//fin.ignore()// get rid of the "\n"
		for (int i = 0; i < NumofStu; i++) {
			getline(fin, a[i].Fullname);
			getline(fin, a[i].Username);
			getline(fin, a[i].Password);
			getline(fin, a[i].DoB);
			getline(fin, a[i].Class);
			getline(fin, a[i].ID);
		}
	}
}

//string Login(string user, string pass) {
//	bool flag = true;
//
//	
//}
