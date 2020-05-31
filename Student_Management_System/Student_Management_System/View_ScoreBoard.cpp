#include "Declarations.h"
void readcoursefile(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays)
{
	fin >> NumofStu;
	fin.ignore();
	a = new FileCourse * [100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = new FileCourse[100];
	}
	for (int i = 0; i < NumofStu; i++)
	{
		countdays = 0;
		getline(fin, a[i][0].Name);
		getline(fin, a[i][0].ID);
		getline(fin, a[i][0].Password);
		getline(fin, a[i][0].DoB);
		getline(fin, a[i][0].active);
		getline(fin, a[i][0].miterm);
		getline(fin, a[i][0].final);
		getline(fin, a[i][0].bonus);
		getline(fin, a[i][0].total);
		getline(fin, a[i][0].learning);
		int j = 1;
		while (getline(fin, a[i][j].learning) && a[i][j].learning != "")
		{
			j++;
		}
		countdays = j;
	}
}

void printoutscore(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays)
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
	f = x + "-" + y + "-" + Class+"-"+ course + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CS162-Student.txt
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "Cant open file" << endl;
	}
	else
	{
		readcoursefile(fin, a, NumofStu, countdays);
		cout << "Score Board: " << Class << " - " << course << endl;
		cout << "No\tFull Name Students    \tMidterm\t      Final\t\   Bonus\t    Total\n";
		for (int i = 0; i < NumofStu; i++)
		{
			/*cout << "No\tFull Name Students    \tMidterm\t      Final\t\   Bonus\t    Total\n";*/
			cout << i + 1 << "\t" << a[i][0].Name;
			cout << "\t" << "          " << a[i][0].miterm;
			cout << "\t" << "       " << a[i][0].final;
			cout << "\t" << "    " << a[i][0].bonus;
			cout << "\t" << "             " << a[i][0].total << endl << endl;
			/*cout << a[i][25].learning << endl;*/ //0-25
		}
	}
	delete[] a;
}