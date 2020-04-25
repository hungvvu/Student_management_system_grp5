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


int mainmenu(int& choice1);

int MenuStudent(int& choice2);

int MenuStaff(int& choice2);

int MenuLecturer(int& choice2);

void showmenu(int& choice1, int& choice2, string Position);

void Profile(string user, string pass);

void ImportStudent(ifstream& fin, Stu*& a, int& NumofStu);

void CSVStudent();


// Function 1.1 (Login)
void LoadStudent(ifstream& fin, Stu*& a, int& NumofStu);
void LoadLect(ifstream& fin, Lect*& a, int& NumofLect);
void LoadStaf(ifstream& fin, Staf*& a, int& NumofStaf);
string Login(string user, string pass);

#endif