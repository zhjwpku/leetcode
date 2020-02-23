#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(TreeNode * root, int &max_sum) {
	if (root == nullptr) return 0;
	int l = dfs(root->left, max_sum);
	int r = dfs(root->right, max_sum);

	int sum = root->val;
	if (l > 0) sum += l;
	if (r > 0) sum += r;

	max_sum = max(max_sum, sum);

	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}

int maxPathSum(TreeNode *root) {
	int max_sum = INT_MIN;
	dfs(root, max_sum);

	return max_sum;
}
