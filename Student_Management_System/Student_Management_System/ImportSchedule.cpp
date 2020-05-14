#include "Declarations.h"

void ImportSchedule(ifstream fin)
{
	string x;
	string y;
	string z;
	string Class;
	cout << "Enter academic year(YYYY-YYYY): " << endl;
	string x;
	getline(cin, x);
	cout << "\nEnter semester:" << endl;
	getline(cin, y);
	cout << "Enter class" << endl;
	getline(cin, Class);
	cout << "\nEnter file Schedule Name:" << endl;
	getline(cin, z);
	//x = "string";
	//x = x + ".txt";
	x = x + "-" + y + "-" + "Schedule" + Class + ".txt"; //x for example 2019-2020-19CLC5.txt
	ofstream Schedule;
	Schedule.open(x.c_str());
	if (!Schedule.is_open())
		cout << "Cant open file:";
	else
	{

	}
	

}