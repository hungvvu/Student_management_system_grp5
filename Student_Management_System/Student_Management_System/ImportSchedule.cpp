#include "Declarations.h"


void LoadScheduleCsv(ifstream& fin,FileSchedule *&s,int &countcsv) {

	int i = 0;
	s = new FileSchedule[20]; 
	fin.ignore();//skip the first Line

	while (fin.good())
	{
		++i;
		getline(fin, s[i].No, ',');
		getline(fin, s[i].courseID, ',');
		getline(fin, s[i].courseName, ',');
		getline(fin, s[i].Class, ',');
		getline(fin, s[i].LUser, ',');
		getline(fin, s[i].LName, ',');
		getline(fin, s[i].Ldegree, ',');
		getline(fin, s[i].Lgender, ',');
		getline(fin, s[i].startdate, ',');
		getline(fin, s[i].enddate, ',');
		getline(fin, s[i].dayofweek, ',');
		getline(fin, s[i].starthour, ',');
		getline(fin, s[i].startminute, ',');
		getline(fin, s[i].endhour, ',');
		getline(fin, s[i].endminute, ',');
		getline(fin, s[i].Room, ',');
	}
	countcsv = i;

} //Read File Schedule.csv

void SaveSchedule(ofstream &fout, FileSchedule*& s,int &countcsv)
{
	cout << countcsv;
	for (int i = 0; i < countcsv; i++)
	{
		cout << s[i].courseID << endl;
		cout << s[i].courseName<< endl;
		cout << s[i].Class << endl;
		cout << s[i].LUser << endl;
		cout << s[i].LName << endl;
		cout << s[i].Ldegree << endl;
		cout << s[i].Lgender << endl;
		cout << s[i].startdate << endl;
		cout << s[i].enddate << endl;
		cout << s[i].dayofweek << endl;
		cout << s[i].starthour << endl;
		cout << s[i].startminute << endl;
		cout << s[i].endhour << endl;
		cout << s[i].endminute << endl;
		cout << s[i].Room << endl;
		cout << endl;
	}
}

void saveListOfStudent(ofstream& Schedule, Stu*& a, int &NumofStu)
{
	Schedule << NumofStu << endl;
	for (int i = 0; i < NumofStu; i++)
	{
		Schedule << a[i].Fullname << endl;
		Schedule << a[i].ID << endl;
		Schedule << a[i].Password << endl;
		Schedule << a[i].DoB << endl;
		Schedule << endl;
	}

}

void ImportSchedule(ifstream &fin,FileSchedule *&s,int &countcsv,ifstream &fin2,Stu *&a,int & NumofStu)
{
	string x;
	string y;
	string z;
	string f;
	string Class;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester:" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class" << endl;//19CLC5
	getline(cin, Class);
	cout << "\nEnter file Schedule Name:" << endl;//19CLC5-Schedule.csv
	getline(cin, z);
	
	//x = "string";
	//x = x + ".txt";
	f = x + "-" + y + "-" + "Schedule" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt

	fin.open(z.c_str()); //open file schedule
	while (!fin.is_open())
	{
		cout << "Cant open file";
		cout << "\nPlease enter file Schedule Name again: " << endl;
		getline(cin, z);
		fin.open(z.c_str());
	}
	LoadScheduleCsv(fin, s, countcsv);
	fin.close();
	

	
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

	for (int i = 0; i < countcsv; i++)
	{
		string filename;
		filename = x + "-" + y + "-" + Class + "-" + s[i].courseID + "-Student.txt"; //2019-2020-HK2-19CLC5-CS1612-Student.txt or cm101
		Schedule.open(filename.c_str());
		if (!Schedule.is_open())
			cout << "Cant open file:";
		else {
			saveListOfStudent(Schedule, a, NumofStu);
		}
		Schedule.close();
	}
	cout << "Import Success Fully";
}