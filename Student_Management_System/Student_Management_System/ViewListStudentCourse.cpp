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
	string check;

	for (int i = 0; i < numofstu; i++)
	{
		getline(fin, SArray[i].Fullname);
		getline(fin, SArray[i].ID);
		getline(fin, SArray[i].Password);
		getline(fin, SArray[i].DoB);
		fin >> active[i]; fin.ignore();
		getline(fin, check);
		while (check != "")
		{
			fin.ignore(15, '-1');
			getline(fin, check);
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
}