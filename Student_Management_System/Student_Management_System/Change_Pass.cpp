#include "Declarations.h"

// Erase current password from file
int eraseCurPass(string path, string username) {
	string line, erased;
	ifstream fin;

	fin.open(path);
	if (!fin.is_open()) {
		return -1;// error
	}
	else {
		ofstream temp; // temp file to copy all content from the current file
		temp.open("temp.txt");

		if (!temp.is_open()) {
			return -2;// error
		}
		else {
			while (getline(fin, line)) {
				if (line != username) {// copy all lines to the temp file, except for the current password
					temp << line << endl;
				}
				else {
					temp << line << endl;
					fin.ignore();
					getline(fin, erased);// ignore the line that have the current password
				}
			}

			temp.close();
			fin.close();

			const char* p = path.c_str(); // required conversion for remove and rename functions
			remove(p);
			rename("temp.txt", p);
		}
	}
	return 1;
}


// Write the new password to the file
int WriteNewPass(string path, string username, string newPass) {
	string line, erased;
	ifstream fin;

	fin.open(path);
	if (!fin.is_open()) {
		return -1;// error
	}
	else {
		ofstream temp; // temp file to copy all content from the current file
		temp.open("temp.txt");

		if (!temp.is_open()) {
			return -2;// error
		}
		else {
			while (getline(fin, line)) {
				if (line != username) {// copy all lines to the temp file, 
									   // when reach the line after the username, write the new password
					temp << line << endl;
				}
				else {
					temp << line << endl;
					temp << newPass << endl;
				}
			}

			temp.close();
			fin.close();

			const char* p = path.c_str(); // required conversion for remove and rename functions
			remove(p);
			rename("temp.txt", p);
		}
	}
	return 1;
}

bool ChangePass(string path, string username, string password) {
	string OldPass, NewPass1, NewPass2;

	do {
		cout << "enter current password: ";
		cin >> OldPass;
		if (OldPass != password)
			cout << "incorrect password, please re-enter" << endl;
	} while (OldPass != password);

	do {
		cout << "enter new password: ";
		cin >> NewPass1;
		cout << "re-enter new password: ";
		cin >> NewPass2;

		if (NewPass1 != NewPass2)
			cout << "does not match, please re-enter" << endl;
		else if (NewPass2 == OldPass)
			cout << "new password can not be the same as the old password, please re-enter" << endl;

	} while (NewPass1 != NewPass2 || NewPass2 == OldPass);

	eraseCurPass(path, username);
	WriteNewPass(path, username, NewPass2);
	if (eraseCurPass(path, username) < 0 || WriteNewPass(path, username, NewPass2) < 0)
		return false;
	return true;
}