#include "Declarations.h"

int ExportScoreCSV()
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

	int count;
	fin >> count;
	fin.ignore();

	FileCourse* arr = new FileCourse[count];
	string s;
	int i = 0;
	int n = CountDate(a, b, c, Class);

	while (!fin.eof() && i < count)
	{
		getline(fin, s);
		getline(fin, arr[i].ID);
		getline(fin, s); getline(fin, s); getline(fin, s);
		getline(fin, arr[i].miterm);
		getline(fin, arr[i].final);
		getline(fin, arr[i].bonus);
		getline(fin, arr[i].total);
		for (int j = 0; j < (n - 1); j++)
		{
			getline(fin, s);
		}
		getline(fin, s);
		i++;
	}

	fin.close();

	ofstream fout;
	string csv;
	csv = a + "-" + b + "-" + Class + "-" + c + "-Score.csv"; //f for example 2019-2020-HK2-19CLC5-CM101-Score.csv
	fout.open(csv.c_str());

	fout << "ID,Midterm,Final,Bonus,Total" << endl;
	for (int i = 0; i < count; i++)
	{
		fout << arr[i].ID << ",";
		fout << arr[i].miterm << ",";
		fout << arr[i].final << ",";
		fout << arr[i].bonus << ",";
		fout << arr[i].total << endl;
	}

	cout << "EXPORT SCORE SUCCESSFULLY !" << endl;

	fout.close();

	delete[] arr;
	return 0;
}