#include <iostream>
#include <vector>

using namespace std;

static void subsets(const vector<int> &nums, vector<int>&path,
			int step, vector<vector<int> > &result) {
	if (step == nums.size()) {
		result.push_back(path);
		return;
	}

	subsets(nums, path, step+1, result);
	path.push_back(nums[step]);
	subsets(nums, path, step+1, result);
	path.pop_back();
}

vector<vector<int> > subsets(vector<int> nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int> >res;
	vector<int> path;
	subsets(nums, path, 0, res);
	return res;
}
