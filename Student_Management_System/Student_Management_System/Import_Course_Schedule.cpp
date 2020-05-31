#include "Declarations.h"

void LoadStudentClass(ifstream& fin, Stu*& a, int& NumofStu) {
	fin >> NumofStu;

	if (NumofStu == 0) {
		return;
	}

	// alocate new array of student
	a = new Stu[NumofStu];

	fin.ignore();// get rid of the "\n"
	for (int i = 0; i < NumofStu; i++) {
		getline(fin, a[i].Fullname);
		getline(fin, a[i].ID);
		getline(fin, a[i].Password);
		getline(fin, a[i].DoB);
		fin.ignore();// skip the empty line
	}
}
void LoadScheduleCsv(ifstream& fin, FileSchedule*& s, int& countcsv) {

	int i = 0;
	s = new FileSchedule[20];
	//fin.ignore();//skip the first Line

	while (fin.good())
	{
		getline(fin, s[i].No, ',');
		getline(fin, s[i].courseID, ',');
		getline(fin, s[i].courseName, ',');
		getline(fin, s[i].Class, ',');
		getline(fin, s[i].LUser, ',');
		getline(fin, s[i].LName, ',');
		getline(fin, s[i].Ldegree, ',');
		getline(fin, s[i].Lgender, ',');
		getline(fin, s[i].startdateday, '/');
		getline(fin, s[i].startdatemonth, '/');
		getline(fin, s[i].startdateyear, ',');
		getline(fin, s[i].enddateday, '/');
		getline(fin, s[i].enddatemonth, '/');
		getline(fin, s[i].enddateyear, ',');
		getline(fin, s[i].dayofweek, ',');
		getline(fin, s[i].starthour, ',');
		getline(fin, s[i].startminute, ',');
		getline(fin, s[i].endhour, ',');
		getline(fin, s[i].endminute, ',');
		getline(fin, s[i].Room, '\n');
		i++;

	}
	countcsv = i;

} //Read File Schedule.csv

void SaveSchedule(ofstream& fout, FileSchedule*& s, int& countcsv)
{
	for (int i = 0; i < countcsv; i++)
	{
		fout << s[i].No << endl;
		fout << s[i].courseID << endl;
		fout << s[i].courseName << endl;
		fout << s[i].Class << endl;
		fout << s[i].LUser << endl;
		fout << s[i].LName << endl;
		fout << s[i].Ldegree << endl;
		fout << s[i].Lgender << endl;
		fout << s[i].startdateday << " ";
		fout << s[i].startdatemonth << " ";
		fout << s[i].startdateyear << endl;
		fout << s[i].enddateday << " ";
		fout << s[i].enddatemonth << " ";
		fout << s[i].enddateyear << endl;
		fout << s[i].dayofweek << endl;
		fout << s[i].starthour << endl;
		fout << s[i].startminute << endl;
		fout << s[i].endhour << endl;
		fout << s[i].endminute << endl;
		fout << s[i].Room << endl;
		fout << endl;
	}
}

void saveListOfStudent(ofstream& Schedule, Stu*& a, int& NumofStu, int& j, FileSchedule*& s, int& d1, int& d2, int& m1, int& m2, int& y1, int& y2, int& weekdays)
{
	/*int d1=0, d2=0;
	int m1=0, m2=0;
	int y1=0, y2=0;
	int weekdays=0;*/
	Schedule << NumofStu << endl;
	for (int i = 0; i < NumofStu; i++)
	{
		int d1 = stoi(s[j].startdateday);
		int m1 = stoi(s[j].startdatemonth);
		int y1 = stoi(s[j].startdateyear);
		int d2 = stoi(s[j].enddateday);
		int m2 = stoi(s[j].enddatemonth);
		int y2 = stoi(s[j].enddateyear);
		int weekdays = 0;
		if (s[j].dayofweek == "MON")
		{
			weekdays = 2;
		}
		if (s[j].dayofweek == "TUE")
		{
			weekdays = 3;
		}
		if (s[j].dayofweek == "WED")
		{
			weekdays = 4;
		}
		if (s[j].dayofweek == "THUR")
		{
			weekdays = 5;
		}
		if (s[j].dayofweek == "FRI")
		{
			weekdays = 6;
		}
		if (s[j].dayofweek == "SAT")
		{
			weekdays = 7;
		}
		Schedule << a[i].Fullname << endl;
		Schedule << a[i].ID << endl;
		Schedule << a[i].Password << endl;
		Schedule << a[i].DoB << endl;
		Schedule << "-1" << endl;//active and inactive
		Schedule << "-1" << endl;
		Schedule << "-1" << endl;
		Schedule << "-1" << endl;
		Schedule << "-1" << endl;
		DateToFIle(Schedule, d1, d2, m1, m2, y1, y2, weekdays, s, j);
		/*Schedule <<" "<< s[j].starthour << " " << s[j].startminute << " " << s[j].endhour << " " << s[j].endminute << " "<< "-1"<<endl;*/
		Schedule << endl;
	}

}

void ImportSchedule(ifstream& fin, FileSchedule*& s, int& countcsv, ifstream& fin2, Stu*& a, int& NumofStu)
{
	string x;
	string y;
	string z;
	string f;
	string Class;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter file Schedule Name:" << endl;//19CLC5-Schedule.csv
	getline(cin, z);

	//x = "string";
	//x = x + ".txt";
	f = x + "-" + y + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

	fin.open(z.c_str()); //open file schedule
	while (!fin.is_open())
	{
		cout << "Cant open file";
		cout << "\nPlease enter file Schedule Name again: " << endl;
		getline(cin, z);
		fin.close();
		fin.open(z.c_str());
	}
	LoadScheduleCsv(fin, s, countcsv);
	fin.close();

	fin.open("Lecturer.txt");
	Lect* b;
	int NumofLect = 0;
	LoadLect2(fin, b, NumofLect);
	fin.close();
	int h = 0;
	while (h < countcsv)
	{
		if (checkLecturer(s, b, NumofLect, countcsv, h) == true)
		{
			NumofLect++;
			b[NumofLect - 1].Username = s[h].LUser;
			b[NumofLect - 1].Name = s[h].LName;
			b[NumofLect - 1].Password = s[h].LUser;
			b[NumofLect - 1].Degree = s[h].Ldegree;
			if (s[h].Lgender == "Male"|| s[h].Lgender == "male")
			{
				b[NumofLect - 1].Sex = 0;
			}
		}
		h++;
	}
	ofstream fout;
	fout.open("Lecturer.txt");
	SaveLectFromCsv(fout, b, NumofLect);
	fout.close();


	ofstream Schedule;
	Schedule.open(f.c_str());
	if (!Schedule.is_open())
		cout << "Cant open file:";

	else
	{
		SaveSchedule(Schedule, s, countcsv);
		Schedule.close();
	}// file 2019-2020-HK2-Schedule-19CLC5.txt

	string Student_Class;
	Student_Class = "Student-" + Class + ".txt";
	fin2.open(Student_Class.c_str());
	LoadStudentClass(fin2, a, NumofStu); // Read  file Student-19CLC5-txt
	fin2.close();
	int j;
	for (int i = 0; i < countcsv; i++)
	{
		string filename;
		filename = x + "-" + y + "-" + Class + "-" + s[i].courseID + "-Student.txt"; //2019-2020-HK2-19CLC5-CS1612-Student.txt or cm101

		j = i;

		Schedule.open(filename.c_str());
		if (!Schedule.is_open())
			cout << "Cant open file:";
		else {
			int d1 = 0;
			int m1 = 0;
			int y1 = 0;
			int d2 = 0;
			int m2 = 0;
			int y2 = 0;
			int weekdays = 0;
			//if (s[j].dayofweek == "MON")
			//{
			//	weekdays = 2;
			//}
			//if (s[j].dayofweek == "TUE")
			//{
			//	weekdays = 3;
			//}
			//if (s[j].dayofweek == "WED")
			//{
			//	weekdays = 4;
			//}
			//if (s[j].dayofweek == "THUR")
			//{
			//	weekdays = 5;
			//}
			//if (s[j].dayofweek == "FRI")
			//{
			//	weekdays = 6;
			//}
			//if (s[j].dayofweek == "SAT")
			//{
			//	weekdays = 7;
			//}

			saveListOfStudent(Schedule, a, NumofStu, j, s, d1, d2, m1, m2, y1, y2, weekdays);
		}
		Schedule.close();
	}

//	int i = 0;
//	if (checkLecturer(s, b, NumofLect, countcsv) == true)
//	{
//		NumofLect++;
//		ofstream fout3;
//		fout3.open("Lecturer.txt");
//		if (!fout3.is_open())
//		{
//			cout << "Cant open file Lecturer.txt";
//		}
//		else
//		{
//			i = 0;
//			while (i < countcsv)
//			{
//				NumofLect++;
//				b[NumofLect - 1].Name = s[i].LName;
//				b[NumofLect - 1].Username=s[i].LUser;
//				b[NumofLect - 1].Password = s[i].LUser;
//				b[NumofLect - 1].Degree = s[i].Ldegree;
//				if (s[i].Lgender == "Male")
//				{
//					b[NumofLect - 1].Sex = 0;
//				}
//				else
//				{
//					b[NumofLect - 1].Sex = 1;
//				}
//			}
//		}
//		SaveLectFromCsv(fout3, b, NumofLect);
//	}

//}
	delete[] a;
	delete[] s;
	cout << "\nImport SuccessFully!!!!!";
}

bool checkLecturer(FileSchedule*& s, Lect*& b, int& NumofLect, int& countcsv, int& h)
{
	for (int i = 0; i < NumofLect; i++)
	{
		if (b[i].Username == s[h].LUser)
		{
			return false;
		}
	}
	return true;
}
void LoadLect2(ifstream& fin, Lect*& a, int& NumofLect) {
	fin >> NumofLect;

	if (NumofLect == 0) {
		return;
	}

	a = new Lect[100];

	fin.ignore();// get rid of the "\n"
	for (int i = 0; i < NumofLect; i++) {
		getline(fin, a[i].Name);
		getline(fin, a[i].Username);
		getline(fin, a[i].Password);
		getline(fin, a[i].Degree);
		fin >> a[i].Sex;
		fin.ignore();// skip the empty line
		fin.ignore();// skip the empty line
	}
}
//
void SaveLectFromCsv(ofstream& fout3, Lect*& b, int& NumofLect)
{
	fout3 << NumofLect << endl;
	for (int i = 0; i < NumofLect; i++)
	{
		fout3 << b[i].Name << endl;
		fout3 << b[i].Username << endl;
		fout3 << b[i].Password << endl;
		fout3 << b[i].Degree << endl;
		fout3 << b[i].Sex << endl;
		fout3 << endl;
	}
}