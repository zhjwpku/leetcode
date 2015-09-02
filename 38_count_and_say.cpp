#include <iostream>

using namespace std;

string getNext(string s) {
	string res = "";
	int beg = 0;
	int end = 0;
	char tmp = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == tmp) {
			end++;
		} else {
			res += (end - beg + 1) + '0';
			res += tmp;
			beg = i;
			end = i;
			tmp = s[i];
		}
	}

	res += (end - beg + 1) + '0';
	res += tmp;

	return res;
}

int main() {
	string s = "1";
	int n = 10;
	while (n--) {
		s = getNext(s);
		cout << s << endl;
	}

	return 0;
}
