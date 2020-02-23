#include <iostream>

void getBs(string &s, int &i) {
	while (i < s.size() && s[i] == ' ')
		i++;
}

void getSign(string &s, int &i) {
	if (i < s.size() && (s[i] == '+' || s[i] == '-'))
		i++;
}

bool getDigit(string &s, int &i) {
	int j = i;
	while (i < s.size() && isdigit(s[i]))
		i++;

	return (i != j);
}

bool getDot(string &s, int &i) {
	int j = i;
	if (i < s.size() && s[i] == '.')
		i++;
	return (i != j);
}

bool getE(string &s, int &i) {
	int j = i;
	if (i < s.size() && (s[i] == 'E' || s[i] == 'e'))
		i++;

	return (i != j);
}

bool isNumber(string s) {
	int i = 0;
	bool integer = false, decimal = false;
	getBs(s, i);
	getSign(s, i);

	if (getDigit(s, i)) {
		integer = true;
	}

	if (getDot(s, i)) {
		if (getDigit(s, i))
			decimal = true;
	}

	if (getE(s, i)) {
		getSign(s, i);
		if (!getDigit(s, i)) return false;
	}

	getBs(s, i);

	if (i != s.size()) return false;

	if (integer == false && decimal == false) return false;

	return true;
}
