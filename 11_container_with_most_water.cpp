#include <iostream>
using namespace std;

int maxArea(vector<int> &height) {
	int l = 0;
	int r = height.size() - 1;
	int res = 0;
	while (l < r) {
		int temp = min(height[l], height[r]) * (r-1);
		res = max(res, temp);

		if (height[l] >= height[r])
			r--;
		else
			l++;
	}

	return res;
}
