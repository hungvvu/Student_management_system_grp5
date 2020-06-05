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

	string startdate;
	string enddate;
};

struct FileCourse
{
	string Name;
	string ID;
	string Password;
	string DoB;
	string miterm;
	string active;
	string final;
	string bonus;
	string total;
	string learning;

	//add 
	//string day;
	//string month;
	//string year;
	//string starthour;
	//string startminute;
	//string endhour;
	//string endminute;
	//string attend;
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
bool checkLecturer(FileSchedule*& s, Lect*& b, int& NumofLect, int& countcsv, int& h);
void SaveLectFromCsv(ofstream& fout3, Lect*& b, int& NumofLect);
void LoadLect2(ifstream& fin, Lect*& a, int& NumofLect);

bool check_date(int day, int month);
bool check_month(int month);
bool check_year(int year);
bool check_leap_year(int year);
const char* get_day(int day, int month, int year);
void nextmonth(int& d1, int& m1, int& y1);
void DateToFIle(ofstream& fout, int& d1, int& d2, int& m1, int& m2, int& y1, int& y2, int& weekdays, FileSchedule*& s, int& j);


// Function 3.4 (Edit a course)
int CountCourse(ifstream& fin);// count how many courses are there in the file
void LoadCourse(ifstream& fin, FileSchedule*& Courses, int& n);
void editCourseField(FileSchedule& course, int choice);
int EditCourseArray(FileSchedule*& courses, int n, string& oldID);
void SaveCoursesToFile(ofstream& fout, FileSchedule* courses, int n);// save the array with the edited course back to the file
void EditCourse();

// Function 3.5 (Remove Course)
void Load_Schedule_txt(ifstream& fin, FileSchedule*& s, int& counts);
void RemoveCourseInSchedule(string& CourseID, FileSchedule*& s, int& counts, string& k, ofstream& fout);
void RemoveCourse(FileSchedule*& s, int& counts, string& k);

// Function 3.7 (Add a student to a course)
void AddToFile(ifstream& fin, string OldFileName, Stu S, FileSchedule* Courses, int CourseIndex);
void AddStu2Course();

//Function 3.8 (View List of course)
void Load_Schedule_txt(ifstream& fin, FileSchedule*& s, int& counts);
void View_List_Of_Course(FileSchedule*& s, int& counts);

//Function 3.11(View All Lecturers)
void View_ALL_Lecturers(ifstream& fin, Lect*& a, int& NumofLect);

//Function 4.1(Search and View ScoreBoard)
void readcoursefile(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays);
void printoutscore(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays);

//Function 6.4(Edit an Attandance)
void Load_Schedule_txt(ifstream& fin, FileSchedule*& s, int& counts);
//void readcoursefile2(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays); //to read seperately from check in
void readcoursefile(ifstream& fin, FileCourse**& a, int& NumofStu, int& countdays);
void Edit_Attandance(ifstream& fin, ofstream& fout, FileCourse**& a, FileSchedule*& s, int& counts, string& username, int& NumofStu, int& countdays);
void savetocoursefile(ofstream& fout, int& NumofStu, int& countdays, FileCourse**& a);



#endif