#pragma once
template <class T>
class IComparable {
private:


public:
	virtual bool operator!= (const T &other) = 0;

};