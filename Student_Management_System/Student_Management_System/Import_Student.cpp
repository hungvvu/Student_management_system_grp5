#include "Declarations.h"

void CSVStudent()
{
	ifstream fin;
	ofstream fout;
	string line;
	int countAll = 0;

	//Open file first time to input number of all students in this csv file
	fin.open("Import_Student_Info.csv");

	if (!fin.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	while (getline(fin, line))
	{
		countAll++;
	}

	fin.close();

	fout.open("19CLC5.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	//Open file second time to input students into array
	fin.open("Import_Student_Info.csv");

	Stu* StuArr;
	StuArr = new Stu[countAll];

	int i = 0;

	while (fin.good() && i < countAll)
	{
		getline(fin, StuArr[i].Class, ',');
		getline(fin, StuArr[i].Fullname, ',');
		getline(fin, StuArr[i].ID, ',');
		getline(fin, StuArr[i].DoB, '\n');

		i++;
	}

	int count = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC5")
		{
			count++;
		}
	}

	fout << count << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC5")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}

	cout << "IMPORT COMPLETE !" << endl;

	fin.close();
	fout.close();

	delete[] StuArr;
}