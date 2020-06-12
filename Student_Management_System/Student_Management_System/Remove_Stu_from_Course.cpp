#include "Declarations.h"

int RemoveStufromCourse()
{
	ifstream fin;
	string a, b, c, f, Class;
	int menu = 0;

	cout << "Enter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, a);

	cout << "Enter semester:" << endl;//HK2
	getline(cin, b);
	cout << "Enter class" << endl;//19CLC5
	getline(cin, Class);
	cout << "Enter Course ID: " << endl;//CM101
	getline(cin, c);

	f = a + "-" + b + "-" + Class + "-" + c + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CM101-Student.txt

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
			cout << "Enter class" << endl;//19CLC5
			getline(cin, Class);
			cout << "Enter Course ID: " << endl;//CM101
			getline(cin, c);

			f = a + "-" + b + "-" + Class + "-" + c + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CM101-Student.txt

			fin.open(f.c_str());
		}
	}

	string ID;
	cout << "Enter Student ID: " << endl;
	getline(cin, ID);

	int count;
	fin >> count;
	fin.ignore();

	ofstream fout;
	string s;
	fout.open("temp.txt");

	fout << count << endl;

	FileCourse* stu = new FileCourse[count];
	int i = 0;
	int n = CountDate(a, b, c, Class);

	while (!fin.eof())
	{
		getline(fin, stu[i].Name);
		fout << stu[i].Name << endl;
		getline(fin, stu[i].ID);
		fout << stu[i].ID << endl;
		getline(fin, stu[i].Password);
		fout << stu[i].Password << endl;
		getline(fin, stu[i].DoB);
		fout << stu[i].DoB << endl;
		getline(fin, stu[i].active);
		fout << stu[i].active << endl;
		getline(fin, stu[i].miterm);
		fout << stu[i].miterm << endl;
		getline(fin, stu[i].final);
		fout << stu[i].final << endl;
		getline(fin, stu[i].bonus);
		fout << stu[i].bonus << endl;
		getline(fin, stu[i].total);
		fout << stu[i].total << endl;
		for (int j = 0; j < (n - 1); j++)
		{
			getline(fin, s);
			fout << s << endl;
		}
		getline(fin, s);
		fout << endl;
		i++;
	}

	fout.close();
	fin.close();

	delete[] stu;
	return 0;
}