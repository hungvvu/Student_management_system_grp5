#include "Declarations.h"


void checkin(ifstream& fin, ofstream& fout, FileCourse**& a, FileCourse**& b, FileSchedule*& s, int& counts, string& username, int& NumofStu, int& countdays)
{
	SYSTEMTIME h;
	GetLocalTime(&h);
	int daysystem = h.wDay;
	int monthsystem = h.wMonth;
	int yearsystem = h.wYear;
	int hoursystem = h.wHour;
	int minutesystem = h.wMinute;
	string x;
	string y;
	string f;
	string Class;
	string ID;
	string CourseID;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter course (Ex:CS162) " << endl;//19CLC5-Schedule.csv
	getline(cin, CourseID);

	string z = x + "-" + y + "-" + Class + "-" + CourseID + "-Student.txt"; //z for example 2019-2020-HK2-19CLC5-CS162-Student.txt
	fin.open(z.c_str());
	if (!fin.is_open())
	{
		cout << "Cant reach Class or Course" << endl;
		return;
	}
	else
	{
		NumofStu = 0;
		countdays = 0;
		readcoursefile(fin, a, NumofStu, countdays);
		fin.close();
		
		int i = 0;
		while (a[i][0].ID != username)
		{
			i++;
			if (i >= NumofStu)
			{
				break;
			}
		}
		if (i >= NumofStu)
		{
			cout << "You dont in Course " << Class << "-" << CourseID << endl;
			return;
		}
		else
		{
			delete[] a;
			fin.open(z.c_str());
			if (!fin.is_open())
			{
				cout << "You dont in this " << Class << "-" << CourseID << endl;
				return;
			}
			else
			{
				cout << Class << "-" << CourseID<<endl;
				readcoursefile2(fin, b, NumofStu, countdays);
				fin.close();
				cout << b[3][0].Name;
				
				return;
				
				//delete[] b;
			}
		}
	}
}

void readcoursefile2(ifstream& fin, FileCourse**& b, int& NumofStu, int& countdays)
{
	fin >> NumofStu;
	fin.ignore();
	b = new FileCourse * [100];
	for (int i = 0; i < 100; i++)
	{
		b[i] = new FileCourse[100];
	}
	for (int i = 0; i < NumofStu; i++)
	{
		getline(fin, b[i][0].Name);
		getline(fin, b[i][0].ID);
		getline(fin, b[i][0].Password);
		getline(fin, b[i][0].DoB);
		getline(fin, b[i][0].active);
		getline(fin, b[i][0].miterm);
		getline(fin, b[i][0].final);
		getline(fin, b[i][0].bonus);
		getline(fin, b[i][0].total);
		for(int j = 0; j < countdays; j++)
		{
			getline(fin, b[i][j].day, ' ');
			getline(fin, b[i][j].month, ' ');
			getline(fin, b[i][j].year, ' ');
			getline(fin, b[i][j].starthour, ' ');
			getline(fin, b[i][j].startminute, ' ');
			getline(fin, b[i][j].endhour, ' ');
			getline(fin, b[i][j].endminute, ' ');
			getline(fin, b[i][j].checkin,'\n');
		}
		fin.ignore();
	}
}