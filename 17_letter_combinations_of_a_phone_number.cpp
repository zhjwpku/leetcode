#include <iostream>
#include <vector>
using namespace std;

const vector<string> keyboard{" ", "", "abc", "def", "ghi",
				"jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(const string &digits, size_t cur, string path, vector<string> &res) {
	if (cur == digits.size()) {
		res.push_back(path);
		return;
	}

	for (auto c: keyboard[digits[cur] - '0']) {
		dfs(digits, cur+1, path+c, res);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	if (digits.size() == 0) return res;
	dfs(digits, 0, "", res);
	return res;
}
