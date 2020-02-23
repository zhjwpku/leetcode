#include <iostream>

using namespace std;

void flatten(TreeNode *root) {
	if (root == NULL) return;
	stack<TreeNode *> stk;

	stk.push(root);

	while (!stk.empty()) {
		TreeNode *tmp = stk.top();
		stk.pop();

		if (tmp->right) stk.push(tmp->right);
		if (tmp->left) stk.push(tmp->left);

		tmp->left = NULL;
		if (!stk.empty()) {
			tmp->right = stk.top();
		}
	}
}
