#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string str) {
	unordered_map<string, char> mymap;
	unordered_map<char, bool> charmap;
	vector<string> words;
	string tmp = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			if (tmp != "")
				words.push_back(tmp);
			tmp = "";
		} else {
			tmp += str[i];
		}
	}

	if (tmp != "")
		words.push_back(tmp);

	string pp = "";
	if (pattern.size() != words.size()) return false;

	for (int i = 0; i < words.size(); i++) {
		if (mymap.find(words[i]) == mymap.end()) {

			if (charmap.find(pattern[i]) == charmap.end()) {
				pp += pattern[i];
				mymap[words[i]] = pattern[i];
				charmap[pattern[i]] = true;
			} else {
				return false;
			}

		} else {
			pp += mymap[words[i]];
		}
	}

	if (pp == pattern)
		return true;
	return false;
}

int main() {
	string pattern;
	string str;
	while (cin >> pattern) {
		getline(cin, str);
		cout << wordPattern(pattern, str) << endl;
	}

	return 0;
}
