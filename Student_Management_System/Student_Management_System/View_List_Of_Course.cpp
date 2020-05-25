#include "Declarations.h"

void View_List_Of_Course(FileSchedule*& s, int& counts)
{
	counts = 0;
	string x;
	string y;
	string f;
	string Class;
	string CourseID;
	cout << "\nEnter academic year(YYYY-YYYY) to view: " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);
	cout << "\nEnter semester to view:" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class to view" << endl;//19CLC5
	getline(cin, Class);;
	f = x + "-" + y + "-" + "Schedule-" + Class + ".txt"; //2019-2020-HK2-Schedule-19CLC5.txt
	ifstream fin;
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "Cant view course ";
	}
	else
	{
		Load_Schedule_txt(fin, s, counts);
		fin.close();
		cout << "\nList of Course:\n";
		int i = 0;
		do
		{
			cout << i+1 << ". " << s[i].courseID << ":" << s[i].courseName << endl;
			i++;
		} while (i < counts);
	}
}