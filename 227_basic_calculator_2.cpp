#include <iostream>
#include <stack>
using namespace std;

int calculate(string s) {
	int num = 0;
	int sig = 1;
	int pre;
	int flag = 0;
	stack<int> nums;

	for (char c : s) {
		if (c == ' ') continue;
		if (isdigit(c)) {
			num = num * 10 + c - '0';
		} else {
			num = num * sig;
			sig = 1;

			if (flag == 1) { // *
				pre = nums.top();
				nums.pop();
				num = pre * num;
				nums.push(num);
				flag = 0;
			} else if (flag == -1) {
				pre = nums.top();
				nums.pop();
				num = pre / num;
				nums.push(num);
				flag = 0;
			} else {
				nums.push(num);
			}

			if (c == '-') sig = -1;

			if (c == '*') {
				flag = 1;
			} else if (c == '/') {
				flag = -1;
			}

			num = 0;
		}
	}

	num = num * sig;
	if (flag == 1) {
		num = nums.top() * num;
		nums.pop();
	}

	if (flag == -1) {
		num = nums.top() / num;
		nums.pop();
	}

	while (!nums.empty()) {
		num = num + nums.top();
		nums.pop();
	}

	return num;
}

int main() {
	string s;
	while (getline(cin, s)) {
		cout << calculate(s) << endl;
	}

	return 0;
}
