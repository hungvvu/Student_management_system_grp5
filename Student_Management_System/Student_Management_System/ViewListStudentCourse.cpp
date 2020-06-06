#include "Declarations.h"

void printoutStuinfo(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays)
{
	string x;
	string y;
	string course;
	string f;
	string Class;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter course (Ex:CS162) " << endl;//19CLC5-Schedule.csv
	getline(cin, course);

	//x = "string";
	//x = x + ".txt";
	f = x + "-" + y + "-" + Class + "-" + course + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CS162-Student.txt
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "Cant open file" << endl;
		return;
	}
	else
	{
		readcoursefile(fin, a, NumofStu, countdays);
		cout << "Student Info: " << Class << " - " << course << endl;
		cout << "No\tID\t        Full Name   \t      DoB\t\          Active\n";
		for (int i = 0; i < NumofStu; i++)
		{
			/*cout << "No\tFull Name Students    DoB\t\          Active\n;*/

			cout << i + 1 << "\t" << a[i][0].ID;
			cout << "\t" << a[i][0].Name;
			cout << "\t" << "      " << a[i][0].DoB;
			if (a[i][0].active == "0")
			{
				cout << "\t" << "  Inactive" << endl;
			}
			else
				cout << endl;
			/*cout << a[i][25].learning << endl;*/ //0-25
		}
	}
	cout << endl;

	delete[] a;
}