#include "Declarations.h"

int CountCourse(ifstream& fin) {// count how many courses are there in the file
	int count = 0;
	while (true) {
		for (int i = 0; i < 17; ++i) {// ignore a block of 17 lines (a courses)
			fin.ignore(100, '\n');

			if (fin.eof())// reached end of file, return the number of courses
				return count;
		}
		++count;// each time we skip through 17 lines,
				// increase the number of counted courses by 1
	}

	return count;// return the number of course
}

void LoadCourse(ifstream& fin, FileSchedule*& Courses, int& n) {
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
}

void editCourseField(FileSchedule& course, int choice) {
	switch (choice) {
	case 1: {
		cout << "new course ID: ";
		cin >> course.courseID;
		return;
	}
	case 2: {
		cin.ignore();// skip the '\n'
		cout << "new course name: ";
		getline(cin, course.courseName);

		return;
	}
	case 3: {
		cout << "new class: ";
		cin >> course.Class;

		return;
	}
	case 4: {
		cin.ignore();// skip the '\n'
		cout << "Lecturer user: ";
		getline(cin, course.LUser);
		cout << "Lecturer Name: ";
		getline(cin, course.LName);
		cout << "Lecturer degree: ";
		getline(cin, course.Ldegree);
		cout << "Lecturer gender: ";
		getline(cin, course.Lgender);

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
		cout << "enter day of week(MON, TUS, WEN,...): ";
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

int EditCourseArray(FileSchedule*& courses, int n, string& oldID) {
	bool found = false;
	do {
		string ID;
		cout << "enter course ID to edit: ";
		cin >> ID;
		cout << endl;
		oldID = ID;// save the old ID in case of edit the ID

		for (int i = 0; i < n && !found; ++i) {// find the course in the array to edit
			if (courses[i].courseID == ID) {
				found = true;
				int choice;
				do {
					cout << "1. CourseID: " << courses[i].courseID << endl;
					cout << "2. Course name: " << courses[i].courseName << endl;

					cout << "3. Class: " << courses[i].Class << endl;/***dev note*** "should remove this field since it won't be use a lot" */

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
					while (choice < 0 || choice > 9) {
						cout << "invalid choice, enter again: ";
						cin >> choice;
					}
					editCourseField(courses[i], choice);// edit the chosen field

					cout << "would you like to continue editing?" << endl;
					cout << "0.No\n1.Yes\n";
					cin >> choice;
					cout << endl;
				} while (choice != 0);
			}
			if (found)// found and edited the chosen course, exit this function
				return i;// return the index of the course in the array
		}
		// can't find course, ask user to re-enter
		cout << "cannot find the course, please check your input" << endl;
	} while (!found);// re-enter course id if not found the course
}

void SaveCoursesToFile(ofstream& fout, FileSchedule* courses, int n) {// save the array with the edited course back to the file
	for (int i = 0; i < n; i++)
	{
		fout << courses[i].No << endl;
		fout << courses[i].courseID << endl;
		fout << courses[i].courseName << endl;
		fout << courses[i].Class << endl;
		fout << courses[i].LUser << endl;
		fout << courses[i].LName << endl;
		fout << courses[i].Ldegree << endl;
		fout << courses[i].Lgender << endl;
		fout << courses[i].startdateday << " " << courses[i].startdatemonth << " " << courses[i].startdateyear << endl;
		fout << courses[i].enddateday << " " << courses[i].enddatemonth << " " << courses[i].enddateyear << endl;
		fout << courses[i].dayofweek << endl;
		fout << courses[i].starthour << endl;
		fout << courses[i].startminute << endl;
		fout << courses[i].endhour << endl;
		fout << courses[i].endminute << endl;
		fout << courses[i].Room << endl;
		fout << endl;
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
	FileName = year + "-" + semester + "-Schedule-" + Class + ".txt";

	// edit in schedule file
	ifstream fin;
	fin.open(FileName.c_str());
	if (!fin.is_open()) {
		cout << "Invalid input";
		return;
	}
	else {
		FileSchedule* Courses;
		int n = 0;
		LoadCourse(fin, Courses, n);// load the courses to an array

		string OldID;
		int index = EditCourseArray(Courses, n, OldID);// edit a course in the array, get the index of chosen course

		ofstream fout;
		fout.open(FileName.c_str());
		if (!fout.is_open()) {
			cout << "fail to save the edited course" << endl;
			return;
		}
		else {
			SaveCoursesToFile(fout, Courses, n);
			fout.close();
		}

		fin.close();

		// edit the atendance date for student in the student list file
		string ClassFile = "Student-" + Class + ".txt";
		ifstream  ReadClass;
		ReadClass.open(ClassFile.c_str());
		if (!ReadClass.is_open()) {
			cout << "cannot read from class file";
		}
		else {
			///*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|
			//	The codes below try to save the current grade of the student to the new file,
			//	But because this function is only used at the start of
			//	a semester, so the grade will all be "-1"
			//*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|/
			//string OldStuFile = year + "-" + semester + "-" + Class + "-" + OldID + "-Student.txt";// the old student file
			//ifstream OldFile;
			//OldFile.open(OldStuFile.c_str());
			//if (!OldFile.is_open()) {
			//	cout << "cannot open student list file";
			//}
			//else {
				//string NewFileName = year + "-" + semester + "-" + Class + "-" + Courses[index].courseID + "-Student.txt";// the new student file
			//	fout.open("temp.txt");
			//	if (!fout.is_open()) {
			//		cout << "cannot write in student list file";
			//	}
			//	else {
			//		//// save the new edited course atendance list
			//		//int d1 = 0;
			//		//int m1 = 0;
			//		//int y1 = 0;
			//		//int d2 = 0;
			//		//int m2 = 0;
			//		//int y2 = 0;
			//		//int weekdays = 0;

			//		//// read and write number of student
			//		//int NumOfStu;
			//		//OldFile >> NumOfStu;
			//		//OldFile.ignore();

			//		//for (int j = 0; j < NumOfStu; ++j) {
			//		//	for (int i = 0; i < 9; ++i) {// copy the first 9 lines of each student
			//		//								 // since they will not be edited
			//		//		string temp;
			//		//		getline(fin, temp);
			//		//		fout << temp << endl;
			//		//	}

			//		//	DateToFIle(fout, d1, d2, m1, m2, y1, y2, weekdays, Courses, index);// pritn out the atendance list for
			//		//	/*saveListOfStudent(fout, Students, NumOfStu, index, Courses, d1, d2, m1, m2, y1, y2, weekdays);*/
			//		//	fout.close();
			//		//}
			//	
			//}
		
			Stu* Students;
			int NumOfStu;
			LoadStudentClass(ReadClass, Students, NumOfStu);// load the students in the class to an array
			string OldStuFile = year + "-" + semester + "-" + Class + "-" + OldID + "-Student.txt";// the old student file
			string NewFileName = year + "-" + semester + "-" + Class + "-" + Courses[index].courseID + "-Student.txt";// the new student file
			
			fout.open(NewFileName.c_str());
			if (!fout.is_open()) {
				cout << "fail to write in the new file" << endl;
			}
			else {
				int d1 = 0;
				int m1 = 0;
				int y1 = 0;
				int d2 = 0;
				int m2 = 0;
				int y2 = 0;
				int weekdays = 0;
		
				remove(OldStuFile.c_str());// remove the old file, in case the ID was changed and
										   // by fout to the new file name, the old file still exist and create spare file
				saveListOfStudent(fout, Students, NumOfStu, index, Courses, d1, d2, m1, m2, y1, y2, weekdays);
			}
			fout.close();

			delete[] Students;
		}
		delete[] Courses;
	}
	cout << "edit course succesfully" << endl;
}