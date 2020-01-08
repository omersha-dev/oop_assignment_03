#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
using namespace std;

class Date : virtual public IComparable<Date>, virtual public IPrintable<Date> {

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
	void std::ostream& << (ostream& output, const Date toPrint) override;
	//	bool operator!= (const Date& other) override;
	//	bool operator!=(Date & other);

};