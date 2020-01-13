#pragma once
#include <iostream>
using namespace std;

class IPrintable {
private:


public:
	
	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<< (ostream& output, const IPrintable& toPrint) {
		toPrint.toOs(output);
		return output;
	}

};