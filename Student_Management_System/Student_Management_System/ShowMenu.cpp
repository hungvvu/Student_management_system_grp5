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
	cout << "0.Quay Ve\n1.Attendance\n2.Xem Thoi Khoa Bieu\n3.Xem Diem\n4.Xem Bai Tap\n5.View Profile\n";
	cin >> choice2;
	return choice2;
}
int MenuStaff(int& choice2)
{
	cout << "\n-----MENU------\n";
	cout << " 0.Return\n1.Manully Add Student to a class\n2.Edit an existing student\n3.Remove a student\n4.Change Student's Class\n5.View list of classes\n6.View list of students in a class\n7.View Profile\n";
	cin >> choice2;
	return choice2;
}

int MenuLecturer(int& choice2)
{
	cout << "\n-----MENU------\n";
	cout << " 0.Return\n1.Manully Add Student to a class\n2.Remove a student\3.Change Student's Class\n4.View Profile\n";
	cin >> choice2;
	return choice2;
}


void showmenu(int& choice1, int& choice2, string Position)
{
	mainmenu(choice1);
	if (choice1 == 1)
	{
		string username;
		string password;
		cout << "username: ";
		cin >> username;
		cout << "password: ";
		cin >> password;
		Position = Login(username, password);

		while (Position == "-1") {// can't find in the whole data base
			cout << "username or password is incorect" << endl;
			showmenu(choice1, choice2, Position);
		}

		if (Position == "Student")
		{
			MenuStudent(choice2);
			while (choice2 == 0 && choice1 == 1)
			{
				showmenu(choice1, choice2, Position);
			}
			if (choice2 == 5)
			{
				Profile(username, password);
			}
		}
		if (choice1 == 1)
			if (Position == "Staff")
			{
				MenuStaff(choice2);
				while (choice2 == 0 && choice1 == 1)
				{
					showmenu(choice1, choice2, Position);
				}
				if (choice2 == 7)
				{
					Profile(username, password);
				}
			}
		if (choice1 == 1)
		{
			if (Position == "Lecturer")
			{
				MenuLecturer(choice2);
				while (choice2 == 0 && choice1 == 1)
				{
					showmenu(choice1, choice2, Position);
				}
				if (choice2 == 4)
				{
					Profile(username, password);
				}
			}
		}
	}
}