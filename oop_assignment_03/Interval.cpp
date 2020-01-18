#include <iostream>
#include "Interval.h"

using namespace std;

template <class T>
Interval<T>::Interval(T first, T second)
{
	this->low = first;
	this->high = second;
}
template<class T>
void Interval<T>::setLow(T first) { this->low = first; }
template<class T>
void Interval<T>::setHigh(T Second) { this->high = Second; }

template<class T>
T Interval<T>::getLow() const { return low; }
template<class T>
T Interval<T>::getHigh() const { return high; }

template<class T>
bool Interval<T>::isEmpty() const
{
	if (this->low == this->high)
		return true;
}

template<class T>
bool Interval<T>::isBefore(const Interval<T> &other) const
{
	if (this->high < other.getLow())
		return true;
	return false;
}

template<class T>
bool Interval<T>::isAfter(const Interval<T> &other) const
{
	if (this->getlow() > other.getHigh())
		return true;
	return false;
}

template<class T>
bool Interval<T>::intersects(const Interval<T> &other) const
{
	if (this->checkInter(other) || other.checkInter(this))	return true;

	return false;
}

template<class T>
bool Interval<T>::contains(const T &other) const
{
	if ((this->getLow() < other) && (this->getHigh() > other))
	{
		return true;
	}
	return false;
}

template<class T>
Interval<T>* Interval<T>::operator&&(const Interval<T>& other)
{
	Interval<T> summery = new Interval<T>;
	T min, max;
	if (this->intersects(other))
	{
		if (this->getLow() > other->getLow())
			min = this->getLow();
		else
			min = other.getLow();
		if (this->getHigh() < other->getHigh())
			max = this->getHigh();
		else
			max = other.getHigh();
		summery.setLow(min);
		summery.setHigh(max);
		return summery;
	}
	return summery;
}

template<class T>
Interval<T>* Interval<T>::operator||(const Interval<T>& other)
{
	Interval<T> summery = new Interval<T>;
	T min, max;
	if (!this->intersects(other))
	{
		if (this->getLow() > other->getLow())
			min = other->getLow();
		else
			min = this.getLow();
		if (this->getHigh() < other->getHigh())
			max = other->getHigh();
		else
			max = this.getHigh();
		summery.setLow(min);
		summery.setHigh(max);
		return summery;
	}
	return summery;
}

template<class T>
bool Interval<T>::checkInter(const Interval<T> other)
{
	if (this->isAfter(other) || this->isBefore(other)) { return false; }

	if (this->getLow() <= other.getLow() && this->getHigh() <= other->getHigh()) { return true; }

	if (this->getLow() <= other.getLow() && this->getHigh() <= other->getHigh()) { return true; }

	if (this->getLow() >= other.getLow() && this->getHigh() >= other->getHigh()) { return true; }
}

template<class T>
std::ostream& operator<<(std::ostream& output, const Interval<T>& other)
{
	string str = "";
	if (other.getLow() == 0 && other.getHigh() == 0)
	{
		str = "Invalid interval";
	}
	else
	{
		str = "(" + other.getLow() + "," + other.getHigh() + ")";
	}
	output << str;
	return output;
}

//template<class T>
//Interval<T>::~Interval()
//{}
