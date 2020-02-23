#include <iostream>
#include <stack>

// iteratively
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;
	stack<TreeNode *> stk;
	TreeNode *p = root;

	while (!stk.empty() || p != NULL) {
		if (p != NULL) {
			stk.push(p);
			p = p->left;
		} else {
			p = stk.top();
			stk.pop();
			res.push_back(p->val);
			p = p->right;
		}
	}

	return res;
}
