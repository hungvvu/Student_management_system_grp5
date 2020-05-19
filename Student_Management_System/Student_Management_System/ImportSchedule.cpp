#include "Declarations.h"


void LoadScheduleCsv(ifstream& fin,FileSchedule *&s,int &countcsv) {

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

void SaveSchedule(ofstream &fout, FileSchedule*& s,int &countcsv)
{
	for (int i = 0; i < countcsv-1; i++)
	{
		fout << s[i].No << endl;
		fout << s[i].courseID << endl;
		fout << s[i].courseName<< endl;
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

void saveListOfStudent(ofstream& Schedule, Stu*& a, int &NumofStu,int&j,FileSchedule* &s)
{
	int d1=0, d2=0;
	int m1=0, m2=0;
	int y1=0, y2=0;
	int weekdays=0;
	Schedule << NumofStu << endl;
	for (int i = 0; i < NumofStu; i++)
	{
		Schedule << a[i].Fullname << endl;
		Schedule << a[i].ID << endl;
		Schedule << a[i].Password << endl;
		Schedule << a[i].DoB << endl;
		Schedule << "-1"<<endl;
		Schedule << "-1" << endl;
		Schedule << "-1" << endl;
		Schedule << "-1"<<endl;
		DateToFIle(Schedule, d1, d2, m1, m2, y1, y2, weekdays, s, j);
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
	for (int i = 0; i < countcsv-1; i++)
	{
		string filename;
		filename = x + "-" + y + "-" + Class + "-" + s[i].courseID + "-Student.txt"; //2019-2020-HK2-19CLC5-CS1612-Student.txt or cm101
		
		j = i;

		Schedule.open(filename.c_str());
		if (!Schedule.is_open())
			cout << "Cant open file:";
		else {
			cout << j << "is" << s[j].enddateday << endl;
			saveListOfStudent(Schedule, a, NumofStu,j,s);
		}
		Schedule.close();
	}
	cout << "\nImport SuccessFully!!!!!";
}