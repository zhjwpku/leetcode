#include <stack>
#include <iostream>

using namespace std;

class Queue {
private:
	stack<int> s1;
	stack<int> s2;

public:
	void push(int x) {
		s1.push(x);
	}

	void pop(void) {
		if (s1.empty())
			return;
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int peek(void) {
		if (s1.empty())
			return -1;

		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		int t = s2.top();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		return t;
	}

	bool empty(void) {
		return s1.empty();
	}
}
