#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
using namespace std;


class Date : public IPrintable<Date>, public IComparable<Date> {

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
	virtual void toIs(istream& input);

	bool isLeapYear(int d, int m, int y) const;

	string isValidDate(int d, int m, int y) const;
	string isValidDate(Date& dateToCheck) const;

	virtual bool operator <= (const IComparable<Date> & other) const;
	virtual bool operator == (const IComparable<Date> & other) const;
	virtual bool operator >= (const IComparable<Date> & other) const;
	virtual bool operator != (const IComparable<Date> & other) const;
	virtual bool operator < (const IComparable<Date> & other) const;
	virtual bool operator > (const IComparable<Date> & other) const;

};