#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"




int main() {
	BigInteger n(989);
	BigInteger m("-988");
	BigInteger s = n + m;
	
	n.print();
	m.print();
	s.print();
	
	return 0;
}