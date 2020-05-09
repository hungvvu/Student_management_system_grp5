#include "Declarations.h"


void LoadFileClass(ifstream &fin,int &NumofClass,School* &a)
{
	fin >> NumofClass;
	if (NumofClass == 0) {
		return;
	}
	a = new School[NumofClass];
	fin.ignore();
	for (int i = 0; i < NumofClass; i++) 
		{
			getline(fin, a[i].Class);
		}
	cout << "\nNumber of Class:" <<NumofClass<< endl;
	for (int i = 0; i < NumofClass; i++)
	{
		cout <<i+1<<". "<< a[i].Class << endl;
	}

}

void ViewListOfClass(ifstream &fin, int& NumofClass, School*& a)
{
	fin.open("Class.txt");
	if(!fin.is_open())
		cout << "Can not open file" << endl;
	else {
		LoadFileClass(fin, NumofClass, a);

		fin.close();
	}

}