#include "Declarations.h"

int ViewStudent(string Class) {
	int Pos = ClassPos(Class);
	switch (Pos)
	{
	case 1: {// 19APCS1
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19APCS1.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 2: {// 19APCS2
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19APCS2.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 3: {// 19CLC1
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC1.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 4: {// 19CLC2
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC2.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 5: {// 19CLC3
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC3.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 6: {//19CLC4
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC4.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 7: {//19CLC5
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC5.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 8: {//19CLC6
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC6.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 9: {//19CLC7
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC7.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 10: {//19CLC8
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC8.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 11: {//19CLC9
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC9.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	case 12: {//19CLC10
		ifstream fin;
		string line;
		int count;

		//Open file
		fin.open("Student-19CLC10.txt");

		if (!fin.is_open())
		{
			cout << "INPUT FILE ERROR !" << endl;
			return -1;
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

		return 1;
	}
	default:
		return -2;//wrong class
	}
}


int ViewStudentChoice()
{
	string C;
	cout << "Enter Class: ";
	cin >> C;

	while (ViewStudent(C) == -2)
	{
		cout << "This class does not exist. Please enter again: ";
		cin >> C;
	}
	return 0;
}