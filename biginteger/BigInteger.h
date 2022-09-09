#ifndef _BIGINTEGER_H
#define _BIGINTEGER_H

#include <vector>
#include <iostream>
#include <string>

class BigInteger {
private:
	std::vector<int> digits;
	bool is_negative;


public:
	BigInteger(long long n);
	BigInteger(std::string s);
	BigInteger(std::vector<int>& digits);
	BigInteger add(BigInteger other);
	BigInteger subtr(BigInteger other);
	BigInteger summ(BigInteger other);
	void print();



};


#endif
