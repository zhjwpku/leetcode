#include <iostream>
#include <vector>

using namespace std;

bool TLE_canWinNim(int n) {
	bool a = true;
	bool b = true;
	bool c = true;

	for (int i = 3; i < n; i++) {
		if (a && b && c) {
			a = b;
			b = c;
			c = false;
		} else {
			a = b;
			b = c;
			c = true;
		}
	}

	return c;
}

bool canWinNim(int n) {
	return n % 4;
}
