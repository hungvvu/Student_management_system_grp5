#include "Declarations.h"

void ViewStudent()
{
	ifstream fin;
	string line;
	int count = 0;

	//Open file first time to count students
	fin.open("Student-19CLC5.txt");

	if (!fin.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	while (getline(fin, line))
	{
		count++;
	}

	cout << "There are " << count << " students in this class." << endl;
	cout << endl;

	fin.close();

	//Open file second time to input students into array
	fin.open("Student-19CLC5.txt");

	Stu* StuArr;
	StuArr = new Stu[count];

	int i = 0;

	while (fin.good() && i < count)
	{
		getline(fin, StuArr[i].Fullname, ',');
		getline(fin, StuArr[i].ID, ',');
		getline(fin, StuArr[i].Password, ',');
		getline(fin, StuArr[i].DoB, ',');

		cout << "STUDENT " << i + 1 << ": " << endl;
		cout << "Name: " << StuArr[i].Fullname << endl;
		cout << "ID: " << StuArr[i].ID << endl;
		cout << "Class: " << StuArr[i].Class << endl;
		cout << "Password: " << StuArr[i].Password << endl;
		cout << "Date of Birth: " << StuArr[i].DoB << endl;
	}

	fin.close();

	delete[] StuArr;
}