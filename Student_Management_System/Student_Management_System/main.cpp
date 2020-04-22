#include "Declarations.h"

int main() {
	int choice1, choice2;
	string Position = "-1";//Position will get it from files
	choice1 = 0;
	choice2 = 0;
	showmenu(choice1, choice2, Position);
	if (choice2 == 1)
		cout << "Success";//place to perform Attendance...


	/******
	for testing the eraseCurPass and WriteNewPass functions, will be delete when merge
	******/
	/*eraseCurPass("Student.txt", "19127201");
	WriteNewPass("Student.txt", "19127201", "ThisIsNewPass");*/

	/*ChangePass("Student.txt", "19127155", "abc");*/
	
	return 0;
}