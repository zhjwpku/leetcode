#include <iostream>

bool isBadVersion(int version);

int firstBadVersion(int l, int r) {
	while (l < r) {
		int m = l + (r - l) / 2;
		if (isBadVersion(m))
			r = m;
		else
			l = m+1;
	}

	return l;
}

int firstBadVersion(int n) {
	return firstBadVersion(1, n);
}
