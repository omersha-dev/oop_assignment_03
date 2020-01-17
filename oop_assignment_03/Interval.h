#pragma once
/*
דיסטרקטור 
אורפטור ||
הדפסה
ולהריץ הכל
*/

template <class T>
class Interval
{
private:
	T low;
	T high;

public:
	Interval<T>(T first, T second);
	void setLow(T first);
	void setHigh(T Second);
	T getLow() const;
	T getHigh() const;

	bool isEmpty() const;
	bool isBefore(const Interval<T> &other)const;
	bool isAfter(const Interval<T> &other)const;
	bool intersects(const Interval<T> &other)const;
	bool contains(const T &other)const;

	bool checkInter(const Interval<T> other);
	Interval<T>* operator && (const Interval<T> &other);
	Interval<T>* operator || (const Interval<T> &other);
};


