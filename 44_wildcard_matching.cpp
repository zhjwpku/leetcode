#include <iostream>
#include <vector>

bool isMatch(string s, string p) {
	int slen = s.size(), plen = p.size();
	int i, j, iStar = -1, jStar = -1;

	for (i = 0, j = 0; i < slen; ++i, ++j) {
		if (p[j] == '*') {
			iStar = i;
			jStar = j;
			--i;
		} else {
			if (p[j] != s[i] && p[j] != '?') {
				if (iStar >= 0) {
					i = iStar++;
					j = jStar;
				} else
					return false;
			}
		}
	}

	while (p[j] == '*') j++;

	return j == plen;
}
