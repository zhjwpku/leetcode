#include <iostream>

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode *tmp = root;

	while (tmp) {
		if (tmp->val == p->val || tmp->val == q->val)
			return tmp;
		if (tmp->val > p->val && tmp->val < q->val)
			return tmp;
		if (tmp->val < p->val && tmp->val > q->val)
			return tmp;

		if (tmp->val > p->val && tmp->val > q->val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	return NULL;
}
