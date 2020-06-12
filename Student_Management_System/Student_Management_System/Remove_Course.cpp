#include "Declarations.h"

void Load_Schedule_txt(ifstream& fin, FileSchedule*& s, int& counts)
{
	int i = 0;
	counts = 0;
	s = new FileSchedule[20];
	while (!fin.eof())
	{
		getline(fin, s[i].No);
		getline(fin, s[i].courseID);
		getline(fin, s[i].courseName);
		getline(fin, s[i].Class);
		getline(fin, s[i].LUser);
		getline(fin, s[i].LName);
		getline(fin, s[i].Ldegree);
		getline(fin, s[i].Lgender);
		getline(fin, s[i].startdate);
		getline(fin, s[i].enddate);
		getline(fin, s[i].dayofweek);
		getline(fin, s[i].starthour);
		getline(fin, s[i].startminute);
		getline(fin, s[i].endhour);
		getline(fin, s[i].endminute);
		getline(fin, s[i].Room);
		fin.ignore();
		i++;
	}
	counts = i - 1;
}

void RemoveCourseInSchedule(string& CourseID, FileSchedule*& s, int& counts, string& k, ofstream& fout)
{
	int i = 0;
	while (s[i].courseID != CourseID)
	{
		i++;
		if (i > counts)
		{
			break;
		}
	}

	if (i > counts)
	{
		cout << "Cant not find course " << endl;
		return;
	}
	cout << counts << i;
	if (i == counts)
	{
		counts--;
		cout << "\nRemove Course successfully!!!!!" << endl;

	}
	if (i < counts)
	{
		counts = counts - 1;
		for (int j = i; j < counts; j++)
		{
			s[j].courseID = s[j + 1].courseID;
			s[j].courseName = s[j + 1].courseName;
			s[j].Class = s[j + 1].Class;
			s[j].LUser = s[j + 1].LUser;
			s[j].LName = s[j + 1].LName;
			s[j].Ldegree = s[j + 1].Ldegree;
			s[j].Lgender = s[j + 1].Lgender;
			s[j].startdate = s[j + 1].startdate;
			s[j].enddate = s[j + 1].enddate;
			s[j].dayofweek = s[j + 1].dayofweek;
			s[j].starthour = s[j + 1].starthour;
			s[j].startminute = s[j + 1].startminute;
			s[j].endhour = s[j + 1].endhour;
			s[j].endminute = s[j + 1].endminute;
			s[j].Room = s[j + 1].Room;
		}
		cout << "\nRemove Course successfully!!!!!" << endl;
	}
	remove(k.c_str()); //Delete course file
	for (int i = 0; i < counts; i++)
	{
		fout << s[i].No << endl;
		fout << s[i].courseID << endl;
		fout << s[i].courseName << endl;
		fout << s[i].Class << endl;
		fout << s[i].LUser << endl;
		fout << s[i].LName << endl;
		fout << s[i].Ldegree << endl;
		fout << s[i].Lgender << endl;
		fout << s[i].startdate <<endl;
		fout << s[i].enddate << endl;
		fout << s[i].dayofweek << endl;
		fout << s[i].starthour << endl;
		fout << s[i].startminute << endl;
		fout << s[i].endhour << endl;
		fout << s[i].endminute << endl;
		fout << s[i].Room << endl;
		fout << endl;
	}
}


void RemoveCourse(FileSchedule*& s, int& counts, string& k)
{

	counts = 0;
	string x;
	string y;
	string z;
	string f;
	string Class;
	string CourseID;
	cout << "\nEnter academic year(YYYY-YYYY) to remove: " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);
	cout << "\nEnter semester to remove (Ex:HK2):" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class to remove(Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter course ID" << endl;
	getline(cin, CourseID);
	f = x + "-" + y + "-" + "Schedule-" + Class + ".txt"; //2019-2020-HK2-Schedule-19CLC5.txt
	k = x + "-" + y + "-" + Class + "-" + CourseID + "-Student.txt"; // 2019-2020-HK2-19CLC5-CS162-Student.txt
	ifstream fin;
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "Cant remove course ";
	}
	else
	{
		Load_Schedule_txt(fin, s, counts);
		fin.close();
		ofstream fout;
		fout.open(f.c_str());
		if (!fout.is_open())
		{
			cout << "Cant remove course ";
		}
		else
		{
			RemoveCourseInSchedule(CourseID, s, counts, k, fout);
		}
	}
}

