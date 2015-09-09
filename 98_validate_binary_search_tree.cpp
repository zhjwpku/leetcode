#include <iostream>
#include <stack>
using namespace std;

bool isValidBST(TreeNode *root, long long lower, long long upper) {
	if (!root) return true;

	return (root->val > lower && root->val < upper &&
		isValidBST(root->left, lower, root->val) &&
		isValidBST(root->right, root->val, upper));
}

bool isValidBST(TreeNode *root) {
	return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

