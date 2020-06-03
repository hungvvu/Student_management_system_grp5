#include "Declarations.h"

void AddToFile(ifstream& fin, string OldFileName, Stu S, FileSchedule* Courses, int CourseIndex) {
		ofstream temp;
		temp.open("temp.txt");

		if (!temp.is_open()) {
			cout << "cannot create buffer" << endl;
			return;
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

			// print out the new student
			int d1 = stoi(Courses[CourseIndex].startdateday);
			int m1 = stoi(Courses[CourseIndex].startdatemonth);
			int y1 = stoi(Courses[CourseIndex].startdateyear);
			int d2 = stoi(Courses[CourseIndex].enddateday);
			int m2 = stoi(Courses[CourseIndex].enddatemonth);
			int y2 = stoi(Courses[CourseIndex].enddateyear);
			int weekdays = 0;
			if (Courses[CourseIndex].dayofweek == "MON")
			{
				weekdays = 2;
			}
			if (Courses[CourseIndex].dayofweek == "TUE")
			{
				weekdays = 3;
			}
			if (Courses[CourseIndex].dayofweek == "WED")
			{
				weekdays = 4;
			}
			if (Courses[CourseIndex].dayofweek == "THUR")
			{
				weekdays = 5;
			}
			if (Courses[CourseIndex].dayofweek == "FRI")
			{
				weekdays = 6;
			}
			if (Courses[CourseIndex].dayofweek == "SAT")
			{
				weekdays = 7;
			}
			temp << S.Fullname << endl;
			temp << S.ID << endl;
			temp << S.Password << endl;
			temp << S.DoB << endl;
			temp << "-1" << endl;//active and inactive
			temp << "-1" << endl;
			temp << "-1" << endl;
			temp << "-1" << endl;
			temp << "-1" << endl;
			DateToFIle(temp, d1, d2, m1, m2, y1, y2, weekdays, Courses, CourseIndex);
			temp << endl;
		}

		temp.close();
		fin.close();

		remove(OldFileName.c_str());// remove old file
		rename("temp.txt", OldFileName.c_str());// rename the temp file
		cout << "added student " << S.ID << " to course " << Courses[CourseIndex].courseID << " successfully" << endl << endl;
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
	do {
		for (int i = 0; i < NumOfStu && !found; ++i) {
			if (ID == Students[i].ID) {
				found = true;
				S = Students[i];
			}
		}

		if (!found) {
			cout << "cannot find student with given ID, please re-enter: ";
			cin >> ID;
		}
	} while (!found);
	delete[] Students;

	cout << "enter the course information" << endl;
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

	string StuFile = year + "-" + semester + "-" + CourseClass + "-" + CourseID + "-Student.txt";

	ifstream fin;
	fin.open(StuFile.c_str());
	if (!fin.is_open()) {
		cout << "cannot find the entered course" << endl;
	}
	else {
		FileSchedule* Courses = NULL;
		int n = 0;
		
		string ScheduleFile;
		ScheduleFile = year + "-" + semester + "-Schedule-" + CourseClass + ".txt";
		ifstream Load;
		Load.open(ScheduleFile.c_str());
		if (!Load.is_open()) {
			cout << "cannot open schedule file" << endl;
		}
		else {
			LoadCourse(Load, Courses, n);// load the course to an array
			int CourseIndex = 0;
			for (int i = 0; i < n; ++i) {
				if (CourseID == Courses[i].courseID) {
					CourseIndex = i;
					break;
				}
			}
			Load.close();

			AddToFile(fin, StuFile, S, Courses, CourseIndex);
		}
		delete[] Courses;

		fin.close();
	}
}