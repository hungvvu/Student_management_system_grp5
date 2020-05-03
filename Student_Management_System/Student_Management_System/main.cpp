#include "Declarations.h"

int main() {
	int choice1, choice2;
	string Position = "-1";//Position will get it from files
	string username, password;
	choice1 = 0;
	choice2 = 0;
	showmenu(choice1, choice2, Position, username, password);
	if (choice2 == 1)
		cout << "Success";//place to perform Attendance...
	return 0;
}