#pragma once
/* Needs to overload the following operators:
 * ==, =<, =>, =!,  <, >
 */

class IComparable {
private:


public:
	virtual bool operator <= (const IComparable& other) const = 0;

};