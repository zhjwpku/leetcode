#include <iostream>
#include <stack>

using namespace std;

int kthSmallest(TreeNode *root, int k) {
	stack<TreeNode*> stk;
	TreeNode *p = root;
	while (p || !stk.empty()) {
		while(p) {
			stk.push(p);
			p = p->left;
		}
		p = stk.top();
		if (--k == 0)
			return p->val;
		stk.pop();
		p = p->right;
	}
}
