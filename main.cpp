#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"




int main() {
	BigInteger n(988);
	BigInteger m("988");
	BigInteger s = n - m;
	
	s.print();
	
	return 0;
}