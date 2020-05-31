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
	cout << "0.Return\n1.Attendance\n2.Timetable\n3.Grade/Score\n4.HomeWork\n5.Change Password\n6.View Profile\n";
	cin >> choice2;
	return choice2;
}
int MenuStaff(int& choice2)
{

	cout << "0.Return\n1.Manully Add Student to a class\n2.Edit an existing student\n3.Remove a student\n4.Change Student's Class\n5.View list of classes\n6.View list of students in a class\n7.Change Password\n8.View Profile\n9.Create semester\n10.Import Course(Schedule)\n11.Edit a course\n13.Remove Course\n16.View List of Course\n19.View All Lecturers\n";
	cin >> choice2;
	return choice2;
}

int MenuLecturer(int& choice2)
{
	cout << "\n-----MENU------\n";
	cout << "0.Return\n1.Manully Add Student to a class\n2.Remove a student\3.Change Student's Class\n4.Change Password\n5.View Profile\n";
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
			Position = Login(username, password);

		while (Position == "-1") {// can't find in the whole data base
			cout << "username or password is incorect" << endl;
			showmenu(choice1, choice2, Position, username, password);
		}

		if (Position == "Student")
		{
			MenuStudent(choice2);
			if (choice2 == 5) {// Change pass
				if (ChangePass("Student.txt", username, password)) {
					cout << "password changed successfull" << endl;
				}
				else {
					cout << "change password fail" << endl;
				}
				showmenu(choice1, choice2, Position, username, password);// back to main menu
			}

			if (choice2 == 6)
			{
				Profile(username, password);
				showmenu(choice1, choice2, Position, username, password);
			}

			while (choice2 == 0 && choice1 == 1)
			{
				choice1 = 0;
				Position = "-2";// logout
				showmenu(choice1, choice2, Position, username, password);
			}
		}

			if (Position == "Staff")
			{
				MenuStaff(choice2);
				if (choice2 == 2)
				{
					Stu* a;
					string Class;
					EditIntoFile(a, Class);
					showmenu(choice1, choice2, Position, username, password);
				}

				if (choice2 == 6)
				{
					ViewStudentChoice();
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}

				if (choice2 == 7) {// change pass
					if (ChangePass("Staff.txt", username, password)) {
						cout << "password changed successfull" << endl;
					}
					else {
						cout << "change password fail" << endl;
					}
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}

				if (choice2 == 1) {// Manually add student to class
					if (AddStuManually() < 0) {
						cout << "add student failed" << endl;
					}
					else {
						cout << "add student successful" << endl;
					}
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}
				if (choice2 == 3) {
					if (!Remove_Student()) {
						cout << "remove student failed" << endl;
					}
					else {
						cout << "remove student successful" << endl;
					}
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}

				if (choice2 == 4) {
					if (ChangeStu2Class())
						cout << "change student's class successfully" << endl;
					else
						cout << "change student's class failed" << endl;
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}

				if (choice2 == 5)
				{
					ifstream fin;
					int NumOfClass;
					School* a;
					ViewListOfClass(fin, NumOfClass, a);
					showmenu(choice1, choice2, Position, username, password);
				}

				if (choice2 == 0 && choice1 == 1)
				{
					choice1 = 0;
					Position = "-2";// logout
					showmenu(choice1, choice2, Position, username, password);
				}
				
				if(choice2 == 8)
				{
					Profile(username, password);
					showmenu(choice1, choice2, Position, username, password);
				}

				if (choice2 == 9) {
					if (New_Semester())
						cout << "New semester has been created" << endl;
					cout << "Current semester is " << Cur_Semester() << endl;
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
					showmenu(choice1, choice2, Position, username, password);
				}
				if (choice2 == 13)
				{
					FileSchedule* s;
					int counts;
					string k;
					RemoveCourse(s, counts, k);
					showmenu(choice1, choice2, Position, username, password);
				}
				if (choice2 == 16)
				{
					FileSchedule* s;
					int counts;
					View_List_Of_Course(s, counts);
					showmenu(choice1, choice2, Position, username, password);
				}

				if (choice2 == 19)
				{
					Lect* a;
					ifstream fin;
					int NumofLect;
					View_ALL_Lecturers(fin, a, NumofLect);
					showmenu(choice1, choice2, Position, username, password);
				}

				if (choice2 == 11) {
					EditCourse();
					showmenu(choice1, choice2, Position, username, password);
				}
			}

		{
			if (Position == "Lecturer")
			{
				MenuLecturer(choice2);
				if (choice2 == 4) {// change pass
					if (ChangePass("Lecturer.txt", username, password)) {
						cout << "password changed successfull" << endl;
					}
					else {
						cout << "change password fail" << endl;
					}
					showmenu(choice1, choice2, Position, username, password);// back to main menu
				}

				if (choice2 == 5)
				{
					Profile(username, password);
					showmenu(choice1, choice2, Position, username, password);
				}

				while (choice2 == 0 && choice1 == 1)
				{
					choice1 = 0;
					Position = "-2";// logout
					showmenu(choice1, choice2, Position, username, password);
				}
			}
		}
	}
}