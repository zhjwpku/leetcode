#include <iostream>
#include <vector>

void pathSum(TreeNode *root, vector<int> &cur, int gap, vector<vector<int> > &result) {
	if (root == NULL) return;

	cur.push_back(root->val);

	if (root->left == NULL && root->right == NULL && gap == root->val)
		result.push_back(cur);

	pathSum(root->left, cur, gap - root->val, result);
	pathSum(root->right, cur, gap - root->val, result);

	cur.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > res;
	vector<int> cur;
	pathSum(root, cur, sum, res);

	return res;
}
