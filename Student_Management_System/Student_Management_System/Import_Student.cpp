#include "Declarations.h"

void CSVStudent()
{
	ifstream fin;
	ofstream fout;
	string line;
	int count = 0;

	//Input number of students
	fin.open("Import_Student_Info.csv");

	if (!fin.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	while (getline(fin, line))
	{
		count++;
	}

	fin.close();

	fout.open("19CLC5.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << count << endl;

	//Open file second time to input students into array
	fin.open("Import_Student_Info.csv");

	Stu* StuArr;
	StuArr = new Stu[count];

	int i = 0;

	while (fin.good() && i < count)
	{
		getline(fin, StuArr[i].Fullname, ',');
		getline(fin, StuArr[i].ID, ',');
		getline(fin, StuArr[i].Class, ',');
		getline(fin, StuArr[i].DoB, '\n');

		fout << StuArr[i].Fullname << endl;
		fout << StuArr[i].ID << endl;
		fout << StuArr[i].Class << endl;
		fout << StuArr[i].DoB << endl;
		fout << endl;

		i++;
		/*
		cout << "STUDENT " << i + 1 << ": " << endl;
		cout << "Name: " << StuArr[i].Fullname << endl;
		cout << "ID: " << StuArr[i].ID << endl;
		cout << "Class: " << StuArr[i].Class << endl;
		cout << "Date of Birth: " << StuArr[i].DoB << endl;
		cout << endl;
		i++;
		*/
	}

	cout << "IMPORT COMPLETE !" << endl;

	fin.close();
	fout.close();

	delete[] StuArr;
}