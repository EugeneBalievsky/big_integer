#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"




int main() {
	BigInteger n(-988);
	BigInteger m("222");
	BigInteger s = n + m;
	BigInteger l = n * m;

	
	n.print();
	m.print();
	s.print();
	l.print();

	n += m;
	n.print();
	n -= m;
	n.print();
	n *= m;
	n.print();
	
	return 0;
}