#include "Declarations.h"

void EditScoreboard(ifstream& fin, ofstream& fout, FileCourse**& a, FileSchedule*& s, int& counts, string& username, int& NumofStu, int& countdays)
{
	string x;
	string y;
	string f;
	string Class;
	string ID;
	cout << "\nEnter academic year(YYYY-YYYY): " << endl;//2019-2020
	cin.ignore();
	getline(cin, x);

	cout << "\nEnter semester (Ex:HK2) :" << endl;//HK2
	getline(cin, y);
	cout << "\nEnter class (Ex:19CLC5)" << endl;//19CLC5
	getline(cin, Class);
	//cout << "\nEnter course (Ex:CS162) " << endl;//19CLC5-Schedule.csv
	//getline(cin, course);


	f = x + "-" + y + "-" + "Schedule-" + Class + ".txt"; //f for example 2019-2020-HK2-Schedule-19CLC5.txt
	fin.open(f.c_str());
	if (!fin.is_open())
	{
		cout << "\nCant find Class" << endl;
		return;
	}
	else
	{
		counts = 0;
		Load_Schedule_txt(fin, s, counts);
		fin.close();
		int i = 0;
		while (s[i].LUser != username)
		{
			i++;
			if (i > counts)
			{
				break;
			}
		}
		if (i > counts)
		{
			cout << "\nYou do not teach " << Class << " class " << endl;
			return;
		}
		else {
			string CourseID = s[i].courseID;
			string courseName = s[i].courseName;
			cout << "\nYou teach " << CourseID << "-" << courseName << " in " << Class << endl;
			string z = x + "-" + y + "-" + Class + "-" + CourseID + "-Student.txt"; //f for example 2019-2020-HK2-19CLC5-CS162-Student.txt
			fin.open(z.c_str());
			if (!fin.is_open())
			{
				cout << "Cant open file Course" << endl;
			}
			else {
				NumofStu = 0;
				countdays = 0;
				readcoursefile(fin, a, NumofStu, countdays);
				fin.close();
				cout << "Enter ID of Student:" << endl;
				getline(cin, ID);
				i = 0;
				while (a[i][0].ID != ID)
				{
					i++;
					if (i >= NumofStu)
					{
						break;
					}
				}
				if (i >= NumofStu)
				{
					cout << "\nCant find student " << Class << " class " << endl;
					return;

				}
				else {
					cout << a[i][0].ID << "-" << a[i][0].Name << endl;
					cout << "No\tID\t        Full Name   \t      Midterm\t    Final\t\  Bonus\t         Total\n";
					cout << i + 1 << "\t" << a[i][0].ID;
					cout << "\t" << a[i][0].Name;
					cout << "\t" << "        " << a[i][0].miterm;
					cout << "\t" << "     " << a[i][0].final;
					cout << "\t" << "           " << a[i][0].bonus;
					cout << "\t" << "          " << a[i][0].total;
					if (a[i][0].active == "0")
					{
						cout << "\t" << "    Inactive" << endl;
					}
					else
					{
						cout << endl;
					}
					int choice;
					float midterm;
					float final;
					float bonus;
					float total;
					cout << "\n-----MENU------\n";
					cout << "0.Return Menu\n1.Edit Midterm\n2.Edit Final\n3.Edit Bonus\nYour choice is? (Only return menu score will save)\n";
					cin >> choice;
					while (choice > 3 || choice < 0)
					{
						cout << "Enter choice again:" << endl;
						cin >> choice;
					}

					while (choice == 1)
					{
						cout << "Edit midterm score(Ex:9.0) :";
						cin >> midterm;
						while (midterm > 10 || midterm < 0)
						{
							cout << "Please Enter Midterm again:";
							cin >> midterm;
						}
						a[i][0].miterm = to_string(midterm);
						final = stoi(a[i][0].final);
						bonus = stoi(a[i][0].bonus);
						total = ((midterm + final * 2) / 3) + bonus;
						cout << "Total after fix: " << setprecision(1) << fixed << total << endl;
						a[i][0].total = to_string(total);
						cout << "\n-----MENU------\n";
						cout << "0.Return Menu\n1.Edit Midterm\n2.Edit Final\n3.Edit Bonus\nYour choice is?(Only return menu score will save)\n";
						cin >> choice;
					}
					while (choice == 2)
					{
						cout << "Edit final score(Ex:9.0) :";
						cin >> final;
						while (final > 10 || final < 0)
						{
							cout << "Please Enter final again:";
							cin >> final;
						}
						a[i][0].final = to_string(final);
						midterm = stoi(a[i][0].miterm);
						bonus = stoi(a[i][0].bonus);
						total = ((midterm + final * 2) / 3) + bonus;
						cout << "Total after fix: " << setprecision(1) << fixed << total << endl;
						a[i][0].total = to_string(total);
						cout << "\n-----MENU------\n";
						cout << "0.Return Menu\n1.Edit Midterm\n2.Edit Final\n3.Edit Bonus\nYour choice is?(Only return menu score will save)\n";
						cin >> choice;
					}
					while (choice == 3)
					{
						cout << "Edit bonus score(Ex:1.0)(Bonus<2) :";
						cin >> bonus;
						while (bonus > 2 || bonus < 0)
						{
							cout << "Please Enter bonus again:";
							cin >> bonus;
						}
						a[i][0].bonus = to_string(bonus);
						midterm = stoi(a[i][0].miterm);
						final = stoi(a[i][0].final);
						total = ((midterm + final * 2) / 3) + bonus;
						cout << "Total after fix: " << setprecision(1) << fixed << total << endl;
						a[i][0].total = to_string(total);
						cout << "\n-----MENU------\n";
						cout << "0.Return Menu\n1.Edit Midterm\n2.Edit Final\n3.Edit Bonus\nYour choice is?(Only return menu score will save)\n";
						cin >> choice;
					}
					if (choice == 0)
					{
						fout.open(z.c_str());
						savetocoursefile(fout, NumofStu, countdays, a);
						fout.close();
						delete[] a;
						delete[] s;
						return;
					}
				}
			}
		}
	}
}