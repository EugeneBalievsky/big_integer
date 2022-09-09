#include "BigInteger.h"
#include <iostream>
#include <vector>
#include <string>

BigInteger::BigInteger(long long n) {
	(n < 0 ? this->is_negative = true : this->is_negative = false);
	
	while (abs(n) > 0) {
		digits.push_back(abs(n) % 10);
		n /= 10;
	}
}

 
BigInteger::BigInteger(std::string s) {
	(s[0] == '-' ? this->is_negative = true : this->is_negative = false);
		
	for (int i = s.size()-1; i >= 0; --i) {
		
		digits.push_back(s[i] - '0');
	}
}

BigInteger::BigInteger(std::vector<int>& digits) {
	this->digits = digits;
}

void BigInteger::print() {
	if (is_negative) {
		std::cout << '-';
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		std::cout << digits[i];
	}
}

BigInteger BigInteger::add(BigInteger other) {
	std::vector<int> result;
	int size = std::max(digits.size(), other.digits.size());
	int carry = 0;
	for (int i = 0; i < size; ++i) {
		int cur = carry;

		if (i < digits.size()) {
			cur += digits[i];
		}
		if (i < other.digits.size()) {
			cur += other.digits[i];
		}
		result.push_back(cur % 10);
		carry = (cur >= 10);
	}

	if (carry == 1) {
		result.push_back(1);
	}

	return BigInteger(result);
}

BigInteger BigInteger::subtr(BigInteger other) {
	std::vector<int> result;
	int size = std::max(digits.size(), other.digits.size());
	int carry = 0;
	for (int i = 0; i < size; ++i) {
		int cur = carry;

		if (i < digits.size()) {
			cur += digits[i];
		}
		if (i < other.digits.size()) {
			cur -= other.digits[i];
		}
		result.push_back((10 + cur) % 10);
		carry = -(cur < 0);
	}

	return BigInteger(result);
}

BigInteger BigInteger::summ(BigInteger a, BigInteger b) {
	
	if (!a.is_negative && !b.is_negative) {
		return a.add(b);
	}

}

