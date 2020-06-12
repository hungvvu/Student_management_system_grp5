#include "Declarations.h"

bool ViewStudentATD(string username, Attendance* ATDinfo, int numofstu, Date_n_Time* Dates, int numofdates, bool* Active){
	for (int i = 0; i < numofstu; ++i) {
		if (username == ATDinfo[i].StuInfo.ID) {
			for (int j = 0; j < numofdates; ++j) {
				cout << j + 1 << ". " << Dates[j].day << "/" << Dates[j].month << "/" << Dates[j].year << " - ";
				if (ATDinfo[i].ATD_Status[j])// checking the attendance status of the current student, on the current date
					cout << "Present";
				else
					cout << "Absent";

				cout << endl;
			}
			return true;
		}
	}
	
	return false;// cannot find the student
}

void ViewATD(string username) {
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
		cout << "cannot open file";
	}
	else {
		int NumofDates = CountDates(fin);// count how many attendance date are there
		fin.seekg(0);// reset the read cursor to read again later

		Date_n_Time* ATD_Dates = new Date_n_Time[NumofDates];// array to store attendance dates
		SaveDates(fin, ATD_Dates, NumofDates);// save the attendance dates
		fin.seekg(0);// reset the read cursor to read again later

		int NumofStu = 0;
		Attendance* ATDinfo;// array to store attendance infomation of the students
		bool* Active;
		SaveATD_Info(fin, ATDinfo, NumofStu, NumofDates, Active);// save the attendance info to the array

		if (!ViewStudentATD(username, ATDinfo, NumofStu, ATD_Dates, NumofDates, Active))
			cout << "You were not enrolled in this course" << endl;

		delete[] ATD_Dates;
		for (int i = 0; i < NumofStu; ++i) {// loop to delete all array that store the attendance status
			delete[] ATDinfo[i].ATD_Status;
		}
		delete[] ATDinfo;
		delete[] Active;

		fin.close();
	}
}