#pragma once
/* Needs to overload the following operators:
 * ==, =<, =>, =!,  <, >
 */

template <class T>
class IComparable {
private:


public:
	virtual bool operator <= (const IComparable& other) const = 0;
	virtual bool operator == (const IComparable& other) const = 0;
	virtual bool operator >= (const IComparable& other) const = 0;
	virtual bool operator != (const IComparable& other) const = 0;
	virtual bool operator < (const IComparable& other) const = 0;
	virtual bool operator > (const IComparable& other) const = 0;

};