#include <iostream>
#include <vector>

using namespace std;

int balancedHeight(TreeNode *root) {
	if (root == NULL) return 0;

	int left = balancedHeight(root->left);
	int right = balancedHeight(root->right);

	if (left < 0 || right < 0) return -1;

	if (abs(left - right) > 1) return -1;

	return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
	if (root == NULL) return true;
	return balancedHeight(root) >= 0;
}
