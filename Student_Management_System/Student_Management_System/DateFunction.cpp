#include "Declarations.h"

bool check_date(int day, int month) {
	if ((month == 2) && (day > 0) && (day < 30)) {
		return true;
	}
	if ((
		(month == 1) ||
		(month == 3) ||
		(month == 5) ||
		(month == 7) ||
		(month == 8) ||
		(month == 10) ||
		(month == 12)
		) && ((day > 0) && (day < 32)))
	{
		return true;
	}
	if ((
		(month == 4) ||
		(month == 6) ||
		(month == 9) ||
		(month == 11)
		) && ((day > 0) && (day < 31)))
	{
		return true;
	}
	return false;
}
bool check_month(int month) {
	if ((month > 0) && (month < 13)) {
		return true;
	}
	else {
		return false;
	}
}
bool check_year(int year) {
	if ((year > 999) && (year < 10000)) {
		return true;
	}
	else {
		return false;
	}
}
bool check_leap_year(int year) {
	if (((year % 4) == 0) && ((year % 100) != 0)) {
		return true;
	}
	else if ((year % 400) == 0) {
		return true;
	}
	else {
		return false;
	}
}
const char* get_day(int day, int month, int year) 
{
	int JMD;
	JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
		(365 * (year + 4800 - ((14 - month) / 12))) +
		((year + 4800 - ((14 - month) / 12)) / 4) -
		((year + 4800 - ((14 - month) / 12)) / 100) +
		((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;
	const char* weekday[] = { "Thu 2",
	  "Thu 3",
	  "Thu 4",
	  "Thu 5",
	  "Thu 6",
	  "Thu 7",
	  "Chu nhat" };
	return weekday[JMD];
}
void nextmonth(int& d1, int& m1, int& y1)
{
	if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
	{
		d1 = d1 - 30;
		m1 += 1;
	}
	if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
	{
		d1 = d1 - 31;
		m1 += 1;
	}
	if (d1 > 28 && m1 == 2, check_leap_year(y1) == false) {
		d1 = d1 - 28;
		m1 += 1;
	}
	if (d1 > 29 && m1 == 2 && check_leap_year(y1) == true) {
		d1 = d1 - 29;
		m1 += 1;
	}
}
void DateToFIle(ofstream& fout, int& d1, int &d2, int& m1, int &m2, int& y1, int &y2, int& weekdays,FileSchedule *&s,int &j)//must include struct....
{
	d1 = stoi(s[j].startdateday);
	m1 = stoi(s[j].startdatemonth);
	y1 = stoi(s[j].startdateyear);
	d2 = stoi(s[j].enddateday);
	m2 = stoi(s[j].enddatemonth);
	y2 = stoi(s[j].enddateyear);
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
	if (s[j].dayofweek == "Sat")
	{
		weekdays = 7;
	}
	switch (weekdays)
	{
	case 2: {
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1) == true) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2 && check_leap_year(y1) == false) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 29;
					m1 += 1;
				}
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (/*d1 <= d2 && y1 <= y2 && m1 <= m2*/d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	case 3:
	{
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1)) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 28;
					m1 += 1;
				}
			}
			if (d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	case 4:
	{
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1)) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 28;
					m1 += 1;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	case 5:
	{
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1)) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 28;
					m1 += 1;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	case 6:
	{
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1)) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 28;
					m1 += 1;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	case 7:
	{
		while (1) {
			if (check_year(y1)) {
			}
			else {
				break;
			}
			if (check_month(m1)) {
			}
			else {
				break;
			}
			if (check_date(d1, m1)) {
			}
			else {
				break;
			}
			if (check_leap_year(y1)) {
			}
			else {
				if (m1 == 2 && d1 == 29)
				{
					break;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 2")
			{
				d1 += 5;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 3")
			{
				d1 += 4;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 4")
			{
				d1 += 3;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 5")
			{
				d1 += 2;
				if ((d1 > 30 && m1 == 4) || (d1 > 30 && m1 == 6) || (d1 > 30 && m1 == 9) || (d1 > 30 && m1 == 11))
				{
					d1 = d1 - 30;
					m1 += 1;
				}
				if ((d1 > 31 && m1 == 1) || (d1 > 31 && m1 == 3) || (d1 > 31 && m1 == 5) || (d1 > 31 && m1 == 7) || (d1 > 31 && m1 == 8) || (d1 > 31 && m1 == 10) || (d1 > 31 && m1 == 12))
				{
					d1 = d1 - 31;
					m1 += 1;
				}
				if (d1 > 28 && m1 == 2) {
					d1 = d1 - 28;
					m1 += 1;
				}
				if (d1 > 29 && m1 == 2 && check_leap_year(y1)) {
					d1 = d1 - 28;
					m1 += 1;
				}
			}
			if (get_day(d1, m1, y1) == "Thu 6")
			{
				d1 += 1;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Thu 7")
			{
				d1 += 7;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (get_day(d1, m1, y1) == "Chu nhat")
			{
				d1 += 6;
				nextmonth(d1, m1, y1);
				fout << d1 << " " << m1 << " " << y1 << endl;
			}
			if (d1 >= d2 && y1 == y2 && m1 == m2)
			{
				break;
			}
		}
		break;
	}
	}





}