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

	fin.close();

	//Create array contains number of students from different class

	int NumOfStu[12]; 
	/*
	12 is the number of class
	    a[0] - 19APCS1
		a[i] - 19APCS2
		a[2] - 19CLC1
		a[3] - 19CLC2
		a[4] - 19CLC3
		a[5] - 19CLC4
		a[6] - 19CLC5
		a[7] - 19CLC6
		a[8] - 19CLC7
		a[9] - 19CLC8
		a[10] - 19CLC9
		a[11] - 19CLC10
	*/
	for (int i = 0; i < 12; i++)
	{
		NumOfStu[i] = 0;
	}

	for (int i = 0; i < countAll; i++)
	{
		string C = StuArr[i].Class;
		int Pos = ClassPos(C);
		switch (Pos)
		{
		case 1://19APCS1
		{
			NumOfStu[0]++;
		}
		case 2://19APCS2
		{
			NumOfStu[1]++;
		}
		case 3://19CLC1
		{
			NumOfStu[2]++;
		}
		case 4://19CLC2
		{
			NumOfStu[3]++;
		}
		case 5://19CLC3
		{
			NumOfStu[4]++;
		}
		case 6://19CLC4
		{
			NumOfStu[5]++;
		}
		case 7://19CLC5
		{
			NumOfStu[6]++;
		}
		case 8://19CLC6
		{
			NumOfStu[7]++;
		}
		case 9://19CLC7
		{
			NumOfStu[8]++;
		}
		case 10://19CLC8
		{
			NumOfStu[9]++;
		}
		case 11://19CLC9
		{
			NumOfStu[10]++;
		}
		case 12://19CLC10
		{
			NumOfStu[11]++;
		}
		}
	}

	//**************** Create 19APCS1 file *******************
	fout.open("19APCS1.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[0] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS1")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19APCS2 file *******************
	fout.open("19APCS2.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[1] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS2")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC1 file *******************
	fout.open("19CLC1.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[2] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC1")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC2 file *******************
	fout.open("19CLC2.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[3] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC2")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC3 file *******************
	fout.open("19CLC3.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[4] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC3")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC4 file *******************
	fout.open("19CLC4.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[5] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC4")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC5 file *******************
	fout.open("19CLC5.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[6] << endl;

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
	fout.close();

	//**************** Create 19CLC6 file *******************
	fout.open("19CLC6.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[7] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC6")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC7 file *******************
	fout.open("19CLC7.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[8] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC7")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC8 file *******************
	fout.open("19CLC8.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[9] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC8")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC9 file *******************
	fout.open("19CLC9.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[10] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC9")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC10 file *******************
	fout.open("19CLC10.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << NumOfStu[11] << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC10")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//cout Complete
	cout << "IMPORT COMPLETE !" << endl;

	delete[] StuArr;
}

void AddToStudentTextFile()
{

}