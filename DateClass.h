#include <iostream>
using namespace std;

class Date
{
	private:
		int year, month, day;
		const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		const string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
    public:
		Date(int d = 1, int m = 1, int y = 1900);
		~Date();
		void setDate(int d = 1, int m = 1, int y = 1900);
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
		int getDay() const { return day; }
		int getMonth() const { return month; }
		int getYear() const { return year; }
		void IncreaseDay();
		void PrintDate();
};

Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}

Date::~Date()
{
	cout << "Date destroyed" << endl;
}

void Date::setDay(int d)
{
	if (d >= 1 && d <= monthDays[month - 1])
		day = d;
	else
		day = 1;
}

void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 1;
}

void Date::setYear(int y)
{
	if (y >= 1900)
		year = y;
	else
		year = 1900;
}

void Date::setDate(int d, int m, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::IncreaseDay()
{
	if (day < monthDays[month - 1])
		day++;
	else
	{
		day = 1;
		if (month < 12)
			month++;
		else
		{
			month = 1;
			year++;
		}	
	}
}

void Date::PrintDate()
{
	cout << day << " " << months[month - 1] << " " << year << endl;
}