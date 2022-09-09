#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"




int main() {
	BigInteger n(102);
	BigInteger m("98");
	BigInteger sum = n.subtr(m);
	sum.print();

	return 0;
}