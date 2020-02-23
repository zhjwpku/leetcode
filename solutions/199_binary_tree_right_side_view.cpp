#include <iostream>
#include <vector>
#include <queue>

vector<int> rightSideView(TreeNode *root) {
	vector<int> res;
	if (root == NULL) {
		return res;
	}

	queue<TreeNode *> q1;
	queue<TreeNode *> q2;

	q1.push(root);

	while (!q1.empty()) {
		vector<int> abc;
		while (!q1.empty()) {
			TreeNode *p = q1.front();
			q1.pop();
			abc.push_back(p->val);

			if (p->left)
				q2.push(p->left);
			if (p->right)
				q2.push(p->right);
		}

		swap(q1, q2);
		res.push_back(abc[abc.size()-1]);
	}

	return res;
}

// below is using dfs
void dfs(TreeNode *root, int lv, vector<int> &res) {
	if (!root) return;
	if (lv >= res.size()) res.push_back(root->val);

	dfs(root->right, lv+1, res);
	dfs(root->left, lv+1, res);
}

vector<int> rightSideView_dfs(TreeNode *root) {
	vector<int> res;
	dfs(root, 0, res);
	return res;
}
