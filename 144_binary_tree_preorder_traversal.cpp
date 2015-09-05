#include <iostream>
#include <stack>
using namespace std;

// iteratively
vector <int> preorderTraversal(TreeNode * root) {
	stack<TreeNode *> stk;
	vector <int> res;

	if (root == NULL)
		return res;

	stk.push(root);

	while (!stk.empty()) {
		TreeNode * tmp = stk.top();
		res.push_back(tmp->val);
		stk.pop();
		if (tmp->right)
			stk.push(tmp->right);
		if (tmp->left)
			stk.push(tmp->left);
	}

	return res;
}
