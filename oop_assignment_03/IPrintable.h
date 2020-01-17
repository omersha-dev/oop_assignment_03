#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class IPrintable {
private:


public:
	
	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<< (ostream& output, const IPrintable& toPrint) {
		toPrint.toOs(output);
		return output;
	}

	/*virtual void toIs() = 0;
	friend istream& operator>> (istream& input, IPrintable& toSet) {
		input >> str;
		toIS();
		return input;
	}*/

};