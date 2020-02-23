#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void dfs(int n, vector<int> &path, int k, int start, vector<vector<int>> &res) {
	if (cur == k) {
		res.push_back(path);
		return;
	}

	for (int i = start; i <= n; i++) {
		path.push_back(i);
		dfs(n, path, k, i+1, res);	//here must be i+1, not start+1
		path.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> path;

	dfs(n, path, k, 1, res);
	return res;
}
