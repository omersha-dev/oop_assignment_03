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
	bool valid;
	string Problem;

public:
	Interval() {
		this->setLow(0);
		this->setHigh(0);
		valid = false;
		Problem = "EMPTY";
	}
	Interval(T first, T second) {
		this->setLow(first);
		this->setHigh(second);
		if (first > second)
		{
			valid = false;
			Problem = "Invalid interval";
		}

	}

	void setLow(T first) { this->low = first; }
	void setHigh(T second) { this->high = second; }
	void setValid(bool updateValid) { this->valid = updateValid; }
	void setProblem(string updateProblem) { this->Problem = updateProblem; }
	T getLow() const { return low; }
	T getHigh() const { return high; }
	bool isValid() const { return valid; }
	string getProblem() const { return Problem; }

	bool isEmpty() const
	{
		if (this->low == this->high)
			return true;
	}

	bool isBefore(const Interval<T> &other)const
	{
		if (this->high <= other.getLow())
			return true;
		return false;
	}

	bool isAfter(const Interval<T> &other)const
	{
		if (this->getLow() >= other.getHigh())
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
		if (this->isAfter(other) || this->isBefore(other)) { return false; }

		if (this->getLow() <= other.getLow() && this->getHigh() <= other.getHigh()) { return true; }

		if (this->getLow() <= other.getLow() && this->getHigh() <= other.getHigh()) { return true; }

		if (this->getLow() >= other.getLow() && this->getHigh() >= other.getHigh()) { return true; }

		return false;
	}

	Interval<T> operator && (const Interval<T> &other)
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
			summery->setValid(true);
			return *summery;
		}
		else
		{
			summery->setProblem("EMPTY");
			summery->setValid(false);
		}
		return *summery;
	}
	Interval<T> operator || (const Interval<T> other)
	{
		Interval<T> *summery = new Interval<T>;
		T min, max;
		if (this->intersects(other))
		{
			if (this->getLow() > other.getLow())
				min = other.getLow();
			else
				min = this->getLow();
			if (this->getHigh() < other.getHigh())
				max = other.getHigh();
			else
				max = this->getHigh();
			summery->setLow(min);
			summery->setHigh(max);
			summery->setValid(true);
			return *summery;
		}
		else
		{
			summery->setProblem("Invalid interval");
			summery->setValid(false);
		}
		return *summery;
	}

	friend ostream& operator<<(ostream& output, const Interval<T> other)
	{
		string str = "";
		if (other.isValid())
		{
			str = "(" + to_string(other.getLow()) + "," + to_string(other.getHigh()) + ")";
		}
		else
		{
			str = other.getProblem();
		}
		output << str;
		return output;
	}

	~Interval() {}
};