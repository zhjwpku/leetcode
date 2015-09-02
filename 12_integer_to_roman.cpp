#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num) {
	const int radix[] = {1000, 900, 500, 400, 100, 90, 50,
				40, 10, 9, 5, 4, 1};
	const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L",
				"XL", "X", "IX", "V", "IV", "I"};

	string roman = "";

	for (size_t i = 0; num > 0; i++) {
		int count = num / radix[i];
		num %= radix[i];
		while (count--)
			roman += symbol[i];
	}

	return roman;
}

int main()
{
	int a;
	while (cin >> a)
		cout << intToRoman(a) << endl;

	return 0;
}
