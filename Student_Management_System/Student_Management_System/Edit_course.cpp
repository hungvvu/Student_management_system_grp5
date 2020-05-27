#include "Declarations.h"

int CountCourse(ifstream& fin) {// count how many courses are there in the file
	int count = 0;
	while (!fin.eof()) {
		for (int i = 0; i < 17; ++i) {// ignore a block of 17 lines (a courses)
			fin.ignore();
		}
		++count;// each time we skip through 17 lines,
				// increase the number of counted courses by 1
	}

	return count;// return the number of course
}

void LoadCourse(ifstream& fin, FileSchedule*& Courses, int& n) {
	n = CountCourse(fin);
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
		// input start date and end date
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
		fin.ignore();
	}
}

void editCourseField(FileSchedule& course, int choice) {
	switch (choice) {
	case 1: {
		cout << "new course ID: ";
		cin >> course.courseID;
		return;
	}
	case 2: {
		cout << "new course name: ";
		cin >> course.courseName;

		return;
	}
	case 3: {
		cout << "new class: ";
		cin >> course.Class;

		return;
	}
	case 4: {
		cout << "Lecturer user: ";
		cin >> course.LUser;
		cout << "Lecturer Name: ";
		cin >> course.LName;
		cout << "Lecturer degree: ";
		cin >> course.Ldegree;
		cout << "Lecturer gender: ";
		cin >> course.Lgender;

		return;
	}
	case 5: {
		cout << "enter start date(dd mm yyyy): ";
		cin >> course.startdateday;
		cin >> course.startdatemonth;
		cin >> course.startdateyear;
		return;
	}
	case 6: {
		cout << "enter end date(dd mm yyyy): ";
		cin >> course.enddateday;
		cin >> course.enddatemonth;
		cin >> course.enddateyear;

		return;
	}
	case 7: {
		cout << "enter day of week: ";
		cin >> course.dayofweek;

		return;
	}
	case 8: {
		cout << "enter start time(<hour> <minute>): ";
		cin >> course.starthour;
		cin >> course.startminute;
		cout << "enter end time(<hour> <minute>): ";
		cin >> course.endhour;
		cin >> course.endminute;

		return;
	}
	case 9: {
		cout << "enter room: ";
		cin >> course.Room;

		return;
	}
	}
}
void EditCourseArray(FileSchedule*& courses, int n) {
	string ID;
	cout << "enter course ID to edit: ";
	cin >> ID;

	bool found = false;
	for (int i = 0; i < n && !found; ++i) {// find the course in the array to edit
		if (courses[i].courseID == ID) {
			found = true;
			int choice;
			do {
				cout << "1. CourseID: " << courses[i].courseID << endl;
				cout << "2. Course name: " << courses[i].courseName << endl;
				cout << "3. Class: " << courses[i].Class << endl;
				cout << "4. Lecturer information: " << endl;// print out the lecturer information
				cout << " - User: " << courses[i].LUser << endl;
				cout << " - Name: " << courses[i].LName << endl;
				cout << " - Degree: " << courses[i].Ldegree << endl;
				cout << " - Sex: " << courses[i].Lgender << endl;
				cout << "5. Start date: " << courses[i].startdateday << "/" << courses[i].startdatemonth << "/" << courses[i].startdateyear << endl;
				cout << "6. End date: " << courses[i].enddateday << "/" << courses[i].enddatemonth << "/" << courses[i].enddateyear << endl;
				cout << "7. Day of week: " << courses[i].dayofweek << endl;
				cout << "8. Time: " << courses[i].starthour << ":" << courses[i].startminute << " - " << courses[i].endhour << ":" << courses[i].endminute << endl;
				cout << "9 Room: " << courses[i].Room << endl;

				cout << "choose a field to edit: ";
				cin >> choice;
				while (choice < 0 || choice > 9){
					cout << "invalid choice, enter again: ";
					cin >> choice;
				}
				editCourseField(courses[i], choice);// edit the chosen field

				cout << "would you like to continue editing?" << endl;
				cout << "0.No\n1.Yes\n";
				cin >> choice;	
			} while (choice != 0);
		}
	}
}

void EditCourse() {
	string year;
	string semester;
	string Class;
	cout << "enter academic year(yyyy-yyyy): ";
	cin >> year;
	cout << "enter semester(HK<num>): ";
	cin >> semester;
	cout << "enter class: ";
	cin >> Class;

	// create a file name from user input
	string FileName;
	FileName = year + "-" + semester + "Schedule-" + Class + ".txt";

	ifstream fin;
	fin.open(FileName.c_str());
	if (!fin.is_open()) {
		cout << "Invalid input";
	}
	else {
		FileSchedule* Courses;
		int n = 0;
		LoadCourse(fin, Courses, n);// load the courses to an array
		EditCourseArray(Courses, n);
	}
}