#pragma once

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
};


