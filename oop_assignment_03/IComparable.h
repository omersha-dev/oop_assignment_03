#pragma once

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