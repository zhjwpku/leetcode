#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
	queue<int> q;
public:
	void push(int x) {
		q.push(x);
	}

	void pop() {
		for (int i = 0; i < q.size() - 1; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		q.pop();
	}

	int top() {
		return q.back();
	}

	bool empty() {
		return q.empty();
	}
}
