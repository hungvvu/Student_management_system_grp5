#include "Declarations.h"

void Export_to_CSV(string CourseID, Attendance* ATDinfo, int numofstu, Date_n_Time* Dates, int numofdates, bool* Active) {
	for (int i = 0; i < numofdates; ++i) {
		cout << i + 1 << ". " << Dates[i].day << "/" << Dates[i].month << "/" << Dates[i].year << endl;
	}
	cout << endl;

	int dateIndex;
	cout << "choose a date to export attendance list: ";
	cin >> dateIndex;
	--dateIndex;
	
	ofstream fout;
	string Filename = CourseID + "-" + "Atendance" + "-" + Dates[dateIndex].day + "_" + Dates[dateIndex].month + "_" + Dates[dateIndex].year + ".csv";
	fout.open(Filename.c_str());
	if (!fout.is_open()) {
		cout << "cannot open file" << endl;
	}
	else {
		fout << "Number,Student ID,Name,Attendance,Inactive" << endl;
		for (int j = 0; j < numofstu; ++j) {
			fout << j + 1 << "," << ATDinfo[j].StuInfo.ID << "," << ATDinfo[j].StuInfo.Fullname;

			if (!ATDinfo[j].ATD_Status[dateIndex])// print out the status of this student on the chosen date
				fout << ",Absent";// absent
			else
				fout << ",Present";// present

			// inform user if this student is inactive
			if (!Active[j])
				fout << ",X";

			fout << endl;
		}

		cout << "succesfully exported" << endl;
		fout.close();
	}
}

void Export_Atendance() {
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
		bool* Active;
		SaveATD_Info(fin, ATDinfo, NumofStu, NumofDates, Active);// save the attendance info to the array

		Export_to_CSV(CourseID, ATDinfo, NumofStu, ATD_Dates, NumofDates, Active);
		delete[] ATD_Dates;
		for (int i = 0; i < NumofStu; ++i) {// loop to delete all array that store the attendance status
			delete[] ATDinfo[i].ATD_Status;
		}
		delete[] ATDinfo;
		delete[] Active;

		fin.close();
	}
}