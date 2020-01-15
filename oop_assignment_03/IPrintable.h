#pragma once
#include <iostream>
#include <string>
using namespace std;

class IPrintable {
private:


public:
	
	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<< (ostream& output, const IPrintable& toPrint) {
		toPrint.toOs(output);
		return output;
	}

	virtual void toIs(string is, IPrintable& other);
	friend istream& operator>> (istream& input, IPrintable& toSet) {
		string str;
		input >> str;
		toIS(str, toSet);
		return input;
	}

};