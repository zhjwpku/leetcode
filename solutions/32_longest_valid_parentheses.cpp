#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* wrong method */
int longestValidParentheses_wrong(string s) {
	int len = 0;
	int max_len = 0;
	stack<char> stk;

	for (auto c : s) {
		if (c == '(' || c == '[' || c == '{')
			stk.push(c);
		else {
			if (stk.empty()) {
				stk.push(c);
				continue;
			} else {
				char tmp = stk.top();
				cout << "len:" << len << "top():" << tmp << "c:" << c << endl;
				if (c == ')' && tmp == '(' ||
					c == ']' && tmp == '[' ||
					c == '}' && tmp == '{') {
					stk.pop();
					len += 2;
				} else {
					stk.push(c);
					max_len = max_len > len ? max_len : len;
					len = 0;
				}
			}
		}
	}

	return max_len > len ? max_len : len;
}

// use stack
int longestValidParentheses(string s) {
	int max_len = 0, last = -1;
	stack<int> lefts;	// keep track of the positions of non-matching '('s

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			lefts.push(i);
		} else {
			if (lefts.empty()) {
				last = i;
			} else {
				lefts.pop();
				if (lefts.empty()) {
					max_len = max(max_len, i - last);
				} else {
					max_len = max(max_len, i - lefts.top());
				}
			}
		}
	}
	return max_len;
}

// Dynamic programming
int longestValidParentheses_withDP(string) {
	vector<int> f(s.size(), 0);
	int ret = 0;

	for (int i = s.size() - 2; i >=0; i--) {
		int match = i + f[i+1] + 1;

		if (s[i] == '(' && match < s.size() && s[match] == ')') {
			f[i] = f[i+1] + 2;

			if (match + 1 < s.size())
				f[i] += f[match + 1];
		}

		ret = max(ret, f[i]);
	}

	return ret;
}


int main() {
	string s;
	while (getline(cin, s)) {
		cout << longestValidParentheses(s) << endl;
	}

	return 0;
}
