#include "Declarations.h"

void AddToFile(Stu S, ifstream& fin, FileSchedule Course) {
		ofstream temp;
		temp.open("temp.txt");

		if (!temp.is_open()) {
			cout << "cannot create buffer" << endl;
		}
		else {
			int numofstu;// number of student
			fin >> numofstu;
			fin.ignore();

			temp << numofstu + 1 << endl;// update the number of student in the course
			string line;
			while (getline(fin, line)) {// copy all existing student to temp
				temp << line << endl;
			}

			int d1 = stoi(s[j].startdateday);
			int m1 = stoi(s[j].startdatemonth);
			int y1 = stoi(s[j].startdateyear);
			int d2 = stoi(s[j].enddateday);
			int m2 = stoi(s[j].enddatemonth);
			int y2 = stoi(s[j].enddateyear);
			int weekdays = 0;
			if (s[j].dayofweek == "MON")
			{
				weekdays = 2;
			}
			if (s[j].dayofweek == "TUE")
			{
				weekdays = 3;
			}
			if (s[j].dayofweek == "WED")
			{
				weekdays = 4;
			}
			if (s[j].dayofweek == "THUR")
			{
				weekdays = 5;
			}
			if (s[j].dayofweek == "FRI")
			{
				weekdays = 6;
			}
			if (s[j].dayofweek == "SAT")
			{
				weekdays = 7;
			}
			Schedule << a[i].Fullname << endl;
			Schedule << a[i].ID << endl;
			Schedule << a[i].Password << endl;
			Schedule << a[i].DoB << endl;
			Schedule << "-1" << endl;//active and inactive
			Schedule << "-1" << endl;
			Schedule << "-1" << endl;
			Schedule << "-1" << endl;
			Schedule << "-1" << endl;
			DateToFIle(Schedule, d1, d2, m1, m2, y1, y2, weekdays, s, j);
		}

		temp.close();
		fin.close();

		remove("Student-19CLC1.txt");// remove old file
		rename("temp.txt", "Student-19CLC1.txt");// rename the temp file
		return 0;
}

void AddStu2Course() {
	ifstream Load;
	string Class;
	do {
		cout << "enter the current class of the student: ";
		cin >> Class;

		string Student_Class;
		Student_Class = "Student-" + Class + ".txt";

		Load.open(Student_Class.c_str());

		if (!Load.is_open())
			cout << "cannot find entered class" << endl;

	} while (!Load.is_open());// cannot find the class, ask to re-enter

	Stu* Students;
	int NumOfStu;
	LoadStudentClass(Load, Students, NumOfStu); // Read  file Student-19CLC5-txt
	Load.close();

	string ID;
	cout << "enter the student ID: ";
	cin >> ID;

	bool found = false;
	Stu S;
	for (int i = 0; i < NumOfStu && !found; ++i) {
		if (ID == Students[i].ID) {
			found = true;
			S = Students[i];
		}
	}
	delete[] Students;

	string year;
	string semester;
	string CourseClass;
	string CourseID;
	cout << "enter academic year(yyyy-yyyy): ";
	cin >> year;
	cout << "enter semester(Ex: HK2): ";
	cin >> semester;
	cout << "enter class: ";
	cin >> CourseClass;
	cout << "enter course ID: ";
	cin >> CourseID;

	string StuFile = year + "-" + semester + "-" + Class + "-" + CourseID + "-Student.txt";

	ifstream fin;
	fin.open(StuFile.c_str());
	if (!fin.is_open()) {
		cout << "cannot find the entered course" << endl;
	}
	else {
		FileSchedule* Courses;
		int n = 0;
		n = CountCourse(fin);// count how many courses in the array
		fin.seekg(0);// after count, the cursor is at the end of file, 
					 // reset the read cursor to the beginning of the file

		Courses = new FileSchedule[n];// count the number of course and alocate the needed memory

		for (int i = 0; i < n; ++i) {// load the courses
			getline(fin, Courses[i].No);
			getline(fin, Courses[i].courseID);
			getline(fin, Courses[i].courseName);
			getline(fin, Courses[i].Class);
			getline(fin, Courses[i].LUser);
			getline(fin, Courses[i].LName);
			getline(fin, Courses[i].Ldegree);
			getline(fin, Courses[i].Lgender);
			getline(fin, Courses[i].startdateday, ' ');
			getline(fin, Courses[i].startdatemonth, ' ');
			getline(fin, Courses[i].startdateyear, '\n');
			getline(fin, Courses[i].enddateday, ' ');
			getline(fin, Courses[i].enddatemonth, ' ');
			getline(fin, Courses[i].enddateyear, '\n');
			getline(fin, Courses[i].dayofweek);
			getline(fin, Courses[i].starthour);
			getline(fin, Courses[i].startminute);
			getline(fin, Courses[i].endhour);
			getline(fin, Courses[i].endminute);
			getline(fin, Courses[i].Room);
			fin.ignore();// ignore the empty line
		}
		fin.close();
	}
}