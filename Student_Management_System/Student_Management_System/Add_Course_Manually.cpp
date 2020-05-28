#include "Declarations.h"

int AddCourseManually()
{
	ifstream fin;
	string course;
	cout << "Enter file course name: "; cin >> course;
	fin.open(course);
	while (!fin)
	{
		cout << "INPUT ERROR !" << endl;
		cout << "Enter file course name: "; cin >> course;
		fin.open(course);
	}

	FileSchedule newCourse;
	cout << "Enter Course ID: ";
	cin >> newCourse.courseID;
	cout << "Enter Course Name: ";
	getline(cin, newCourse.courseName);
	cout << "Enter Class: ";
	cin >> newCourse.Class;
	cout << "Enter Lecturer Username: ";
	cin >> newCourse.LUser;
	cout << "Enter Lecturer Name: ";
	cin >> newCourse.LName;
	cout << "Enter Lecturer Degree: ";
	cin >> newCourse.Ldegree;
	cout << "Enter Lecturer Gender: ";
	cin >> newCourse.Lgender;

	cout << "Enter Start Date: ";
	cin >> newCourse.startdateday;
	int d = stoi(newCourse.startdateday);
	cin >> newCourse.startdatemonth;
	int m = stoi(newCourse.startdatemonth);
	cin >> newCourse.startdateyear;
	bool check1, check2;
	check1 = check_month(m);
	check2 = check_date(d, m);
	while ((check1 && check2) == false)
	{
		cout << "DATE ERROR !" << endl;
		cout << "Enter Start Date: ";
		cin >> newCourse.startdateday;
		d = stoi(newCourse.startdateday);
		cin >> newCourse.startdatemonth;
		m = stoi(newCourse.startdatemonth);
		cin >> newCourse.startdateyear;
		check1 = check_month(m);
		check2 = check_date(d, m);
	}

	AddToCourseFile(fin, course, newCourse);

	fin.close();
}

void AddToCourseFile(ifstream &fin, string course, FileSchedule newCourse)
{
	ofstream temp;
	temp.open("temp.txt");


}