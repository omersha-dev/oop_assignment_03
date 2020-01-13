#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
using namespace std;

class Date : virtual public IPrintable {

private:
	int day, month, year;

public:
	void setDay(int d);
	int getDay() const;
	void setMonth(int m);
	int getMonth() const;
	void setYear(int y);
	int getYear() const;

	Date(int d, int m, int y);
	void operator=  (const Date& other);

	virtual void toOs(ostream& output) const;

	bool isLeapYear(int yearToCheck) const;

	virtual bool operator <= (const IComparable& other) const {
		const Date* temp = dynamic_cast<const Date*>(&other);
		if (this->getYear() < temp->getYear()) {
			return true;
		}
		else if (this->getYear() == temp->getYear()) {
			if (this->getMonth() < temp->getYear()) {
				return true;
			}
			else if (this->getMonth() == temp->getMonth()) {
				if (this->getDay() <= temp->getMonth()) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};