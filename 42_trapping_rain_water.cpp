#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height) {
	int n = height.size();
	if (n < 3) return 0;
	int res = 0;
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	left[0] = height[0];
	right[n-1] = height[n-1];
	for (int i = 1; i < height.size(); i++)
		left[i] = max(left[i-1], height[i]);

	for (int i = n-2; i >= 0; i--)
		right[i] = max(right[i+1], height[i]);

	for (int i = 0; i < n; i++) {
		int tmp = min(left[i], right[i]);
		if (tmp > height[i]) {
			res += tmp - height[i];
		}
	}

	return res;
}

int main()
{
	vector<int> height;
	height.push_back(0);
	height.push_back(1);
	height.push_back(0);
	height.push_back(2);
	height.push_back(1);
	height.push_back(0);
	height.push_back(1);
	height.push_back(3);
	height.push_back(2);
	height.push_back(1);
	height.push_back(2);
	height.push_back(1);

	cout << trap(height) << endl;
}
