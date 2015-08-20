#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int c = 1;
	for (int i = digits.size()-1; i >=0; i--) {
		int tmp = digits[i] + c;
		digits[i] = tmp % 10;
		c = tmp / 10;
		if (!c)
			break;
	}

	if (c == 1) {
		digits[0] = 1;
		digits.push_back(0);
	}

	return digits;
}
