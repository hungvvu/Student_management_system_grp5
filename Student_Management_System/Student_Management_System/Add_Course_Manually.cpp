#include "Declarations.h"


int AddCourseManually()
{
	ifstream fin;
	string a, b, f, Class;
	int menu = 0;
	
	cout << "Enter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, a);

	cout << "Enter semester:" << endl;//HK2
	getline(cin, b);
	cout << "Enter class" << endl;//19CLC5
	getline(cin, Class);

	f = a + "-" + b + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

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

			f = a + "-" + b + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

			fin.open(f.c_str());
		}
	}

	FileSchedule newCourse;
	newCourse.Class = Class;

	cout << "Enter Course ID: ";
	cin >> newCourse.courseID;
	cin.ignore();
	//Neu trung thi chuyen sang Edit course

	cout << "Enter Course Name: ";
	getline(cin, newCourse.courseName);
	cout << "Enter Lecturer Username: ";
	cin >> newCourse.LUser;
	string user = newCourse.LUser;
	cin.ignore();
	cout << "Enter Lecturer Name: ";
	getline(cin, newCourse.LName);
	cout << "Enter Lecturer Degree: ";
	cin >> newCourse.Ldegree;
	cout << "Enter Lecturer Gender: ";
	cin >> newCourse.Lgender;
	string gender = newCourse.Lgender;
	bool cgender = false;
	while (cgender == false)
	{
		if (gender == "Male" || gender == "male" || gender == "Female" || gender == "female")
		{
			cgender = true;
		}
		else
		{
			cout << "Please enter again (male / female): ";
			cin >> gender;
		}
	}
	newCourse.Lgender = gender;

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
	string dayArray[] = { "MON", "TUE", "WED", "THUR", "FRI", "SAT" };
	bool cday = false;
	while (cday == false)
	{
		for (int i = 0; i < 6; i++)
		{
			if (day == dayArray[i]) cday = true;
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

	UpdateLectFile(newCourse, user);

	fin.close();

	TransferDataFile(f.c_str());

	FileSchedule* ncourse = new FileSchedule[1];

	ncourse[0] = newCourse;

	CreateNewCFile(Class, ncourse, a, b);

	delete[] ncourse;

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

void CreateNewCFile(string Class, FileSchedule*& newCourse, string x, string y)
{
	string SFile;
	SFile = "Student-" + Class + ".txt";

	string CFile;
	CFile = x + "-" + y + "-" + Class + "-" + newCourse[0].courseID + "-Student.txt"; //2019-2020-HK2-19CLC5-CS1612-Student.txt or cm101

	ifstream Student;
	Student.open(SFile.c_str());
	if (!Student)
	{
		cout << "STUDENT FILE ERROR !" << endl;
		return;
	}

	int numofstu;
	Student >> numofstu;
	Student.ignore();
	Stu* SArray = new Stu[numofstu];

	for (int i = 0; i < numofstu; i++) {
		getline(Student, SArray[i].Fullname);
		getline(Student, SArray[i].ID);
		getline(Student, SArray[i].Password);
		getline(Student, SArray[i].DoB);
		Student.ignore();// skip the empty line
	}

	int d1 = 0;
	int m1 = 0;
	int y1 = 0;
	int d2 = 0;
	int m2 = 0;
	int y2 = 0;
	int weekdays = 0;
	int j = 0;

	ofstream Course;
	Course.open(CFile.c_str());

	saveListOfStudent(Course, SArray, numofstu, j, newCourse, d1, d2, m1, m2, y1, y2, weekdays);

	delete[] SArray;

	Course.close();
	Student.close();

	cout << CFile << " is created." << endl;
}