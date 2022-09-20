#include "BigInteger.h"
#include <iostream>
#include <vector>
#include <string>

BigInteger::BigInteger(long long n) {
	
	if (n < 0) {
		this->is_negative = true;
	}
	else {
		this->is_negative = false;	
	}
	
	while (abs(n) >0) {
		digits.push_back(abs(n) % 10);
		n /= 10;
	}
}

 
BigInteger::BigInteger(std::string s) {
	int a = 0;
	if (s[0] == '-') {
		this->is_negative = true;
		a = 1;
	}
	else {
		this->is_negative = false;
	}
		
	for (int i = s.size()-1; i >= a; --i) {
		
		digits.push_back(s[i] - '0');
	}
}

BigInteger::BigInteger(std::vector<int>& digits) {
	this->digits = digits;
}

bool operator ==  (const BigInteger& left, const BigInteger& right) {
	if (left.is_negative != right.is_negative) {
		return false;
	}
	if (left.digits.size() != right.digits.size()) {
		return false;
	}
	for (int i = 0; i < left.digits.size(); ++i) {
		if (left.digits[i] != right.digits[i]) {
			return false;
		}
	}
	return true;
}
bool operator !=  (const BigInteger& left, const BigInteger& right) {
	return !(left == right);
}
void BigInteger::print() {
	if (is_negative) {
		std::cout << '-';
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		std::cout << digits[i];
	}
}
const BigInteger operator - (const BigInteger& i) {
	return i.is_negative;
}
 
BigInteger operator + (const BigInteger& left, const BigInteger& right) {
	if (left.is_negative) {
		if (right.is_negative) {
			return -(-left + (-right));
		}
	}
	std::vector<int> result;
	int size = std::max(left.digits.size(), right.digits.size());
	int carry = 0;
	for (int i = 0; i < size; ++i) {
		int cur = carry;

		if (i < left.digits.size()) {
			cur += left.digits[i];
		}
		if (i < right.digits.size()) {
			cur += right.digits[i];
		}
		result.push_back(cur % 10);
		carry = (cur >= 10);
	}

	if (carry == 1) {
		result.push_back(1);
	}

	return BigInteger(result);
}
 
BigInteger operator - (BigInteger left, BigInteger right) {
	std::vector<int> result;
	int size = std::max(left.digits.size(), right.digits.size());
	int carry = 0;
	for (int i = 0; i < size; ++i) {
		int cur = carry;

		if (i < left.digits.size()) {
			cur += left.digits[i];
		}
		if (i < right.digits.size()) {
			cur -= right.digits[i];
		}
		result.push_back((10 + cur) % 10);
		carry = -(cur < 0);
	}

	return BigInteger(result);
}





