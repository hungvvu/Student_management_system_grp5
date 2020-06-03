#include "Declarations.h"

int CountDates(ifstream& fin) {// count how many study dates the course have
	string temp;
	for (int i = 0; i < 10; ++i) {// skip the first 10 lines
		getline(fin, temp);
	}

	// count the number of dates the course have
	// from the first student data
	int count = 0;
	while (temp != "") {// count until the end of this student ("" is the seperating line between students)
		getline(fin, temp);
		++count;
	}
	return count - 1;// minus the last line ""
}

void SaveDates(ifstream& fin, Date_n_Time*& arr, int n) {
	string temp;
	for (int i = 0; i < 10; ++i) {// skip the first 10 lines
		getline(fin, temp);
	}

	// read and save all attendance date from the first student
	for (int i = 0; i < n; ++i) {
		getline(fin, arr[i].day, ' ');
		getline(fin, arr[i].month, ' ');
		getline(fin, arr[i].year, ' ');
		getline(fin, arr[i].sHour, ' ');
		getline(fin, arr[i].sMin, ' ');
		getline(fin, arr[i].eHour, ' ');
		getline(fin, arr[i].eMin, ' ');
		getline(fin, temp);// skip the status
	}
}

void SaveATD_Info(ifstream& fin, Attendance*& ATDinfo, int& NumofStu, int NumofDates) {
	fin >> NumofStu;
	fin.ignore();

	ATDinfo = new Attendance[NumofStu];// array to store attendance infomation of the students

	for (int i = 0; i < NumofStu; ++i) {
		ATDinfo[i].ATD_Status = new bool[NumofDates];// alocate an array for each student to
													 // store his/her attendance status of each day
	}

	// save the attendance information of all students
	for (int i = 0; i < NumofStu; ++i) {
		getline(fin, ATDinfo[i].StuInfo.Fullname);
		getline(fin, ATDinfo[i].StuInfo.ID);
		getline(fin, ATDinfo[i].StuInfo.Password);
		getline(fin, ATDinfo[i].StuInfo.DoB);

		// skip five lines that store the grades
		string temp;
		for (int k =0;k<5;++k){
			getline(fin, temp);
		}


		for (int j = 0; j < NumofDates; ++j) {// save the attendance status for this current student
			for (int k = 0; k < 7; ++k) {// skip the date and time to reach the status of that day
				getline(fin, temp, ' ');
			}

			int Stat;
			fin >> Stat;
			fin.ignore();

			if (Stat == -1) {
				ATDinfo[i].ATD_Status[j] = false;// absent
			}
			else {
				ATDinfo[i].ATD_Status[j] = true;// present
			}
		}
		getline(fin, temp);// skip the separation line
	}
}

void DisplayATD(Attendance* ATDinfo, int numofstu, Date_n_Time* Dates, int numofdates) {
	for (int i = 0; i < numofdates;++i) {// print each list for each day
		// print the date and time
		cout << "- " << Dates[i].day << "/" << Dates[i].month << "/" << Dates[i].year << ", "
			<< Dates[i].sHour << ":" << Dates[i].sMin << "-" << Dates[i].eHour << ":" << Dates[i].eMin << endl;

		// print out the student and his/her atendance status in the current day
		for (int j = 0; j < numofstu; ++j) {
			cout << j + 1 << ". " << ATDinfo[j].StuInfo.Fullname << ". ";
			if (!ATDinfo[j].ATD_Status[i])
				cout << "Absent";// absent
			else
				cout << "Present";// present
			cout << endl;
		}
		cout << "*========*" << endl;
	}
}

void ViewAttendanceList() {
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
		int NumofDates = CountDates(fin);// count how many attendance date are there
		fin.seekg(0);// reset the read cursor to read again later

		Date_n_Time* ATD_Dates = new Date_n_Time[NumofDates];// array to store attendance dates
		SaveDates(fin, ATD_Dates, NumofDates);// save the attendance dates
		fin.seekg(0);// reset the read cursor to read again later

		int NumofStu = 0;
		Attendance* ATDinfo;// array to store attendance infomation of the students
		SaveATD_Info(fin, ATDinfo, NumofStu, NumofDates);// save the attendance info to the array

		DisplayATD(ATDinfo, NumofStu, ATD_Dates, NumofDates);
		delete[] ATD_Dates;
		for (int i = 0; i < NumofStu; ++i) {// loop to delete all array that store the attendance status
			delete[] ATDinfo[i].ATD_Status;
		}
		delete[] ATDinfo;

		fin.close();
	}
}