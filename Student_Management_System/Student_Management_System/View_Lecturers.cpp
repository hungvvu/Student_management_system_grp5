#include "Declarations.h"

void View_ALL_Lecturers(ifstream& fin,Lect*& a,int &NumofLect)
{
	NumofLect = 0;
	fin.open("Lecturer.txt");
	if (!fin.is_open())
	{
		cout << "Cant open file Lecturer.txt" << endl;
	}
	else
	{
		LoadLect(fin, a, NumofLect);
		cout << "\nList of Lecturer:"<<endl;
		for (int i = 0; i < NumofLect; i++)
		{
			string s;
			if (a[i].Sex == 1)
			{
				s = "Mrs";
			}
			else s = "Mr";
			cout << i+1 << ". " << s <<"."<< a[i].Name << ", Degree:" <<a[i].Degree <<endl ;
		}
		cout << endl;
		delete[] a;
	}
	fin.close();
}