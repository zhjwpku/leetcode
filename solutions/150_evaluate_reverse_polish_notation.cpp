#include <stack>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int evalRPN(vector<string> &tokens) {
	int res;
	stack<int> stk;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+" || tokens[i] == "-" ||
		    tokens[i] == "*" || tokens[i] == "/") {
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			if (tokens[i] == "+")
				res = a + b;
			else if (tokens[i] == "-")
				res = a - b;
			else if (tokens[i] == "*")
				res = a * b;
			else if (tokens[i] == "/")
				res = a / b;
			stk.push(res);
		} else {
			int tmp = atoi(tokens[i].c_str());
			stk.push(tmp);
		}
	}

	return stk.top();
}
