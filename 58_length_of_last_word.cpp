#include <iostream>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
	if (s.empty()) return 0;

	int len = 0;
	int i = s.size() - 1;
	while(i >= 0 && isspace(s[i])) {
		if (i == 0)
			return 0;
		i--;
	}

	while (i >= 0 && !isspace(s[i]) ) {
		len++;
		if (i == 0)
			return len;
		i--;
	}

	return len;
}

int main()
{
	string s;
	while (getline(cin, s)) {
		cout << lengthOfLastWord(s) << endl;
	}

	return 0;
}
