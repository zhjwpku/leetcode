#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void binaryTreePaths(TreeNode *root, vector<int>&cur, vector<vector<int> > &result) {
	if (root == NULL) return;

	cur.push_back(root->val);

	if (root->left == NULL && root->right == NULL)
		result.push_back(cur);

	binaryTreePaths(root->left, cur, result);
	binaryTreePaths(root->right, cur, result);

	cur.pop_back();
}

vector<string> binaryTreePaths(TreeNode *root) {
	vector<vector<int> > result;
	vector<int> cur;

	binaryTreePaths(root, cur, result);

	vector<string> res;

	for (int i = 0; i < result.size(); i++) {
		string tmp = "";
		stringstream ss;
		for (int j = 0; j < result[i].size() - 1; j++)
			ss << result[i][j] << "->";
		ss << result[i][result[i].size()-1];
		ss >> tmp;

		res.push_back(tmp);
	}

	return res;
}
