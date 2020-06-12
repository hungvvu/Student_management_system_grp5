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

	//Enter Student ID
	string ID;
	cout << "Enter Student ID: " << endl;
	getline(cin, ID);
	bool check = false;

	int count;
	fin >> count;
	fin.ignore();

	ofstream fout;
	string s;
	fout.open("temp.txt");

	fout << count << endl;

	FileCourse* stu = new FileCourse[count];
	int i = 0, k;
	int n = CountDate(a, b, c, Class);

	while (!fin.eof() && i < count)
	{
		getline(fin, stu[i].Name);
		fout << stu[i].Name << endl;
		getline(fin, stu[i].ID);
		fout << stu[i].ID << endl;
		getline(fin, stu[i].Password);
		fout << stu[i].Password << endl;
		getline(fin, stu[i].DoB);
		fout << stu[i].DoB << endl;
		//Active condition (0 if inactive)
		getline(fin, stu[i].active);
		if (stu[i].ID == ID)
		{
			stu[i].active = "0";
			check = true;
			k = i;
		}
		fout << stu[i].active << endl;
		//
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

	cout << endl;

	if (check == true)
	{
		cout << "Student " << stu[k].Name << " (" << stu[k].ID <<  ") is removed from course " << c << endl;
	}
	else
	{
		cout << "Student ID " << ID << " does not exist in course " << c << endl;
	}

	fout.close();
	fin.close();

	TransferDataFile2(f.c_str());

	delete[] stu;
	return 0;
}

void TransferDataFile2(string course)
{
	ifstream fin;
	fin.open("temp.txt");
	if (!fin)
	{
		cout << "TEMP FILE ERROR !" << endl;
		return;
	}

	ofstream fout;
	fout.open(course);

	string line;
	while (getline(fin, line))
	{
		fout << line << endl;
	}

	fout.close();
	fin.close();
}
