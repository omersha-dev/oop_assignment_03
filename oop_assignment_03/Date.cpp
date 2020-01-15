#include <iostream>
#include <string>
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
	if (!isLeapYear(this->getDay(), this->getMonth(), this->getYear())) {
		cout << "Not a leap year";
		return;
	}
	output << getDay() << "/" << getMonth() << "/" << getYear();
}

//void Date::toIS(string input, Date& toSet) {
//	int index;
//	index = input.find('/');
//	toSet.setDay((int)input.substr(0, index));
//	input = input.substr(index + 1);
//	index = input.find('/');
//	toSet.setMonth((int)input.substr(0, index));
//	input = input.substr(index + 1);
//	toSet.setYear((int)input);
//}

bool Date::isLeapYear(int d, int m, int y) const {
	if (d == 29 && m == 2) {
		if (y % 400 == 0) return true;
		if (y % 100 == 0) return false;
		if (y % 4 == 0) return true;
		return false;
	}
	return true;
}

string Date::isValidDate(int d, int m, int y) const {
	if (y <= 0) return "Illegal year";
	if (m > 12 || m < 1) return "Illegal month";
	if (d > 31 || d < 1) return "Illegal day for month";
	switch (d) {
		case (31):
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return "Legal";
			return "Illegal day for month";
			break;
		case (30):
			if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) return "Legal";
			return "Illegal day for month";
			break;
		case (29):
			if (!isLeapYear(d, m, y)) return "Illegal day for month";
			return "Legal";
			break;
		default:
			return "Legal";
	}
}

string Date::isValidDate(Date& dateToCheck) const {
	return isValidDate(dateToCheck.getDay(), dateToCheck.getMonth(), dateToCheck.getYear());
}

//bool Date::operator <= (const IComparable<Date> & other) const {
//	const Date* temp = dynamic_cast<const Date*>(&other);
//	if (this->getYear() < temp->getYear()) {
//		return true;
//	}
//	else if (this->getYear() == temp->getYear()) {
//		if (this->getMonth() < temp->getYear()) {
//			return true;
//		}
//		else if (this->getMonth() == temp->getMonth()) {
//			if (this->getDay() <= temp->getMonth()) {
//				return true;
//			}
//			else {
//				return false;
//			}
//		}
//		else {
//			return false;
//		}
//	}
//	else {
//		return false;
//	}
//}