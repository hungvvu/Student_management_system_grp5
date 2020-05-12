#include "Declarations.h"

int Load_1Stu_Class(string Class, string ID, Stu& Student) {
	int Pos = ClassPos(Class);
	switch (Pos) {
	case 1: {
		ifstream fin;
		fin.open("Student-19APCS1.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19APCS1";

			fin.close();
		}
	}
	case 2: {
		ifstream fin;
		fin.open("Student-19APCS2.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19APCS2";

			fin.close();
		}
	}
	case 3: {
		ifstream fin;
		fin.open("Student-19CLC1.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC1";

			fin.close();
		}
	}
	case 4: {
		ifstream fin;
		fin.open("Student-19CLC2.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC2";

			fin.close();
		}
	}
	case 5: {
		ifstream fin;
		fin.open("Student-19CLC3.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC3";

			fin.close();
		}
	}
	case 6: {
		ifstream fin;
		fin.open("Student-19CLC4.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC4";

			fin.close();
		}
	}
	case 7: {
		ifstream fin;
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC5";

			fin.close();
		}
	}
	case 8: {
		ifstream fin;
		fin.open("Student-19CLC6.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC6";

			fin.close();
		}
	}
	case 9: {
		ifstream fin;
		fin.open("Student-19CLC7.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC7";

			fin.close();
		}
	}
	case 10: {
		ifstream fin;
		fin.open("Student-19CLC8.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC8";

			fin.close();
		}
	}
	case 11: {
		ifstream fin;
		fin.open("Student-19CLC9.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC9";

			fin.close();
		}
	}
	case 12: {
		ifstream fin;
		fin.open("Student-19CLC10.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return -1;
		}
		else {
			int NumofStu;
			fin >> NumofStu;

			if (NumofStu == 0) {
				return -2;// class have 0 student
			}

			fin.ignore();// get rid of the "\n"
			do {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				fin.ignore();// skip the empty line

				NumofStu--;
			} while (Student.ID != ID && NumofStu > 0);// find the student with given ID in this class
			if (Student.ID != ID) return -2;// can't find given student in this class
			Student.Class = "19CLC10";

			fin.close();
		}
	}
	}
	return 0;
}

bool RemoveFromClass(string Class, string ID) {
	int Pos = ClassPos(Class);
	switch (Pos) {
	case 1: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19APCS1.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19APCS1.txt");// remove old file
				rename("temp.txt", "Student-19APCS1.txt");// rename the temp file
			}
		}
	}
	case 2: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19APCS2.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19APCS2.txt");// remove old file
				rename("temp.txt", "Student-19APCS2.txt");// rename the temp file
			}
		}
	}
	case 3: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC1.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC1.txt");// remove old file
				rename("temp.txt", "Student-19CLC1.txt");// rename the temp file
			}
		}
	}
	case 4: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC2.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC2.txt");// remove old file
				rename("temp.txt", "Student-19CLC2.txt");// rename the temp file
			}
		}
	}
	case 5: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC3.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC3.txt");// remove old file
				rename("temp.txt", "Student-19CLC3.txt");// rename the temp file
			}
		}
	}
	case 6: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC4.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC4.txt");// remove old file
				rename("temp.txt", "Student-19CLC4.txt");// rename the temp file
			}
		}
	}
	case 7: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC5.txt");// remove old file
				rename("temp.txt", "Student-19CLC5.txt");// rename the temp file
			}
		}
	}
	case 8: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC5.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC6.txt");// remove old file
				rename("temp.txt", "Student-19CLC6.txt");// rename the temp file
			}
		}
	}
	case 9: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC7.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC7.txt");// remove old file
				rename("temp.txt", "Student-19CLC7.txt");// rename the temp file
			}
		}
	}
	case 10: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC8.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC8.txt");// remove old file
				rename("temp.txt", "Student-19CLC8.txt");// rename the temp file
			}
		}
	}
	case 11: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC9.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC9.txt");// remove old file
				rename("temp.txt", "Student-19CLC9.txt");// rename the temp file
			}
		}
	}
	case 12: {
		ifstream fin;
		// change the class here for other classes
		fin.open("Student-19CLC10.txt");
		if (!fin.is_open()) {
			cout << "can't open class file";
			return false;
		}
		else {
			ofstream temp;
			temp.open("temp.txt");
			if (!temp.is_open()) {
				cout << "can't open class file";
				return false;
			}
			else {
				int NumofStu;
				fin >> NumofStu;
				fin.ignore();

				temp << NumofStu - 1 << endl;// update the number of student in the class
				Stu Student;
				while (NumofStu > 0) {
					getline(fin, Student.Fullname);
					getline(fin, Student.ID);
					getline(fin, Student.Password);
					getline(fin, Student.DoB);
					fin.ignore();// skip the empty line

					if (Student.ID != ID) {// copy all other students to temp file
						temp << Student.Fullname << endl;
						temp << Student.ID << endl;
						temp << Student.Password << endl;
						temp << Student.DoB << endl;
						temp << endl;
					}
					NumofStu--;
				}

				temp.close();
				fin.close();

				// change the class here for other classes
				remove("Student-19CLC10.txt");// remove old file
				rename("temp.txt", "Student-19CLC10.txt");// rename the temp file
			}
		}
	}
	}
	return true;
}

bool RemoveFromMainData(string ID) {
	ifstream fin;
	fin.open("Student.txt");
	if (!fin.is_open()) {
		cout << "can't open file";
		return false;
	}
	else {
		ofstream temp;
		temp.open("temp.txt");
		if (!temp.is_open()) {
			cout << "can't open file";
			return false;
		}
		else {
			int NumofStu;
			fin >> NumofStu;
			fin.ignore();

			temp << NumofStu - 1 << endl;// update the number of student in the database
			Stu Student;
			while (NumofStu > 0) {
				getline(fin, Student.Fullname);
				getline(fin, Student.ID);
				getline(fin, Student.Password);
				getline(fin, Student.DoB);
				getline(fin, Student.Class);
				fin.ignore();// skip the empty line

				if (Student.ID != ID) {// copy all other students to temp file
					temp << Student.Fullname << endl;
					temp << Student.ID << endl;
					temp << Student.Password << endl;
					temp << Student.DoB << endl;
					temp << Student.Class << endl;
					temp << endl;
				}
				NumofStu--;
			}

			temp.close();
			fin.close();

			remove("Student.txt");// remove old file
			rename("temp.txt", "Student.txt");// rename the temp file
		}
	}
}

bool ChangeStu2Class() {
	string C;
	cout << "enter the current class of the student: ";
	cin >> C;
	while (ClassPos(C) == 0) {// wrong class code, enter again
		cout << "Incorrect class code, please re-enter: ";
		cin >> C;
	}

	string ID;
	cout << "enter student ID: ";
	cin >> ID;
	Stu S;

	// remove that student from the current class
	if (Load_1Stu_Class(C, ID, S) == -1)// can't open file
		return false;
	while (Load_1Stu_Class(C, ID, S) == -2) {// can't find given student in the class
		cout << "cannot find the given student in this class" << endl;
		cout << "please re-enter student ID: ";
		cin >> ID;
	}
	if (!RemoveFromClass(C, ID))
		return false;

	// asign new class for that student
	string nC;
	cout << "enter the new class of the student: ";
	cin >> nC;
	while (ClassPos(nC) == 0 || nC == C) {// wrong class code, enter again
		cout << "Incorrect class code, please re-enter: ";
		cin >> nC;
	}
	S.Class = nC;

	if (AddToClass(nC, S) < 0)// add the student to the new class
		return false;

	// Update the class of that student in the main database
	if (!RemoveFromMainData(ID))
		return false;
	if (!AddToDataBase(S) < 0)
		return false;


	return true;
}