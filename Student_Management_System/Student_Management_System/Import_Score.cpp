#include "Declarations.h"

int CountStu(string a, string b, string c, string Class)
{
	ifstream fin;
	string f;
	string scount;
	int count;

	f = a + "-" + b + "-" + Class + "-" + c + "-Student" + ".txt";
	fin.open(f.c_str());
	if (!fin)
	{
		cout << "Student Course file Error !" << endl;
		return -1;
	}

	fin >> count;
	fin.ignore();

	fin.close();
	return count;
}

void ReadScore(ifstream &fin, FileCourse*&a, int &count)
{
	int i = 0;
	fin.ignore(100, '\n');

	while (!fin.eof() && i < count)
	{
		getline(fin, a[i].ID, ',');
		getline(fin, a[i].miterm, ',');
		getline(fin, a[i].final, ',');
		getline(fin, a[i].bonus, ',');
		getline(fin, a[i].total, '\n');
		i++;
	}
}

int CreateScoreTemp(string a, string b, string c, string Class, FileCourse*& course)
{
	ofstream fout;
	fout.open("Score_temp.txt");
	ifstream fin;
	string f;
	int count;
	string s;

	f = a + "-" + b + "-" + Class + "-" + c + "-Student" + ".txt";
	fin.open(f.c_str());
	if (!fin)
	{
		cout << "Student Course file Error !" << endl;
		return -1;
	}

	fin >> count;
	fin.ignore();
	fout << count << endl;
	int i = 0;

	while (!fin.eof() && i < count)
	{
		getline(fin, course[i].Name);
		fout << course[i].Name << endl;
		getline(fin, course[i].ID);
		fout << course[i].ID << endl;
		getline(fin, course[i].Password);
		fout << course[i].Password << endl;
		getline(fin, course[i].DoB);
		fout << course[i].DoB << endl;
		getline(fin, course[i].active);
		fout << course[i].active << endl;
		//Test cout
		cout << course[i].Name << endl;
		cout << course[i].ID << endl;
		cout << course[i].Password << endl;
		cout << course[i].DoB << endl;
		cout << course[i].active << endl;
		//
		getline(fin, s); getline(fin, s); getline(fin, s);	getline(fin, s);
		fout << course[i].miterm << endl;
		fout << course[i].final << endl;
		fout << course[i].bonus << endl;
		fout << course[i].total << endl;
		for (int j = 0; j < 29; j++)
		{
			getline(fin, s);
			cout << s << endl;
			fout << s << endl;
		}
		getline(fin, s);
		i++;
	}

	/*
	for (int k = 0; k < count; k++)
	{
		fout << course[i].Name << endl;
		fout << course[i].ID << endl;
		fout << course[i].Password << endl;
		fout << course[i].DoB << endl;
		fout << course[i].active << endl;
		fout << course[i].miterm << endl;
		fout << course[i].final << endl;
		fout << course[i].bonus << endl;
		fout << course[i].total << endl;
		fout << endl;
	}
	*/

	fin.close();
	fout.close();
}

int ImportScore()
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
	cout << "Enter Course ID:" << endl;
	getline(cin, c);

	f = a + "-" + b + "-" + Class + "-" + c + "-Score" +  ".csv"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

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

			f = a + "-" + b + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

			fin.open(f.c_str());
		}
	}

	int count = CountStu(a, b, c, Class);

	FileCourse* scorearr = new FileCourse[count];

	ReadScore(fin, scorearr, count);

	fin.close();

	CreateScoreTemp(a, b, c, Class, scorearr);
	
	/*
	for (int i = 0; i < count; i++)
	{
		cout << scorearr[i].ID << " ";
		cout << scorearr[i].miterm << " ";
		cout << scorearr[i].final << " ";
		cout << scorearr[i].bonus << " ";
		cout << scorearr[i].total << endl;
	}
	*/
	delete[] scorearr;

	return 0;
}