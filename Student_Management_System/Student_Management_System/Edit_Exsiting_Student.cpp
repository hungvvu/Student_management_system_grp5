#include "Declarations.h"



void LoadStudentinClass(ifstream& fin, Stu*& a, int& NumofStu) {
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
		fin.ignore();// skip the empty line
	}
}


void EditExsitingStudent(string& ID, Stu*& a, ifstream& fin, int NumofStu, int& x) {
	//cout << "Enter student ID: ";
	//cin.ignore();
	//getline(cin, ID);
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
		cout << "Cant not find student. ";
		return;
		//cin.ignore();
		//cout << "Enter student ID: ";
		//cin.ignore();
		//getline(cin, ID);
		//EditExsitingStudent(ID, a, fin, NumofStu, x);
	}
	else {
		int x = i; //Save x for later
		cout <<"\nName: "<< a[i].Fullname << endl;
		cout << "ID: " << a[i].ID << endl;
		cout << "Password: " << a[i].Password << endl;
		cout << "DoB: " << a[i].DoB << endl;

		cout << "\nEdit Name of student: ";
		getline(cin, a[i].Fullname);
		cout << "Edit ID of student: ";
		getline(cin, a[i].ID);
		cout << "Edit Password of student: ";//in case when student forget password so staff can help
		getline(cin, a[i].Password);
		cout << "Edit Date of birth of student(YYYY-MM-DD): ";
		getline(cin, a[i].DoB);
		cout << "\nEdit Successfully" << endl;
	}
}

void save(ofstream& fout, Stu*& a, int NumofStu)
{
	fout << NumofStu << endl;//stream ko cho phep copy
	for (int i = 0; i < NumofStu; i++)
	{
		fout << a[i].Fullname << endl;
		fout << a[i].ID << endl;
		fout << a[i].Password << endl;
		fout << a[i].DoB << endl;
		fout << endl;
	}

}

void save2(ofstream& fout2, Stu*& a, int NumofStu, string& ID, Stu*& b, int x)
{
	int k = 0;
	while (b[k].ID != ID)
	{
		k++;
		if (k > NumofStu)
		{
			break;
		}
	}
	b[k].Fullname = a[x].Fullname;
	b[k].ID = a[x].ID;
	b[k].Password = a[x].Password;
	b[k].DoB = a[x].DoB;




	fout2 << NumofStu << endl;//stream ko cho phep copy
	for (int i = 0; i < NumofStu; i++)
	{
		fout2 << b[i].Fullname << endl;
		fout2 << b[i].ID << endl;
		fout2 << b[i].Password << endl;
		fout2 << b[i].DoB << endl;
		fout2 << b[i].Class << endl;
		fout2 << endl;
	}
}

void EditIntoFile(Stu*& a, string Class)
{
	int x = 0;
	cout << "Enter class of Student:" << endl;
	cin >> Class;
	int Pos = ClassPos(Class);
	string k = "Student-" + Class + ".txt";
	//switch (Pos) {

	//case 7: {
	string ID;
	cout << "Enter student ID: ";
	cin.ignore();
	getline(cin, ID);


	ifstream fin;
	ofstream fout;
	int NumofStu = 0;

	/*string ID;*/
	fin.open(k.c_str());

	if (!fin.is_open()) {
		cout << "Can not open file" << endl;
	}
	else
	{
		LoadStudentinClass(fin, a, NumofStu);
		EditExsitingStudent(ID, a, fin, NumofStu, x);
	}
	fin.close();
	fout.open(k.c_str());
	if (!fout.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else {
		save(fout, a, NumofStu);
		fout.close();



		ifstream fin2;
		ofstream fout2;
		Stu* b;
		fin2.open("Student.txt");
		if (!fin2.is_open())
		{
			cout << "Can not open file" << endl;
		}
		else {
			LoadStudent(fin2, b, NumofStu);
			fout2.open("Student.txt");
			if (!fout2.is_open())
			{
				cout << "Can not open file" << endl;
			}
			else {
				save2(fout2, a, NumofStu, ID, b, x);

			}
		}
	}
}


//#include "Declarations.h"
////int ClassPos(string Class) {/* function to return the position of a class in the following list:
////1-19APCS1
////2-19APCS2
////3-19CLC1
////4-19CLC2
////5-19CLC3
////6-19CLC4
////7-19CLC5
////8-19CLC6
////9-19CLC7
////10-19CLC8
////11-19CLC9
////12-19CLC10
////*/
////
////	if (Class == "19APCS1") return 1;
////	if (Class == "19APCS2") return 2;
////	if (Class == "19CLC1") return 3;
////	if (Class == "19CLC2") return 4;
////	if (Class == "19CLC3") return 5;
////	if (Class == "19CLC4") return 6;
////	if (Class == "19CLC5") return 7;
////	if (Class == "19CLC6") return 8;
////	if (Class == "19CLC7") return 9;
////	if (Class == "19CLC8") return 10;
////	if (Class == "19CLC9") return 11;
////	if (Class == "19CLC10") return 12;
////	return 0;// wrong class code
////}
//
//
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
//
//
//void EditExsitingStudent(string ID, Stu*& a, ifstream& fin, int NumofStu) {
//	cout << "\nEnter student ID: "<<endl;
//	cin.ignore();
//	getline(cin, ID);
//	int i = 0;
//	while (a[i].ID != ID)
//	{
//		i++;
//		if (i > NumofStu)
//		{
//			break;
//		}
//	}
//	if (i > NumofStu)
//	{
//		cout << "\nCant not find student. Enter random number to retry: ";
//		cin.ignore();
//		EditExsitingStudent(ID, a, fin, NumofStu);
//	}
//	else {
//		cout << "\nEdit Name of student: ";
//		getline(cin, a[i].Fullname);
//		cout << "Edit ID of student: ";
//		getline(cin, a[i].ID);
//		cout << "Edit Password of student: ";//in case when student forget password so staff can help
//		getline(cin, a[i].Password);
//		cout << "Edit Date of birth of student(YYYY-MM-DD): ";
//		getline(cin, a[i].DoB);
//		cout << "\nEdit Successfully"<<endl;
//	}
//}
//
//void saveEditStudent(ofstream& fout, Stu*& a, int NumofStu)
//{
//	fout << NumofStu << endl;
//	for (int i = 0; i < NumofStu; i++)
//	{
//		fout << a[i].Fullname << endl;
//		fout << a[i].ID << endl;
//		fout << a[i].Password << endl;
//		fout << a[i].DoB << endl;
//		fout << endl;
//	}
//
//}
//
//void EditIntoFile(Stu*& a, string Class)
//{
//	cout << "Enter class of Student:" << endl;
//	cin >> Class;
//	int Pos = ClassPos(Class);
//	if (Pos == 1) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19APCS1.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19APCS1.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 2) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19APCS2.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19APCS2.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 3) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC1.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC1.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 4) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC2.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC2.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 5) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC3.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC3.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 6) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC4.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC4.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//
//	}
//	if (Pos == 7) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC5.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC5.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//	}
//	if (Pos == 8) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC6.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC6.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//	}
//	if (Pos == 9) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC7.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC7.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//	}
//	if (Pos == 10) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC8.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC8.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//	}
//	if (Pos == 11) {
//		ifstream fin;
//		ofstream fout;
//		int NumofStu = 0;
//
//		string ID;
//		fin.open("Student-19CLC9.txt");
//
//		if (!fin.is_open()) {
//			cout << "Can not open file" << endl;
//		}
//		else
//		{
//			LoadStudentinClass(fin, a, NumofStu);
//			EditExsitingStudent(ID, a, fin, NumofStu);
//		}
//		fin.close();
//		fout.open("Student-19CLC9.txt");
//		if (!fout.is_open())
//		{
//			cout << "Can not open file" << endl;
//		}
//		else {
//			saveEditStudent(fout, a, NumofStu);
//			fout.close();
//		}
//	}
//}

