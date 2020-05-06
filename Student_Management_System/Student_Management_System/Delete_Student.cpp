#include "Declarations.h"

void Delete()
{
	ifstream fin;
	fin.open("Student-19CLC5.txt");

	if (!fin)
	{
		cout << "Can't open file !" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		ofstream fout;
		fout.open("temp.txt");

		if (!fout)
		{
			cout << "Can't open file !" << endl;
			system("pause");
			exit(-1);
		}
		else
		{
			int num;
			fin >> num;
			fin.ignore();

			fout << num - 1 << endl;

		}
	}
}