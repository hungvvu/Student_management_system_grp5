#include "Declarations.h"

void CSVStudent()
{
	ifstream fin;
	string line;
	int count = 0;

	//Open file first time to count students
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

	cout << "There are " << count << " students in this class." << endl;
	cout << endl;

	fin.close();

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
		getline(fin, StuArr[i].DoB, ',');
		getline(fin, StuArr[i].Gender, ',');
		getline(fin, StuArr[i].Active, '\n');

		cout << "STUDENT " << i + 1  << ": " << endl;
		cout << "Name: " << StuArr[i].Fullname << endl;
		cout << "ID: " << StuArr[i].ID << endl;
		cout << "Class: " << StuArr[i].Class << endl;
		cout << "Date of Birth: " << StuArr[i].DoB << endl;
		cout << "Gender: " << StuArr[i].Gender << endl;
		if (StuArr[i].Active == "0")
		{
			cout << "Active: NO" << endl;
		}
		else
		{
			cout << "Active: YES" << endl;
		}
		cout << endl;
		i++;
	}

	fin.close();

	delete[] StuArr;
}