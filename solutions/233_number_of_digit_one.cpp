#include <iostream>
#include <vector>

using namespace std;

int countDigitOne(int n) {
	if (n < 1) return 0;
	if (n >=1 && n < 10) return 1;

	int y = 1, x = n;

	while (x >= 10) {
		x/=10;
		y*=10;
	}

	if (x == 1)
		return n-y+1 + countDigitOne(y-1) + countDigitOne(n%y);
	else
		return y + x*countDigitOne(y-1) + countDigitOne(n%y);
}
