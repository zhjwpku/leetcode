#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int with;
	int without;

	with = nums[0];
	without = 0;

	for (int i = 1; i < n; i++) {
		int tmp = with;
		with = without + nums[i];
		without = max(without, tmp);
	}

	return max(with, without);
}
