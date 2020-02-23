#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;
	stack<TreeNode *> stk;

	TreeNode *p, *q;

	p = root;

	do {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}

		q = NULL;
		while (!stk.empty()) {
			p = stk.top();
			stk.pop();

			if (p->right == q) {
				result.push_back(p->val);
				q = p;
			} else {
				stk.push(p);
				p = p->right;
				break;
			}
		}
	} while (!stk.empty());

	return result;
}

vector<int> postorderTraversal2(TreeNode *root) {
	stack<TreeNode *> stk;
	vector<int> res;

	if (root == NULL) return res;

	stk.push(root);

	while (!stk.empty()) {
		TreeNode *p = stk.top();
		stk.pop();
		res.push_back(p->val);

		if (p->left) stk.push(p->left);
		if (p->right) stk.push(p->right);
	}

	reverse(res.begin(), res.end());
	return res;
}
