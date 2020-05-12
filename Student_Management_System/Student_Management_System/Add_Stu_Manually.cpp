#include "Declarations.h"

int ClassPos(string Class) {/* function to return the position of a class in the following list: 
1-19APCS1
2-19APCS2
3-19CLC1
4-19CLC2
5-19CLC3
6-19CLC4
7-19CLC5
8-19CLC6
9-19CLC7
10-19CLC8
11-19CLC9
12-19CLC10
13-19CLC11
*/
	if (Class == "19APCS1") return 1;
	if (Class == "19APCS2") return 2;
	if (Class == "19CLC1") return 3;
	if (Class == "19CLC2") return 4;
	if (Class == "19CLC3") return 5;
	if (Class == "19CLC4") return 6;
	if (Class == "19CLC5") return 7;
	if (Class == "19CLC6") return 8;
	if (Class == "19CLC7") return 9;
	if (Class == "19CLC8") return 10;
	if (Class == "19CLC9") return 11;
	if (Class == "19CLC10") return 12;
	if (Class == "19CLC11") return 13;
	return 0;// wrong class code
}

int AddToClass(string Class, Stu newstu) {
	int Pos = ClassPos(Class);
	switch (Pos) {
	case 1: {// 19APCS1
		ifstream fin;
		fin.open("Student-19APCS1.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19APCS1.txt");// remove old file
			rename("temp.txt", "Student-19APCS1.txt");// rename the temp file
			return 0;
		}
	}
	case 2: {// 19APCS2
		ifstream fin;
		fin.open("Student-19APCS2.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19APCS2.txt");// remove old file
			rename("temp.txt", "Student-19APCS2.txt");// rename the temp file
			return 0;
		}
	}
	case 3: {// 19CLC1
		ifstream fin;
		fin.open("Student-19CLC1.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC1.txt");// remove old file
			rename("temp.txt", "Student-19CLC1.txt");// rename the temp file
			return 0;
		}
	}
	case 4: {// 19CLC2
		ifstream fin;
		fin.open("Student-19CLC2.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC2.txt");// remove old file
			rename("temp.txt", "Student-19CLC2.txt");// rename the temp file
			return 0;
		}
	}
	case 5: {// 19CLC3
		ifstream fin;
		fin.open("Student-19CLC3.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC3.txt");// remove old file
			rename("temp.txt", "Student-19CLC3.txt");// rename the temp file
			return 0;
		}
	}
	case 6: {
		ifstream fin;
		fin.open("Student-19CLC4.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC4.txt");// remove old file
			rename("temp.txt", "Student-19CLC4.txt");// rename the temp file
			return 0;
		}
	}
	case 7: {
		ifstream fin;
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
						temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC5.txt");// remove old file
			rename("temp.txt", "Student-19CLC5.txt");// rename the temp file
			return 0;
		}
	}
	case 8: {
		ifstream fin;
		fin.open("Student-19CLC6.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC6.txt");// remove old file
			rename("temp.txt", "Student-19CLC6.txt");// rename the temp file
			return 0;
		}
	}
	case 9: {
		ifstream fin;
		fin.open("Student-19CLC7.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC7.txt");// remove old file
			rename("temp.txt", "Student-19CLC7.txt");// rename the temp file
			return 0;
		}
	}
	case 10: {
		ifstream fin;
		fin.open("Student-19CLC8.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC8.txt");// remove old file
			rename("temp.txt", "Student-19CLC8.txt");// rename the temp file
			return 0;
		}
	}
	case 11: {
		ifstream fin;
		fin.open("Student-19CLC9.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC9.txt");// remove old file
			rename("temp.txt", "Student-19CLC9.txt");// rename the temp file
			return 0;
		}
	}
	case 12: {
		ifstream fin;
		fin.open("Student-19CLC10.txt");
		if (!fin.is_open()) {
			return -1;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");

			if (!temp.is_open()) {
				return -2;
			}
			else {
				int numofstu;// number of student
				fin >> numofstu;
				fin.ignore();

				temp << numofstu + 1 << endl;// update the number of student in the class
				string line;
				while (getline(fin, line)) {// copy all existing student to temp
					temp << line << endl;
				}

				// print out the information of the new student
				temp << newstu.Fullname << endl;
				temp << newstu.ID << endl;
				temp << newstu.Password << endl;
				temp << newstu.DoB << endl;
				temp << endl;
			}

			temp.close();
			fin.close();

			remove("Student-19CLC10.txt");// remove old file
			rename("temp.txt", "Student-19CLC10.txt");// rename the temp file
			return 0;
		}
	}
	}
	return -3;// wrong class
}

int AddToDataBase(Stu newstu) {
	ifstream fin;
	fin.open("Student.txt");
	if (!fin.is_open()) {
		return -1;
	}
	else {
		ofstream temp;
		temp.open("temp.txt");

		if (!temp.is_open()) {
			return -2;
		}
		else {
			int numofstu;// number of student
			fin >> numofstu;
			fin.ignore();

			temp << numofstu + 1 << endl;// update the number of student in the class
			string line;
			while (getline(fin, line)) {// copy all existing student to temp
				temp << line << endl;
			}

			// print out the information of the new student
			temp << newstu.Fullname << endl;
			temp << newstu.ID << endl;
			temp << newstu.Password << endl;
			temp << newstu.DoB << endl;
			temp << newstu.Class << endl;
			temp << endl;
		}

		temp.close();
		fin.close();

		remove("Student.txt");// remove old file
		rename("temp.txt", "Student.txt");// rename the temp file
	}
	return 0;
}

int AddStuManually() {
	string C;
	cout << "Enter class: ";
	cin >> C;

	if (ClassPos(C) == 0) {
		do {
			cout << "Incorrect class code, please re-enter: ";
			cin >> C;
		} while (ClassPos(C) == 0);// wrong class code, enter again
	}
	cin.ignore();

	Stu newstu;
	newstu.Class = C;
	cout << "Enter fullname: ";
	getline(cin, newstu.Fullname);
	cout << "Enter ID: ";
	getline(cin, newstu.ID);
	cout << "Enter DoB(yyyy-mm-dd): ";
	getline(cin, newstu.DoB);

	newstu.Password = newstu.DoB;
	for (int i = 0; i < newstu.Password.length(); i++) {// delete all '-' from the password
														// Ex: 2001-11-04 will be turn into 20011104
		if (newstu.Password[i] == '-') {
			newstu.Password.erase(newstu.Password.begin() + i);// delete the character at position i from the string
		}
	}

	if (AddToClass(C, newstu) < 0) return -1;// fail at adding to class
	if (AddToDataBase(newstu) < 0) return -2;// fail at adding to data base
	return 0;
}