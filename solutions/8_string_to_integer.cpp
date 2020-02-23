#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
	int num = 0;
	int sign = 1;
	int n = str.size();
	int i = 0;

	while (str[i] == ' ' && i < n) i++;

	if ((str[i] == '+' && str[i+1] == '-') ||
		str[i] == '-' && str[i+1] == '+')
		return 0;

	if (str[i] == '+') i++;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}

	for (; i < n; i++) {
		if (str[i] > '9' || str[i] < '0')
			break;
		if (num > INT_MAX / 10 ||
			(num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
			return sign == -1 ? INT_MIN : INT_MAX;
		}

		num = num * 10 + (str[i] - '0');
	}

	return num * sign;
}

int main() {
	string abc;
	while (cin >> abc) {
		cout << myAtoi(abc) << endl;
	}
	return 0;
}
