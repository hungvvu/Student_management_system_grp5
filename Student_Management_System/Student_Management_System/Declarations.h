#ifndef _DECLARE_
#define _DECLARE_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// data types
struct Stu {
	string Fullname;
	string ID;
	string Password;
	string DoB;
	string Class;
};

struct Lect {
	string Name;
	string Username;
	string Password;
	string Degree;
	int Sex;
};

struct Staf {
	string Name;
	string Username;
	string Password;
	int Sex;
};

struct School
{
	string Class;
};

struct FileSchedule {
	string No;
	string courseID;
	string courseName;
	string Class;
	string LUser;
	string LName;
	string Ldegree;
	string Lgender;
	string startdateday;
	string startdatemonth;
	string startdateyear;
	string enddateday;
	string enddatemonth;
	string enddateyear;
	string dayofweek;
	string starthour;
	string startminute;
	string endhour;
	string endminute;
	string Room;
};

int mainmenu(int& choice1);

int MenuStudent(int& choice2);

int MenuStaff(int& choice2);

int MenuLecturer(int& choice2);

void showmenu(int& choice1, int& choice2, string& Position, string& username, string& password);

void Profile(string user, string pass);


// Function 1.1 (Login)
void LoadStudent(ifstream& fin, Stu*& a, int& NumofStu);
void LoadLect(ifstream& fin, Lect*& a, int& NumofLect);
void LoadStaf(ifstream& fin, Staf*& a, int& NumofStaf);
string Login(string &user, string &pass);

// Function 1.4 (Change Password)
int eraseCurPass(string path, string username);
int WriteNewPass(string path, string username, string newPass);
bool ChangePass(string path, string username, string& password);

// Function 2.2 (Manually add student to class)
int ClassPos(string Class);
int AddToClass(string Class, Stu newstu);
int AddToDataBase(Stu newstu);
int AddStuManually();

// Function 2.3(Edit An Exsitng Student)
void LoadStudentinClass(ifstream& fin, Stu*& a, int& NumofStu);
void EditExsitingStudent(string& ID, Stu*& a, ifstream& fin, int NumofStu, int& x);
void save(ofstream& fout, Stu*& a, int NumofStu);
void EditIntoFile(Stu*& a, string Class);
void save2(ofstream& fout2, Stu*& a, int NumofStu, string& ID, Stu*& b, int x);

//Function 2.4 (Remove a student)
bool Remove_Student();

// Function 2.5 (Change student's class)
int Load_1Stu_Class(string Class, string ID, Stu& Student);
bool RemoveFromClass(string Class, string ID);
bool ChangeStu2Class();
bool RemoveFromMainData(string ID);

// Function 2.6(View List Of Class)
void LoadFileClass(ifstream& fin, int& NumofClass, School*& a);
void ViewListOfClass(ifstream& fin, int& NumofClass, School*& a);

// Function 2.7(View List of Student in Class)
int ViewStudent(string Class);
int ViewStudentChoice();

// Function 3.1 (Create new semester)
bool New_Semester();
string Cur_Semester();

// Function 3.2(Import Schedule)
void LoadStudentClass(ifstream& fin, Stu*& a, int& NumofStu);
void LoadScheduleCsv(ifstream& fin, FileSchedule*& s, int& countcsv);
void ImportSchedule(ifstream& fin, FileSchedule*& s, int& countcsv, ifstream& fin2, Stu*& a, int& NumofStu);
void SaveSchedule(ofstream& fout, FileSchedule*& s, int& countcsv);
void saveListOfStudent(ofstream& Schedule, Stu*& a, int& NumofStu, int& j, FileSchedule*& s, int& d1, int& d2, int& m1, int& m2, int& y1, int& y2, int& weekdays);

bool check_date(int day, int month);
bool check_month(int month);
bool check_year(int year);
bool check_leap_year(int year);
const char* get_day(int day, int month, int year);
void nextmonth(int& d1, int& m1, int& y1);
void DateToFIle(ofstream& fout, int& d1, int& d2, int& m1, int& m2, int& y1, int& y2, int& weekdays, FileSchedule*& s, int& j);

// Function 3.3(Manually Add course)
int AddCourseManually();
void AddToCourseFile(ifstream &fin, FileSchedule newCourse);
void TransferDataFile(string course);
int CheckLectInfo(string LUser);
void UpdateLectFile(FileSchedule newCourse, string LUser);
void CreateNewCFile(string Class, FileSchedule*& newCourse, string x, string y);

#endif