#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
	int n = haystack.size();
	int m = needle.size();

	if (m == 0)
		return 0;

	if (n == 0)
		return -1;

	for (int i = 0; ; i++) {
		for (int j = 0; ; j++) {
			if (j == m) return i;
			if (i + j == n) return -1;
			if (haystack[i + j] != needle[j])
				break;
		}
	}
}

// KMP algo
static void compute_prefix(string needle, vector<int> &next) {
	int j = -1;
	const int m = needle.size();

	next[0] = j;

	for (int i = 1; i < m; i++) {
		while (j > -1 && needle[j + 1] != needle[i]) j = next[j];

		if (needle[i] == needle[j + 1]) j++;
		next[i] = j;
	}
}

static int kmp(string haystack, string needle) {
	int i;
	int j = -1;
	int n = haystack.size();
	int m = needle.size();

	if (n == 0 && m == 0) return 0;

	if (m == 0) return 0;

	vector<int> next;
	next.reserve(m);

	compute_prefix(needle, next);

	for (int i = 0; i < n; i++) {
		while (j > -1 && needle[j + 1] != haystack[i]) j = next[j];

		if (haystack[i] == needle[j + 1]) j++;
		if (j == m - 1)
			return i - j;
	}

	return -1;
}

int strStr_kmp(string haystack, string needle) {
	return kmp(haystack, needle);
}
