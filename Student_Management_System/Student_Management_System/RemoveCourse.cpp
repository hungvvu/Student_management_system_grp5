#include "Declarations.h"

void RemoveCourse(FileSchedule*& s)
{
	string x;
	string y;
	string z;
	string f;
	string Class;
	cout << "\nEnter academic year(YYYY-YYYY) to remove: " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);
	cout << "\nEnter semester to remove:" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class to remove" << endl;//19CLC5
	getline(cin, Class);
	ifstream fin;
	
	
}