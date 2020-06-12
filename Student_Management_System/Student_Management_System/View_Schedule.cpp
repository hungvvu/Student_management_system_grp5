#include "Declarations.h"

int ViewSchedule(string &username)
{
	string Class;
	/*
	ifstream classfile;
	classfile.open("Student.txt");

	int count;
	classfile >> count;
	classfile.ignore();
	Stu* arr = new Stu[count];
	string s;
	bool check = false;

	int i = 0, k;
	while (!classfile.eof() && i < count)
	{
		getline(classfile, s);
		getline(classfile, arr[i].ID);
		if (arr[i].ID == username)
		{
			check = true;
			k = i;
		}
		getline(classfile, s);	getline(classfile, s);	
		getline(classfile, arr[i].Class);	
		getline(classfile, s);
	}

	Class = arr[k].Class;

	delete[] arr;
	classfile.close();
	*/

	ifstream fin;
	string a, b, f;
	int menu = 0;

	cout << "Enter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, a);

	cout << "Enter semester:" << endl;//HK2
	getline(cin, b);

	cout << "Enter Class:" << endl;//19CLC5
	getline(cin, Class);

	f = a + "-" + b + "-Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

	fin.open(f.c_str());
	while (!fin || menu == 1)
	{
		cout << "INPUT ERROR !" << endl;
		cout << "Press 0 to re-enter or Press 1 to return to menu: "; cin >> menu;
		while (menu < 0 || menu > 1)
		{
			cout << "Press 0 to re-enter or Press 1 to return to menu: "; cin >> menu;
		}
		if (menu == 1)
		{
			return 1;
		}
		else
		{
			cout << "Enter academic year(YYYY-YYYY): " << endl;//2019-2020
			cin.ignore();
			getline(cin, a);

			cout << "Enter semester:" << endl;//HK2
			getline(cin, b);

			f = a + "-" + b + "-Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

			fin.open(f.c_str());
		}
	}

	FileSchedule* schedule;
	int count = 0;

	Load_Schedule_txt(fin, schedule, count);

	cout << endl;
	cout << "NOTE: " << endl;

	for (int j = 0; j < count; j++)
	{
		cout << schedule[j].courseID << ": " << schedule[j].courseName << endl;
	}

	cout << endl;
	cout << "No\tCourseID\tLect. Name\t    Start Date\t    End Date\t    Day of Week\t    Start Time\t    End Time\t    Room     \n" << endl;
	for (int j = 0; j < count; j++)
	{
		cout << schedule[j].No << "\t";
		cout << schedule[j].courseID << "\t";
		cout << "        " << schedule[j].LName << "\t";
		cout << "    " << schedule[j].startdate << "\t";
		cout << "    " << schedule[j].enddate << "\t";
		cout << "    " << schedule[j].dayofweek << "\t";
		cout << "            " << schedule[j].starthour << ":" << schedule[j].startminute << "\t";
		cout << "    " << schedule[j].endhour << ":" << schedule[j].endminute << "\t";
		cout << "    " << schedule[j].Room << endl;
	}
	
	delete[] schedule;
	fin.close();

	return 0;
}