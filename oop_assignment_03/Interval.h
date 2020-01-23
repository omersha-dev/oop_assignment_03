#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Interval
{
private:
	T low;
	T high;

public:
	Interval() {
		this->setLow(0);
		this->setHigh(0);
	}
	Interval(T first, T second) {
		this->setLow(first);
		this->setHigh(second);
	}

	void setLow(T first) { this->low = first; }
	void setHigh(T second) { this->high = second; }
	T getLow() const { return low; }
	T getHigh() const { return high; }

	bool isEmpty() const
	{
		if (this->low == this->high)
			return true;
	}

	bool isBefore(const Interval<T> &other)const
	{
		if (this->high < other.getLow())
			return true;
		return false;
	}

	bool isAfter(const Interval<T> &other)const
	{
		if (this->getLow() > other.getHigh())
			return true;
		return false;
	}
	bool intersects(const Interval<T> &other)const
	{
		if (this->checkInter(other) || other.checkInter(*this))	return true;

		return false;
	}
	bool contains(const T &other)const
	{
		if ((this->getLow() < other) && (this->getHigh() > other))
		{
			return true;
		}
		return false;
	}

	bool checkInter(const Interval<T> other) const
	{
		/*if (this->checkInter(other) || other.checkInter(*this))
		{
			return true;
		}*/

		return false;
	}

	Interval<T>* operator && (const Interval<T> &other)
	{
		Interval<T> *summery = new Interval<T>;
		T min, max;
		if (this->intersects(other))
		{
			if (this->getLow() > other.getLow())
				min = this->getLow();
			else
				min = other.getLow();
			if (this->getHigh() < other.getHigh())
				max = this->getHigh();
			else
				max = other.getHigh();
			summery->setLow(min);
			summery->setHigh(max);
			return summery;
		}
		return summery;
	}
	Interval<T> operator || (const Interval<T> other)
	{
		return other;
	}

	friend ostream& operator<<(ostream& output, const Interval<T> other)
	{
		string str = "";
		if (other.getLow() == 0 && other.getHigh() == 0)
		{
			str = "Invalid interval";
		}
		else
		{
			str = "(" + to_string(other.getLow()) + "," + to_string(other.getHigh()) + ")";
		}
		output << str;
		return output;
	}

	~Interval() {}
};

//template<class T>
//void Interval<T>::setLow(T first) { this->low = first; }
//template<class T>
//void Interval<T>::setHigh(T second) { this->high = second; }
//
//template<class T>
//T Interval<T>::getLow() const { return low; }
//template<class T>
//T Interval<T>::getHigh() const { return high; }
//
//template<class T>
//bool Interval<T>::isEmpty() const
//{
//	if (this->low == this->high)
//		return true;
//}
//
//template<class T>
//inline bool Interval<T>::isBefore(const Interval<T> &other) const
//{
//	if (this->high < other.getLow())
//		return true;
//	return false;
//}
//
//template<class T>
//inline bool Interval<T>::isAfter(const Interval<T> &other) const
//{
//	if (this->getLow() > other.getHigh())
//		return true;
//	return false;
//}
//
//template<class T>
//inline bool Interval<T>::intersects(const Interval<T> &other) const
//{
//	if (this->checkInter(other) || other.checkInter(*this))	return true;
//
//	return false;
//}
//
//template<class T>
//inline bool Interval<T>::contains(const T &other) const
//{
//	if ((this->getLow() < other) && (this->getHigh() > other))
//	{
//		return true;
//	}
//	return false;
//}
//
//template<class T>
//inline Interval<T>* Interval<T>::operator&&(const Interval<T>& other)
//{
//	Interval<T> *summery = new Interval<T>;
//	T min, max;
//	if (this->intersects(other))
//	{
//		if (this->getLow() > other.getLow())
//			min = this->getLow();
//		else
//			min = other.getLow();
//		if (this->getHigh() < other.getHigh())
//			max = this->getHigh();
//		else
//			max = other.getHigh();
//		summery->setLow(min);
//		summery->setHigh(max);
//		return summery;
//	}
//	return summery;
//}
//
//template<class T>
//inline Interval<T>* Interval<T>::operator||(const Interval<T>& other)
//{
//	Interval<T> *summery = new Interval<T>;
//	T min, max;
//	if (!this->intersects(other))
//	{
//		if (this->getLow() > other.getLow())
//			min = other.getLow();
//		else
//			min = this->getLow();
//		if (this->getHigh() < other.getHigh())
//			max = other.getHigh();
//		else
//			max = this->getHigh();
//		summery->setLow(min);
//		summery->setHigh(max);
//		return summery;
//	}
//	return summery;
//}
//
//template<class T>
//inline bool Interval<T>::checkInter(const Interval<T> other) const
//{
//	if (this->isAfter(other) || this->isBefore(other)) { return false; }
//
//	if (this->getLow() <= other.getLow() && this->getHigh() <= other.getHigh()) { return true; }
//
//	if (this->getLow() <= other.getLow() && this->getHigh() <= other.getHigh()) { return true; }
//
//	if (this->getLow() >= other.getLow() && this->getHigh() >= other.getHigh()) { return true; }
//
//	return false;
//}
// 
//template<class T>
//inline std::ostream& operator<<(std::ostream& output, const Interval<T>& other)
//{
//	string str = "";
//	if (other.getLow() == 0 && other.getHigh() == 0)
//	{
//		str = "Invalid interval";
//	}
//	else
//	{
//		str = "(" + other.getLow() + "," + other.getHigh() + ")";
//	}
//	output << str;
//	return output;
//}
//
//template<class T>
//inline Interval<T>::~Interval() {}