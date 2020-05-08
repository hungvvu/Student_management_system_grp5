#include "Declarations.h"

int FindClass(string Class, Stu newstu) {
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


void ViewStudent()
{
	ifstream fin;
	string line;
	int count;

	//Open file
	fin.open("Student-19CLC5.txt");

	if (!fin.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fin >> count;
	fin.ignore();

	cout << "There are " << count << " students in this class." << endl;
	cout << endl;

	Stu* StuArr;
	StuArr = new Stu[count];

	int i = 0;

	while (!fin.eof() && i < count)
	{
		getline(fin, StuArr[i].Fullname, '\n');
		getline(fin, StuArr[i].ID, '\n');
		getline(fin, StuArr[i].Password, '\n');
		getline(fin, StuArr[i].DoB, '\n');

		cout << "STUDENT " << i + 1 << ": " << endl;
		cout << "Name: " << StuArr[i].Fullname << endl;
		cout << "ID: " << StuArr[i].ID << endl;
		cout << "Password: " << StuArr[i].Password << endl;
		cout << "Date of Birth: " << StuArr[i].DoB << endl;
		cout << endl;

		fin.ignore();

		i++;
	}

	fin.close();

	delete[] StuArr;
}