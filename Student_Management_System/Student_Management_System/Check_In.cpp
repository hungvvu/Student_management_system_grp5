#include "Declarations.h"


void checkin(ifstream& fin, ofstream& fout, FileCourse**& a, FileCourse**& b, FileSchedule*& s, int& counts, string& username, int& NumofStu, int& countdays)
{
	SYSTEMTIME h;
	GetLocalTime(&h);
	int daysystem = h.wDay;
	int monthsystem = h.wMonth;
	int yearsystem = h.wYear;
	int hoursystem = h.wHour;
	int minutesystem = h.wMinute;
	string x;
	string y;
	string f;
	string Class;
	string ID;
	string CourseID;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter course (Ex:CS162) " << endl;//19CLC5-Schedule.csv
	getline(cin, CourseID);

	string z = x + "-" + y + "-" + Class + "-" + CourseID + "-Student.txt"; //z for example 2019-2020-HK2-19CLC5-CS162-Student.txt
	fin.open(z.c_str());
	if (!fin.is_open())
	{
		cout << "Cant reach Class or Course" << endl;
		return;
	}
	else
	{
		NumofStu = 0;
		countdays = 0;
		readcoursefile(fin, a, NumofStu, countdays);
		fin.close();
		
		int i = 0;
		while (a[i][0].ID != username)
		{
			i++;
			if (i >= NumofStu)
			{
				break;
			}
		}
		if (i >= NumofStu)
		{
			cout << "You dont in Course " << Class << "-" << CourseID << endl;
			return;
		}
		else
		{
			delete[] a;
			fin.open(z.c_str());
			if (!fin.is_open())
			{
				cout << "You dont in this " << Class << "-" << CourseID << endl;
				return;
			}
			else
			{
				cout << Class << "-" << CourseID<<endl;
				readcoursefile2(fin, b, NumofStu, countdays);
				fin.close();
				
				for (int j = 0; j < countdays; j++)
				{
					int daycheck = stoi(b[i][j].day);
					int monthcheck = stoi(b[i][j].month);
					int yearcheck = stoi(b[i][j].year);
					int hourstartcheck = stoi(b[i][j].starthour);
					int minutestartcheck = stoi(b[i][j].startminute);
					int hourendcheck = stoi(b[i][j].endhour);
					int minuteendcheck = stoi(b[i][j].endminute);

					int secondcheck1 = hourstartcheck * 3600 + minutestartcheck * 60; //turn into second for easy checking
					int secondcheck2 = hourendcheck * 3600 + minuteendcheck * 60;
					int secondsystem = hoursystem * 3600 + minutesystem * 60;
					if (daycheck == daysystem&&monthcheck==monthsystem&&yearcheck==yearsystem)
					{
						if (secondsystem>= secondcheck1&& secondsystem<= secondcheck2)
						{
							if (b[i][j].checkin == "1")
							{
								cout << "You are already checkin today: " << b[i][j].day << "/" << b[i][j].month << "/" << b[i][j].year << endl;
							}
							if (b[i][j].checkin == "-1")
							{
								cout << "You are available to checkin today: " << b[i][j].day << "/" << b[i][j].month << "/" << b[i][j].year << endl;
								cout << "Check in complete!!!!" << endl;
								b[i][j].checkin = "1";
							}

							 
						}
						else
						{
							cout << "You are not available to check in" << endl;
						}
						break;
					}
					if (j == countdays - 1 && daycheck != daysystem || monthcheck != monthsystem && yearcheck != yearsystem)
					{
						cout << "Course has not begin yet" << endl;
					}
				}
				fout.open(z.c_str());
				if (!fout.is_open())
				{
					cout << "Cant open file" << endl;
				}
				else
				{
					SaveCheckIntoCourse(fout, b, countdays, NumofStu);
					fout.close();
				}
				

				delete[] b;
				return;
				
				
			}
		}
	}
}

void readcoursefile2(ifstream& fin, FileCourse**& b, int& NumofStu, int& countdays)
{
	fin >> NumofStu;
	fin.ignore();
	b = new FileCourse * [100];
	for (int i = 0; i < 100; i++)
	{
		b[i] = new FileCourse[100];
	}
	for (int i = 0; i < NumofStu; i++)
	{
		getline(fin, b[i][0].Name);
		getline(fin, b[i][0].ID);
		getline(fin, b[i][0].Password);
		getline(fin, b[i][0].DoB);
		getline(fin, b[i][0].active);
		getline(fin, b[i][0].miterm);
		getline(fin, b[i][0].final);
		getline(fin, b[i][0].bonus);
		getline(fin, b[i][0].total);
		for(int j = 0; j < countdays; j++)
		{
			getline(fin, b[i][j].day, ' ');
			getline(fin, b[i][j].month, ' ');
			getline(fin, b[i][j].year, ' ');
			getline(fin, b[i][j].starthour, ' ');
			getline(fin, b[i][j].startminute, ' ');
			getline(fin, b[i][j].endhour, ' ');
			getline(fin, b[i][j].endminute, ' ');
			getline(fin, b[i][j].checkin,'\n');
		}
		fin.ignore();
	}
}

void SaveCheckIntoCourse(ofstream& fout, FileCourse**& b,int &countdays,int &NumofStu)
{
	fout << NumofStu << endl;
	for (int i = 0; i < NumofStu; i++)
	{
		fout << b[i][0].Name << endl;
		fout << b[i][0].ID << endl;
		fout << b[i][0].Password << endl;
		fout << b[i][0].DoB << endl;
		fout << b[i][0].active << endl;
		fout << b[i][0].miterm << endl;
		fout << b[i][0].final << endl;
		fout << b[i][0].bonus << endl;
		fout << b[i][0].total << endl;
		for (int j = 0; j < countdays; j++)
		{
			fout << b[i][j].day << " " << b[i][j].month << " " << b[i][j].year << " " << b[i][j].starthour << " " << b[i][j].startminute << " " << b[i][j].endhour << " " << b[i][j].endminute << " " << b[i][j].checkin << endl;
		}
		fout << endl;
	}
}