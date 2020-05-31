#include "Declarations.h"

int CheckLectInfo(string LUser)
{
	ifstream fin;
	fin.open("Lecturer.txt");

	if (!fin)
	{
		cout << "LECTURER FILE ERROR !" << endl;
		return -1;
	}

	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		if (line == LUser)
		{
			return 0;
		}
	}

	fin.close();

	return 1;
}

void UpdateLectFile(FileSchedule newCourse, string LUser)
{
	int check = CheckLectInfo(LUser);

	if (check == -1) return;
	if (check == 0)
	{
		cout << "This username already exist." << endl;
		return;
	}
	ifstream finold;
	finold.open("Lecturer.txt");
	ofstream temp;
	temp.open("UpdateLect.txt");

	int num;
	finold >> num;
	finold.ignore();
	temp << num + 1 << endl;

	string line1;
	while (getline(finold, line1))
	{
		temp << line1 << endl;
	}

	temp << newCourse.LName << endl;
	temp << newCourse.LUser << endl;
	temp << newCourse.LUser << endl;
	temp << newCourse.Ldegree << endl;
	if (newCourse.Lgender == "male" || newCourse.Lgender == "Male")
	{
		temp << 0 << endl;
	}
	else
	{
		temp << 1 << endl;
	}
	temp << endl;

	temp.close();
	finold.close();

	ifstream finnew;
	finnew.open("UpdateLect.txt");

	ofstream fout;
	fout.open("Lecturer.txt");

	string line2;

	while (getline(finnew, line2))
	{
		fout << line2 << endl;
	}

	fout.close();
	finnew.close();

	return;
}
