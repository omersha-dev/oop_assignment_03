#include <iostream>
#include "Date.h"
#include "IComparable.h"

using namespace std;

void Date::setDay(int d) { day = d; }
int Date::getDay()  const { return day; }
void Date::setMonth(int m) { month = m; }
int Date::getMonth() const { return month; }
void Date::setYear(int y) { year = y; }
int Date::getYear() const { return year; }

Date::Date(int d, int m, int y) {
	setDay(d);
	setMonth(m);
	setYear(y);
}

void Date::operator= (const Date& other) {
	day = other.getDay();
	month = other.getMonth();
	year = other.getYear();
}

void Date::toOs(ostream& output) const {
	// TODO : Check if leap year!
	output << getDay() << "/" << getMonth() << "/" << getYear();
}

bool Date::isLeapYear(int yearToCheck) const {
	if (yearToCheck % 4 == 0)
	{
		if (yearToCheck % 100 == 0)
		{
			if (yearToCheck % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	return false;
}