#include <iostream>
#include <vector>

using namespace std;

int lower(vector<int> &nums, int target) {
	int l = 0;
	int r = nums.size() - 1;

	while (l < r - 1) {
		int m = (l+r)/2;
		if (nums[m] > target)
			r = m - 1;
		else if (nums[m] < target)
			l = m + 1;
		else
			r = m;
	}

	if (nums[l] == target)
		return l;
	if (nums[r] == target)
		return r;
	return -1;
}

int upper(vector<int> &nums, int target) {
	int l = 0;
	int r = nums.size() -1;

	while (l < r - 1) {
		int m = (l+r)/2;
		if (nums[m] > target)
			r = m - 1;
		else if (nums[m] < target)
			l = m + 1;
		else
			l = m;
	}

	if (nums[r] == target)
		return r;
	if (nums[l] == target)
		return l;
	return -1;
}

vector<int> searchRange(vector<int>&nums, int target) {
	vector<int> res;
	res.push_back(lower(nums, target));
	res.push_back(upper(nums, target));
	return res;
}
