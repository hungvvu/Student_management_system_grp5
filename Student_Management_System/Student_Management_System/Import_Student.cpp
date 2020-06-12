#include "Declarations.h"

void CSVStudent()
{
	ifstream fin;
	ofstream fout;
	string line;
	int countAll = 0;

	//Open file first time to input number of all students in this csv file
	fin.open("Import_Student_Info.csv");

	if (!fin.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	while (getline(fin, line))
	{
		countAll++;
	}

	fin.close();

	//Open file second time to input students into array
	fin.open("Import_Student_Info.csv");

	Stu* StuArr;
	StuArr = new Stu[countAll];

	int i = 0;

	while (fin.good() && i < countAll)
	{
		getline(fin, StuArr[i].Class, ',');
		getline(fin, StuArr[i].Fullname, ',');
		getline(fin, StuArr[i].ID, ',');
		getline(fin, StuArr[i].DoB, '\n');

		i++;
	}

	fin.close();

	//**************** Create Student file *******************
	fout.open("All_Students.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	fout << countAll << endl;

	for (int i = 0; i < countAll; i++)
	{
		fout << StuArr[i].Fullname << endl;
		fout << StuArr[i].ID << endl;
		StuArr[i].Password = StuArr[i].DoB;
		
		for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
															// Ex: 2001-11-04 will be turn into 20011104
			if (StuArr[i].Password[j] == '/') {
				StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
			}
		}
		fout << StuArr[i].Password << endl;
		fout << StuArr[i].DoB << endl;
		fout << endl;
	}

	fout.close();

	//**************** Create 19APCS1 file *******************
	fout.open("Student-19APCS1.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count1 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS1") count1++;
	}

	fout << count1 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS1")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19APCS2 file *******************
	fout.open("Student-19APCS2.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count2 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS2") count2++;
	}

	fout << count2 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19APCS2")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC1 file *******************
	fout.open("Student-19CLC1.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count3 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC1") count3++;
	}

	fout << count3 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC1")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC2 file *******************
	fout.open("Student-19CLC2.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}
	int count4 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC2") count4++;
	}

	fout << count4 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC2")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC3 file *******************
	fout.open("Student-19CLC3.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count5 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC3") count5++;
	}

	fout << count5 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC3")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC4 file *******************
	fout.open("Student-19CLC4.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count6 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC4") count6++;
	}

	fout << count6 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC4")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC5 file *******************
	fout.open("Student-19CLC5.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count7 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC5") count7++;
	}

	fout << count7 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC5")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC6 file *******************
	fout.open("Student-19CLC6.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count8 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC6") count8++;
	}

	fout << count8 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC6")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC7 file *******************
	fout.open("Student-19CLC7.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count9 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC7") count9++;
	}

	fout << count9 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC7")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC8 file *******************
	fout.open("Student-19CLC8.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count10 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC8") count10++;
	}

	fout << count10 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC8")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC9 file *******************
	fout.open("Student-19CLC9.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count11 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC9") count11++;
	}

	fout << count11 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC9")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//**************** Create 19CLC10 file *******************
	fout.open("Student-19CLC10.txt");

	if (!fout.is_open())
	{
		cout << "CAN'T OPEN FILE !" << endl;
		return;
	}

	int count12 = 0;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC10") count12++;
	}

	fout << count12 << endl;

	for (int i = 0; i < countAll; i++)
	{
		if (StuArr[i].Class == "19CLC10")
		{
			fout << StuArr[i].Fullname << endl;
			fout << StuArr[i].ID << endl;
			StuArr[i].Password = StuArr[i].DoB;

			for (int j = 0; j < StuArr[i].Password.length(); j++) {// delete all '-' from the password
																// Ex: 2001-11-04 will be turn into 20011104
				if (StuArr[i].Password[j] == '/') {
					StuArr[i].Password.erase(StuArr[i].Password.begin() + j);// delete the character at position i from the string
				}
			}
			fout << StuArr[i].Password << endl;
			fout << StuArr[i].DoB << endl;
			fout << endl;
		}
	}
	fout.close();

	//cout Complete
	cout << endl;
	cout << "IMPORT COMPLETE !" << endl;

	delete[] StuArr;
}