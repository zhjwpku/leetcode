#include <iostream>
bool isMatch(string s, string p) {
	if (p.empty()) return s.empty();

	if (p[1] != '*') {
		if (s[0] == p[0] || (p[0] == '0' && s[0] != '\0'))
			return isMatch(s.substr(1), p.substr(1));
		else return false;
	} else {
		if (isMatch(s, p.substr(2)))
			return true;
		int index = 0;
		while (index < s.size() && (s[index] == p[0] || p[0] == '.')) {
			if (isMatch(s.substr(++index), p.substr(2)))
				return true;
		}

		return false;
	}
}
