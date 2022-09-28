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
	BigInteger() : digits(0) {

	}
	BigInteger(long long n);
	BigInteger(std::string s);
	BigInteger(std::vector<int>& digits);
    const BigInteger operator +() const;
	const BigInteger operator -() const;
	friend bool operator ==  (const BigInteger& left, const BigInteger& right);
	friend bool operator !=  (const BigInteger& left, const BigInteger& right);
	friend bool operator <  (const BigInteger& left, const BigInteger& right);
	friend bool operator <=  (const BigInteger& left, const BigInteger& right);
	friend bool operator >  (const BigInteger& left, const BigInteger& right);
	friend bool operator >=  (const BigInteger& left, const BigInteger& right);
	friend BigInteger operator + (const BigInteger& left, const BigInteger& right);
	friend BigInteger operator - (const BigInteger& left, const BigInteger& right);
	friend BigInteger operator * (const BigInteger& left, const BigInteger& right);
	void print();

	BigInteger& operator+=(const BigInteger& other);
	BigInteger& operator-=(const BigInteger& other);
	BigInteger& operator*=(const BigInteger& other);
	 

};


#endif
