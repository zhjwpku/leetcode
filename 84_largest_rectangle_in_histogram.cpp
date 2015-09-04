#include <iostream>
#include <vector>
using namespace std;

// O(n2) TLE
int largestRectangleArea_TLE(vector<int>& height) {
	if (height.size() == 0) return 0;
	if (height.size() == 1) return height[0];

	int maxi = height[height.size() - 1];

	for (int i = 0; i < height.size() - 1; i++) {
		int rect = height[i];
		int mini = height[i];
		for (int j = i+1; j < height.size(); j++) {
			mini = min(mini, height[j]);
			rect = max(rect, (j-i+1) * mini);
		}

		maxi = max(maxi, rect);
	}

	return maxi;
}

int largestRectangleArea(vector<int> &height) {
	stack<int> stk;
	height.push_back(0);
	int res = 0;

	for (int i = 0; i < height.size();) {
		if (stk.empty() || height[i] > height[stk.top()])
			stk.push(i++);
		else {
			int tmp = stk.top();
			stk.pop();
			res = max(res,
				height[tmp] * (stk.empty() ? i : i - stk.top() - 1));
		}
	}

	return res;
}
