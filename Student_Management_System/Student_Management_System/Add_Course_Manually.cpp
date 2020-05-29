#include "Declarations.h"

int AddCourseManually()
{
	ifstream fin;
	string course;
	int menu = 0;
	cout << "Enter file course name: "; cin >> course;
	fin.open(course);
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
			cout << "Enter file course name: "; cin >> course;
			fin.open(course);
		}
	}

	FileSchedule newCourse;

	cout << "Enter Course ID: ";
	cin >> newCourse.courseID;
	cin.ignore();
	cout << "Enter Course Name: ";
	getline(cin, newCourse.courseName);
	cout << "Enter Class: ";
	cin >> newCourse.Class;
	cout << "Enter Lecturer Username: ";
	cin >> newCourse.LUser;
	cin.ignore();
	cout << "Enter Lecturer Name: ";
	getline(cin, newCourse.LName);
	cout << "Enter Lecturer Degree: ";
	cin >> newCourse.Ldegree;
	cout << "Enter Lecturer Gender: ";
	cin >> newCourse.Lgender;

	cout << "Enter Start Date (dd/mm/yyyy): ";
	cin >> newCourse.startdateday;
	int d1 = stoi(newCourse.startdateday);
	cin >> newCourse.startdatemonth;
	int m1 = stoi(newCourse.startdatemonth);
	cin >> newCourse.startdateyear;
	int y = stoi(newCourse.startdateyear);
	bool check1, check2;
	check1 = check_month(m1);
	check2 = check_date(d1, m1);
	while ((check1 && check2) == false)
	{
		cout << "DATE ERROR !" << endl;
		cout << "Enter Start Date (dd/mm/yyyy): ";
		cin >> newCourse.startdateday;
		d1 = stoi(newCourse.startdateday);
		cin >> newCourse.startdatemonth;
		m1 = stoi(newCourse.startdatemonth);
		cin >> newCourse.startdateyear;
		check1 = check_month(m1);
		check2 = check_date(d1, m1);
	}

	cout << "Enter End Date (dd/mm/yyyy): ";
	cin >> newCourse.enddateday;
	int d2 = stoi(newCourse.enddateday);
	cin >> newCourse.enddatemonth;
	int m2 = stoi(newCourse.enddatemonth);
	cin >> newCourse.enddateyear;
	bool check3, check4;
	check3 = check_month(m2);
	check4 = check_date(d2, m2);
	while ((check3 && check4) == false)
	{
		cout << "DATE ERROR !" << endl;
		cout << "Enter End Date (dd/mm/yyyy): ";
		cin >> newCourse.enddateday;
		d2 = stoi(newCourse.enddateday);
		cin >> newCourse.enddatemonth;
		m2 = stoi(newCourse.enddatemonth);
		cin >> newCourse.enddateyear;
		check3 = check_month(m2);
		check4 = check_date(d2, m2);
	}

	string day;
	cout << "Enter weekday (MON, TUE, WED, THUR, FRI, SAT): ";
	cin >> day;
	string a[] = { "MON", "TUE", "WED", "THUR", "FRI", "SAT" };
	bool cday = false;
	while (cday == false)
	{
		for (int i = 0; i < 6; i++)
		{
			if (day == a[i]) cday = true;
		}
		if (cday == false)
		{
			cout << "Please enter again: ";
			cin >> day;
		}
	}
	newCourse.dayofweek = day;

	cout << "Enter Start Time (hh:mm): ";
	cin >> newCourse.starthour;
	int hour1 = stoi(newCourse.starthour);
	while (hour1 < 0 || hour1 > 24)
	{
		cout << "WRONG MINUTE RANGE !" << endl;
		cout << "Enter minute again: ";
		cin >> newCourse.starthour;
		hour1 = stoi(newCourse.starthour);
	}
	cin >> newCourse.startminute;
	int min1 = stoi(newCourse.startminute);
	while (min1 < 0 || min1 > 59)
	{
		cout << "WRONG MINUTE RANGE !" << endl;
		cout << "Enter minute again: ";
		cin >> newCourse.startminute;
		min1 = stoi(newCourse.startminute);
	}

	cout << "Enter End Time (hh:mm): ";
	cin >> newCourse.endhour;
	int hour2 = stoi(newCourse.endhour);
	while (hour2 < 0 || hour2 > 24)
	{
		cout << "WRONG MINUTE RANGE !" << endl;
		cout << "Enter minute again: ";
		cin >> newCourse.endhour;
		hour2 = stoi(newCourse.endhour);
	}
	cin >> newCourse.endminute;
	int min2 = stoi(newCourse.endminute);
	while (min2 < 0 || min2 > 59)
	{
		cout << "WRONG MINUTE RANGE !" << endl;
		cout << "Enter minute again: ";
		cin >> newCourse.endminute;
		min2 = stoi(newCourse.endminute);
	}

	cin.ignore();
	cout << "Enter Room: ";
	getline(cin, newCourse.Room);

	AddToCourseFile(fin, newCourse);

	fin.close();

	TransferDataFile(course);

	return 0;
}

void TransferDataFile(string course)
{
	ifstream fin;
	fin.open("Course_temp.txt");
	if (!fin)
	{
		cout << "TEMP FILE ERROR !" << endl;
		return;
	}

	ofstream fout;
	fout.open(course);

	string line;
	while (getline(fin, line))
	{
		fout << line << endl;
	}

	fout.close();
	fin.close();
}

void AddToCourseFile(ifstream &fin, FileSchedule newCourse)
{
	ofstream temp;
	temp.open("Course_temp.txt");

	string line;
	int count = 0;
	while (getline(fin, line)) 
	{
		temp << line << endl;
		count++;
	}
	count = count / 16;
	count++;
	newCourse.No = to_string(count);

	temp << endl;
	temp << newCourse.No << endl;
	temp << newCourse.courseID << endl;
	temp << newCourse.courseName << endl;
	temp << newCourse.Class << endl;
	temp << newCourse.LUser << endl;
	temp << newCourse.LName << endl;
	temp << newCourse.Ldegree << endl;
	temp << newCourse.Lgender << endl;
	temp << newCourse.startdateday << " ";
	temp << newCourse.startdatemonth << " ";
	temp << newCourse.startdateyear << endl;
	temp << newCourse.enddateday << " ";
	temp << newCourse.enddatemonth << " ";
	temp << newCourse.enddateyear << endl;
	temp << newCourse.dayofweek << endl;
	temp << newCourse.starthour << endl;
	temp << newCourse.startminute << endl;
	temp << newCourse.endhour << endl;
	temp << newCourse.endminute << endl;
	temp << newCourse.Room << endl;
	temp << endl;

	temp.close();
}