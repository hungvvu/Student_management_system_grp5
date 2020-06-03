#include "Declarations.h"

int CountDates(ifstream& fin) {// count how many study dates the course have
	string temp;
	for (int i = 0; i < 10; ++i) {// skip the first 10 lines
		getline(fin, temp);
	}

	// count the number of dates the course have
	// from the first student data
	int count = 0;
	while (temp != "\n") {// count until the end of this student (\n is the seperating line between students)
		getline(fin, temp);
		++count;
	}
	return count - 1;// minus the last line "\n"
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

	Attendance* ATDinfo = new Attendance[NumofStu];// array to store attendance infomation of the students

	for (int i = 0; i < NumofStu; ++i) {
		ATDinfo[i].ATD_Status = new string[NumofDates];// alocate an array for each student to
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

			string Stat;
			getline(fin, Stat);

			if (Stat == "-1") {
				ATDinfo[i].ATD_Status[j] = "A";// A = absent
			}
			else {
				ATDinfo[i].ATD_Status[j] = Stat;// not absent, Stat is LA (stand for late) or P (Present)
			}
		}
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
	}
}