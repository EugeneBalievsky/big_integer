#include "BigInteger.h"
#include <iostream>
#include <vector>
#include <string>

BigInteger::BigInteger(long long n) {
	
	if (n < 0) {
		this->is_negative = true;
		n = -n;
	}
	else {
		this->is_negative = false;	
	}
	
	while (n != 0) {
		digits.push_back(n % 10);
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

bool operator <  (const BigInteger& left, const BigInteger& right) {
	if (left == right) {
		return false;
	}
	if (left.is_negative) {
		if (right.is_negative) {
			return ((-right) < (-left));
		}
		else {
			return true;
		}
	}
	else if (right.is_negative) {
		return false;
	}
	else {
		if (left.digits.size() != right.digits.size()) {
			return left.digits.size() < right.digits.size();
		}
		else {
			for (int i = left.digits.size() - 1; i >= 0; --i) {
				if (left.digits[i] != right.digits[i]) {
					return left.digits[i] < right.digits[i];
				}
			}
			return false;
		}
	}
}

bool operator <=  (const BigInteger& left, const BigInteger& right) {
	return (left == right || left < right);
}

bool operator >  (const BigInteger& left, const BigInteger& right) {
	return !(left <= right);
}

bool operator >=  (const BigInteger& left, const BigInteger& right) {
	return !(left < right);
}

void BigInteger::print() {
	if (is_negative) {
		std::cout << '-';
	}
	for (int i = digits.size() - 1; i >= 0; --i) {
		std::cout << digits[i];
	}
	std::cout << "\n";
}

const BigInteger BigInteger::operator +() const  {
	return BigInteger(*this);
}

const BigInteger BigInteger::operator -() const {
	BigInteger copy(*this);
	copy.is_negative = !copy.is_negative;
	return copy;
}

 
BigInteger operator + (const BigInteger& left, const BigInteger& right) {
	if (left.is_negative) {
		if (right.is_negative) {
			return -(-left + (-right));
		}
		else {
			return right - (-left);
		}
		
	}
	else if (right.is_negative) {
		return left - (-right);
	}
	BigInteger result;
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
		result.digits.push_back(cur % 10);
		carry = (cur >= 10);
	}

	if (carry == 1) {
		result.digits.push_back(1);
	}
	return result;
}
 
BigInteger operator - (const BigInteger& left, const BigInteger& right) {
	if (right.is_negative) {
		return left + (-right);
	}
	else if (left.is_negative) {
		return -(-left + right);
	}
	else if (left < right) {
		return -(right - left);
	}
	BigInteger result;
	int size = left.digits.size();
	int carry = 0;
	for (int i = 0; i < size; ++i) {
		int cur = carry;

		if (i < left.digits.size()) {
			cur += left.digits[i];
		}
		if (i < right.digits.size()) {
			cur -= right.digits[i];
		}
		result.digits.push_back((10 + cur) % 10);
		carry = -(cur < 0);
	}
	return result;
}
BigInteger operator * (const BigInteger& left, const BigInteger& right) {
	BigInteger result;
	result.digits.resize(left.digits.size() + right.digits.size());
	for (int i = 0; i < left.digits.size(); ++i) {
		int carry = 0;
		for (int j = 0; j < right.digits.size() || carry != 0; ++j) {
			long long cur = result.digits[i + j] + 
				left.digits[i] * (j < right.digits.size() ? right.digits[j] : 0) + carry;
			result.digits[i + j] = cur % 10;
			carry = cur / 10;
		}
	}
	(left.is_negative != right.is_negative ? result.is_negative = true : result.is_negative = false);
	return result;
}

BigInteger& BigInteger::operator+=(const BigInteger& other) {
	*this = *this + other;
	return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& other) {
	*this = *this - other;
	return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& other) {
	*this = *this * other;
	return *this;
}

