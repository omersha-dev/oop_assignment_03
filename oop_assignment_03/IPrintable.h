#pragma once
template <class T>
class IPrintable {
private:


public:
	virtual void ostream& << (ostream& output, const T &other) = 0;
	virtual void istream& >> (istream& input, T &other) = 0;

};