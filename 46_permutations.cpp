#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<int> &nums, vector<int> &path,
	vector<vector<int>> &result) {
	if (path.size() == nums.size()) {
		result.push_back(path);
		return;
	}
	for (auto i : nums) {
		auto pos = find(path.begin(), path.end(), i);

		if (pos == path.end()) {
			path.push_back(i);
			dfs(nums, path, result);
			path.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> path;
	sort(nums.begin(), nums.end());

	dfs(nums, path, res);

	return res;
}
