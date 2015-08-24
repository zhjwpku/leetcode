#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> & nums) {
	const int W = sizeof(int) * 8;
	vector<int> count(W, 0);

	for (int i = 0; i < nums.size(); i++) {
		int tmp = nums[i];
		for (int j = 0; j < W; j++)
			count[j] += (tmp >> j) & 0x1;
	}

	int res = 0;
	for (int i = 0; i < W; i++) {
		if (count[i] %3)
			res += 1 << i;
	}

	return res;
}

int main()
{
	int a[10] = {-2, -2, 1, 1, -3, 1, -3, -3, -4, -2};
	vector<int> nums(a, a+10);
	cout << singleNumber(nums) << endl;
	return 0;
}
