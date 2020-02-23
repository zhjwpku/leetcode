#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<char> stk;

	for (auto c : s) {
		if (c == '(' || c == '[' || c == '{')
			stk.push(c);
		else {
			if (stk.empty())
				return false;
			char tmp = stk.top();
			if (c == ')' && tmp == '(' ||
				c == ']' && tmp == '[' ||
				c == '}' && tmp == '{')
				stk.pop();
			else
				return false;
		}
	}

	return stk.empty();
}
