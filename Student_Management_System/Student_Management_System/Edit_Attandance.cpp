#include "Declarations.h"

void Edit_Attandance(ifstream& fin, ofstream& fout, FileCourse**& a, FileSchedule*& s, int& counts, string& username, int& NumofStu, int& countdays)
{
	string x;
	string y;
	string f;
	string Class;
	string ID;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	//cout << "\nEnter course (Ex:CS162) " << endl;//19CLC5-Schedule.csv
	//getline(cin, course);


	f = x + "-" + y + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "\nCant find Class" << endl;
		fin.close();
		return;
	}
	else
	{
		counts = 0;
		Load_Schedule_txt(fin, s, counts);
		fin.close();
		int i = 0;
		while (s[i].LUser != username)
		{
			i++;
			if (i > counts)
			{
				break;
			}
		}
		if (i > counts)
		{
			cout << "\nYou do not teach " << Class << " class " << endl;
			return;

		}
		else {
			string CourseID = s[i].courseID;
			string courseName = s[i].courseName;
			cout << "\nYou teach " << CourseID << "-" << courseName << " in " << Class << endl;
			string z = x + "-" + y + "-" + Class + "-" + CourseID + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CS162-Student.txt
			fin.open(z.c_str());
			if (!fin.is_open())
			{
				cout << "Cant open file Course" << endl;
			}
			else {
				NumofStu = 0;
				countdays = 0;
				readcoursefile2(fin, a, NumofStu, countdays);
				fin.close();
				cout << "Enter ID of Student:" << endl;
				getline(cin, ID);
				i = 0;
				while (a[i][0].ID != ID)
				{
					i++;
					if (i >= NumofStu)
					{
						break;
					}
				}
				if (i >= NumofStu)
				{
					cout << "\nCant find student " << Class << " class " << endl;
					return;

				}
				else {
					cout << "countdays is:" << countdays << endl;
					cout << a[i][0].ID << "-" << a[i][0].Name << endl;
					int h = 1;
					for (int j = 0; j < countdays; j++)
					{
						cout << h << ". " << a[i][j].day <<" "<< a[i][j].month <<" "<< a[i][j].year <<" "<< a[i][j].starthour <<" "<< a[i][j].startminute <<" "<< a[i][j].endhour <<" "<< a[i][j].endminute <<" "<< a[i][j].attend << endl;
						h++;
						//if (h > countdays)
						//{
						//	break;
						//}
					}
					int choicedate;
					cout << "Enter day you want to Edit(Ex: 1)" << endl;
					cin >> choicedate;
					while (choicedate > countdays&& choicedate < 1)
					{
						cout << "Cant find the day you choose\nChoose again" << endl;
						cin >> choicedate;
					}
					cout << "Date:" << a[i][choicedate-1].day << a[i][choicedate - 1].month << a[i][choicedate - 1].year << a[i][choicedate - 1].starthour << a[i][choicedate - 1].startminute << a[i][choicedate - 1].endhour << a[i][choicedate - 1].endminute << a[i][choicedate - 1].attend << endl;


					delete[] a;
					delete[] s;
 				}
			}
		}
	}
}

void readcoursefile2(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays) //to read seperately from check in
{
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
		getline(fin, a[i][0].day,'\0');
		getline(fin, a[i][0].month, '\0');
		getline(fin, a[i][0].year, '\0');
		getline(fin, a[i][0].starthour, '\0');
		getline(fin, a[i][0].startminute, '\0');
		getline(fin, a[i][0].endhour, '\0');
		getline(fin, a[i][0].endminute, '\0');
		getline(fin, a[i][0].attend, '\n');
		int j = 1;
		while (getline(fin, a[i][j].day, '\0')&& getline(fin, a[i][j].month, '\0')&& getline(fin, a[i][0].year, '\0')&& getline(fin, a[i][0].starthour, '\0') && getline(fin, a[i][0].startminute, '\0')&& getline(fin, a[i][0].endhour, '\0') && getline(fin, a[i][0].endminute, '\0') && getline(fin, a[i][0].attend, '\n') &&a[i][j].day != "")
		{
			j++;
		}
		countdays = j;
	}
}