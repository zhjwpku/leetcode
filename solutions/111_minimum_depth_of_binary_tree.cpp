#include <iostream>
using namespace std;

int minDepth(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	if (root->left == NULL)
		return minDepth(root->right) + 1;
	if (root->right == NULL)
		return minDepth(root->left) + 1;

	int l = minDepth(root->left);
	int r = minDepth(root->right);

	return min(l, r) + 1;
}
