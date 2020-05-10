#include "Declarations.h"
//int ClassPos(string Class) {/* function to return the position of a class in the following list:
//1-19APCS1
//2-19APCS2
//3-19CLC1
//4-19CLC2
//5-19CLC3
//6-19CLC4
//7-19CLC5
//8-19CLC6
//9-19CLC7
//10-19CLC8
//11-19CLC9
//12-19CLC10
//*/
//
//	if (Class == "19APCS1") return 1;
//	if (Class == "19APCS2") return 2;
//	if (Class == "19CLC1") return 3;
//	if (Class == "19CLC2") return 4;
//	if (Class == "19CLC3") return 5;
//	if (Class == "19CLC4") return 6;
//	if (Class == "19CLC5") return 7;
//	if (Class == "19CLC6") return 8;
//	if (Class == "19CLC7") return 9;
//	if (Class == "19CLC8") return 10;
//	if (Class == "19CLC9") return 11;
//	if (Class == "19CLC10") return 12;
//	return 0;// wrong class code
//}


//void LoadStudentinClass(ifstream& fin, Stu*& a, int& NumofStu) {
//	fin >> NumofStu;
//
//	if (NumofStu == 0) {
//		return;
//	}
//
//	// alocate new array of student
//	a = new Stu[NumofStu];
//
//	fin.ignore();// get rid of the "\n"
//	for (int i = 0; i < NumofStu; i++) {
//		getline(fin, a[i].Fullname);
//		getline(fin, a[i].ID);
//		getline(fin, a[i].Password);
//		getline(fin, a[i].DoB);
//		fin.ignore();// skip the empty line
//	}
//}


void EditExsitingStudent(string ID, Stu*& a, ifstream& fin, int NumofStu) {
	cout << "Enter student ID: ";
	getline(cin, ID);
	int i = 0;
	while (a[i].ID != ID)
	{
		i++;
		if (i > NumofStu)
		{
			break;
		}
	}
	if (i > NumofStu)
	{
		cout << "Cant not find student" << endl;
		EditExsitingStudent(ID, a, fin, NumofStu);
	}
	else {
		cout << "Edit Name of student: ";
		getline(cin, a[i].Fullname);
		cout << "Edit ID of student: ";
		getline(cin, a[i].ID);
		cout << "Edit Password of student: ";//in case when student forget password so staff can help
		getline(cin, a[i].Password);
		cout << "Edit Date of birth of student(YY-MM-DD): ";
		getline(cin, a[i].DoB);
	}
}

void saveEditStudent(ofstream& fout, Stu*& a, int NumofStu)
{
	fout << NumofStu << endl;
	for (int i = 0; i < NumofStu; i++)
	{
		fout << a[i].Fullname << endl;
		fout << a[i].ID << endl;
		fout << a[i].Password << endl;
		fout << a[i].DoB << endl;
		fout << endl;
	}

}

void EditIntoFile(Stu*& a, string Class)
{
	cout << "Enter class of Student:" << endl;
	cin >> Class;
	int Pos = ClassPos(Class);
	switch (Pos) {
		/*********************************************************
		other case will be filled in later,
		this version use case 7 (19CLC5) just to test the function
		*********************************************************/
		case 1: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19APCS1.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 2: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19APCS2.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 3: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC1.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 4: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC2.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 5: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC3.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 6: {ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC4.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}

		}
		case 7: {
			ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC5.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}
		}
		case 8: {
			ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC6.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}
		}
		case 9: {
			ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC7.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}
		}
		case 10: {
			ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC8.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}
		}
		case 11: {
			ifstream fin;
			ofstream fout;
			int NumofStu = 0;

			string ID;
			fin.open("Student-19CLC9.txt");

			if (!fin.is_open()) {
				cout << "Can not open file" << endl;
			}
			else
			{
				LoadStudent(fin, a, NumofStu);
				EditExsitingStudent(ID, a, fin, NumofStu);
			}
			fin.close();
			fout.open("Student-19CLC5.txt");
			if (!fout.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				saveEditStudent(fout, a, NumofStu);
				fout.close();
			}
		}
	}
}

