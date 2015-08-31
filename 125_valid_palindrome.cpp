#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	if (s.size() == 0)
		return true;
	transform(s.begin(), s.end(), s.begin::tolower);
	auto left = s.begin(), right = prev(s.end());

	while (left < right) {
		if (!::isalnum(*left))
			++left;
		else if (!::isalnum(*right))
			--right;
		else if (*left != *right)
			return false;
		else {
			++left;
			--right;
		}
	}

	return true;
}
