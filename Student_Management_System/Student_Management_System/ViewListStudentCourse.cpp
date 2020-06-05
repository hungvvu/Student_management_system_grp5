#include "Declarations.h"

int ViewListStuCourse()
{
	string f, AcaYear, Semester, Class, CourseID;

	cout << "Enter Academic Year (yyyy-yyyy): "; cin.ignore(); getline(cin, AcaYear);
	cout << "Enter Semester (HKn): "; getline(cin, Semester);
	cout << "Enter Class: "; getline(cin, Class);
	cout << "Enter Course ID: "; getline(cin, CourseID);

	f = AcaYear + "-" + Semester + "-" + Class + "-" + CourseID + "-Student.txt";

	ifstream fin;
	fin.open(f.c_str());
	int choice;
	while (!fin)
	{
		cout << "INPUT ERROR !" << endl;
		cout << "Press 0 to re-enter / Press 1 to return to menu: "; cin >> choice;
		while (choice < 0 || choice > 1)
		{
			cout << "Press 0 to re-enter / Press 1 to return to menu: "; cin >> choice;
		}
		if (choice == 1)
		{
			return 1;
		}
		else
		{
			cout << "Enter Academic Year (yyyy-yyyy): "; cin.ignore(); getline(cin, AcaYear);
			cout << "Enter Semester (HKn): "; getline(cin, Semester);
			cout << "Enter Class: "; getline(cin, Class);
			cout << "Enter Course ID: "; getline(cin, CourseID);

			f = AcaYear + "-" + Semester + "-" + Class + "-" + CourseID + "-Student.txt";

			fin.open(f.c_str());
		}
	}

	int numofstu;
	fin >> numofstu;
	fin.ignore();

	cout << "There are " << numofstu << " students in this course." << endl;
	cout << endl;

	Stu* SArray = new Stu[numofstu];
	int* active = new int [numofstu];
	int* date = new int * 100;
	
	string check;

	for (int i = 0; i < numofstu; i++)
	{
		getline(fin, SArray[i].Fullname);
		getline(fin, SArray[i].ID);
		getline(fin, SArray[i].Password);
		getline(fin, SArray[i].DoB);
		fin >> active[i]; fin.ignore();
		
		getline(fin, date[i][0].learning);
		int j = 1;
		while (getline(fin, a[i][j].learning) && a[i][j].learning != "")
		{
			j++;
		}

		fin.ignore();// skip the empty line
	}

	for (int i = 0; i < numofstu; i++)
	{
		cout << SArray[i].Fullname << endl;
		cout << SArray[i].ID << endl;
		cout << SArray[i].Password << endl;
		cout << SArray[i].DoB << endl;
		cout << active[i] << endl;
		cout << endl;
	}

	delete[] active;
	delete[] SArray;

	fin.close();

	return 0;

	fin >> NumofStu;
	fin.ignore();
	a = new FileCourse * [100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = new FileCourse[100];
	}
	for (int i = 0; i < NumofStu; i++)
	{
		countdays = 0;
		getline(fin, a[i][0].Name);
		getline(fin, a[i][0].ID);
		getline(fin, a[i][0].Password);
		getline(fin, a[i][0].DoB);
		getline(fin, a[i][0].active);
		getline(fin, a[i][0].miterm);
		getline(fin, a[i][0].final);
		getline(fin, a[i][0].bonus);
		getline(fin, a[i][0].total);
		getline(fin, a[i][0].learning);
		int j = 1;
		while (getline(fin, a[i][j].learning) && a[i][j].learning != "")
		{
			j++;
		}
		countdays = j;
	}

}