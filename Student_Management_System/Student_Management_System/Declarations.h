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


// Function 1.1 (Login)
void LoadStudent(ifstream& fin, Stu*& a, int& NumofStu);
void LoadLect(ifstream& fin, Lect*& a, int& NumofLect);
void LoadStaf(ifstream& fin, Staf*& a, int& NumofStaf);
string Login(string user, string pass);

// Function 1.4 (Change Password)
void eraseCurPass(string path, string username);
void WriteNewPass(string path, string username, string newPass);
void ChangePass(string path, string username, string password);

#endif