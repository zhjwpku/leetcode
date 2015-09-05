#include <iostream>
#include <stack>
using namespace std;

bool isSymmetric(TreeNode *root) {
	return root ? isSymmetric(root->left, root->right) : true;
}

bool isSymmetric(TreeNode *left, TreeNode *right) {
	if (!left && !right) return true;
	if (!left || !right) return false;

	return (left->val == right->val &&
		isSymmetric(left->left, right->right) &&
		isSymmetric(left->right, right->left));
}
