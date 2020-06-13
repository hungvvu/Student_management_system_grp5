#include "Declarations.h"
int mainmenu(int& choice1)
{
	cout << "\n-----MENU------\n";
	cout << "0.Return\n1.Login\n\nWhat is your option?\n";
	cin >> choice1;
	return choice1;
}

int MenuStudent(int& choice2)
{
	cout << "\n-----MENU------\n";
	cout << "0.Return\n1.Attendance\n2.Timetable\n3.Grade/Score\n4.HomeWork\n5.Change Password\n6.View Profile\n7.View checkin result\n";
	cin >> choice2;
	return choice2;
}
int MenuStaff(int& choice2)
{
	cout << "\n-----MENU------\n";

	cout << "0.Return\n1.Manully Add Student to a class\n2.Edit an existing student\n3.Remove a student\n4.Change Student's Class\n5.View list of classes\n6.View list of students in a class\n7.Change Password\n8.View Profile\n9.Create semester\n10.Import Course(Schedule)\n11.Edit a course\n12.Remove a student from a course\n13.Add a student to a course\n14.Remove Course\n15.Add new Course\n16.View List of Course\n17.View List of Student of Course\n18.View attendance list of a course\n19.View All Lecturers\n20.Search and View Scoreboard\n21.Export Atendance list of a course\n22.Export Scoreboard to CSV file\n23.Import Student from CSV\n";

	cin >> choice2;
	return choice2;
}

int MenuLecturer(int& choice2)
{
	cout << "\n-----MENU------\n";
	cout << "0.Return\n1.View List of Course\n2.View List of Student of Course\n3.View Attandance List of Course\n4.Edit An Attandance\n5.Import ScoreBoard of Course\n6.Edit Grade of Student\n7.View Scoreboard\n8.Change Password\n9.View Profile\n";
	cin >> choice2;
	return choice2;
}


void showmenu(int& choice1, int& choice2, string& Position, string& username, string& password)
{
	if (choice1 == 0)
		mainmenu(choice1);
	if (choice1 == 1)
	{
		if (Position == "-1" || Position == "-2")
		{
			Position = Login(username, password);
			system("cls");
		}
		while (Position == "-1") {// can't find in the whole data base
			cout << "username or password is incorect" << endl;
			showmenu(choice1, choice2, Position, username, password);
			system("cls");
		}

		if (Position == "Student")
		{
			MenuStudent(choice2);

			system("cls");

			if (choice2 == 1) //Check In
			{
				ifstream fin;
				ofstream fout;
				FileCourse** a;
				FileCourse** b;
				FileSchedule* s;
				int counts;
				int NumofStu;
				int countdays;
				checkin(fin, fout, a, b, s, counts, username, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 4) {
				cout << "Function unavailable" << endl;
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 5) {// Change pass
				if (ChangePass("Student.txt", username, password)) {
					cout << "password changed successfull" << endl;
				}
				else {
					cout << "change password fail" << endl;
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 6)
			{
				Profile(username, password);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 7)
			{
				ViewATD(username);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 3) {
				View_Score(username);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			while (choice2 == 0 && choice1 == 1)
			{
				choice1 = 0;
				Position = "-2";// logout
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 2)
			{
				int n = ViewSchedule(username);
				if (n == 1)
				{
					system("pause");
					system("cls");
					showmenu(choice1, choice2, Position, username, password);
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}
		}

		if (Position == "Staff")
		{
			MenuStaff(choice2);
			system("cls");

			if (choice2 == 0 && choice1 == 1)
			{
				choice1 = 0;
				Position = "-2";// logout
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 1) {// Manually add student to class
				if (AddStuManually() < 0) {
					cout << "add student failed" << endl;
				}
				else {
					cout << "add student successful" << endl;
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 2)
			{
				Stu* a;
				string Class;
				EditIntoFile(a, Class);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 3) {
				if (!Remove_Student()) {
					cout << "remove student failed" << endl;
				}
				else {
					cout << "remove student successfully" << endl;
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 4) {
				if (ChangeStu2Class())
					cout << "change student's class successfully" << endl;
				else
					cout << "change student's class failed" << endl;
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 5)
			{
				ifstream fin;
				int NumOfClass;
				School* a;
				ViewListOfClass(fin, NumOfClass, a);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 6)
			{
				ViewStudentChoice();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 7) {// change pass
				if (ChangePass("Staff.txt", username, password)) {
					cout << "password changed successfull" << endl;
				}
				else {
					cout << "change password fail" << endl;
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 8)
			{
				Profile(username, password);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 9) {
				if (New_Semester())
					cout << "New semester has been created" << endl;
				cout << "Current semester is " << Cur_Semester() << endl;
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 10)
			{
				ifstream fin;
				FileSchedule* s;
				int countcsv;
				ifstream fin2;
				Stu* a;
				int NumofStu;
				ImportSchedule(fin, s, countcsv, fin2, a, NumofStu);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 11) {
				EditCourse();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 12)
			{
				int removestucourse = RemoveStufromCourse();
				if (removestucourse == 1)
				{
					showmenu(choice1, choice2, Position, username, password);
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 13) {
				AddStu2Course();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 14)
			{
				FileSchedule* s;
				int counts;
				string k;
				RemoveCourse(s, counts, k);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 15) //Manually add course
			{
				int c = AddCourseManually();
				if (c == 1)
				{
					system("pause");
					system("cls");
					showmenu(choice1, choice2, Position, username, password);
				}
				else
				{
					cout << "ADD SUCCESSFULLY" << endl;
					system("pause");
					system("cls");
					showmenu(choice1, choice2, Position, username, password);
				}
			}

			if (choice2 == 16)
			{
				FileSchedule* s;
				int counts;
				View_List_Of_Course(s, counts);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 17)
			{
				ifstream fin;
				FileCourse** a;
				int NumofStu = 0;
				int countdays = 0;
				printoutStuinfo(fin, a, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 18) {
				ViewAttendanceList();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 19)
			{
				Lect* a;
				ifstream fin;
				int NumofLect;
				View_ALL_Lecturers(fin, a, NumofLect);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 20)
			{
				ifstream fin;
				FileCourse** a;
				int NumofStu = 0;
				int countdays = 0;
				printoutscore(fin, a, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 21) {
				Export_Atendance();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 22)
			{
				int exportscore = ExportScoreCSV();
				if (exportscore == 1)
				{
					system("pause");
					system("cls");
					showmenu(choice1, choice2, Position, username, password);
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
            }
            if (choice2 == 23)
			{
				CSVStudent();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}
		}
		if (Position == "Lecturer")
		{
			MenuLecturer(choice2);
			system("cls");

			if (choice2 == 1)
			{
				FileSchedule* s;
				int counts;
				View_List_Of_Course(s, counts);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 4)
			{
				ifstream fin;
				ofstream fout;
				FileCourse** a;
				FileSchedule* s;
				int counts;
				int NumofStu;
				int countdays;
				string z;
				Edit_Attandance(fin, fout, a, s, counts, username, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 6)
			{
				ifstream fin;
				ofstream fout;
				FileCourse** a;
				FileSchedule* s;
				int counts;
				int NumofStu;
				int countdays;
				string z;
				EditScoreboard(fin, fout, a, s, counts, username, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 7)
			{
				ifstream fin;
				FileCourse** a;
				int NumofStu = 0;
				int countdays = 0;
				printoutscore(fin, a, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}
			if (choice2 == 8) {// change pass
				if (ChangePass("Lecturer.txt", username, password)) {
					cout << "password changed successfull" << endl;
				}
				else {
					cout << "change password fail" << endl;
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 9)
			{
				Profile(username, password);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 5)
			{
				int n = ImportScore(username);
				if (n == 1)
				{
					system("pause");
					system("cls");
					showmenu(choice1, choice2, Position, username, password);
				}
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 3) {
				ViewAttendanceList();
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}

			while (choice2 == 0 && choice1 == 1)
			{
				choice1 = 0;
				Position = "-2";// logout
				showmenu(choice1, choice2, Position, username, password);
			}

			if (choice2 == 2)
			{
				ifstream fin;
				FileCourse** a;
				int NumofStu = 0;
				int countdays = 0;
				printoutStuinfo(fin, a, NumofStu, countdays);
				system("pause");
				system("cls");
				showmenu(choice1, choice2, Position, username, password);
			}
		}
	}
}