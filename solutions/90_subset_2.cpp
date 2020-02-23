#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void dfs(const vector<int> &nums, vector<int> &path, int step,
		vector<vector<int> > &result) {
		result.push_back(path);

	for (int i = step; i < nums.size(); i++) {
		if (i != step && nums[i] == nums[i-1]) continue;

		path.push_back(nums[i]);
		dfs(nums, path, i+1, result);
		path.pop_back();
	}
}

vector<vector<int> > subsetWithDup(vector<int> & nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int> > result;
	vector<int> path;

	dfs(nums, path, 0, result);
	return result;
}
