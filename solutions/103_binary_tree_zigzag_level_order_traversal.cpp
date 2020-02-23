#include <iostream>
#include <queue>
using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> > res;
	vector<int> level;
	queue<TreeNode *> qu;
	bool right_to_left = false;

	if (root != NULL) {
		qu.push(root);
		qu.push(nullptr);	// level seperator
	}

	while (!qu.empty()) {
		TreeNode *tmp = qu.front();
		qu.pop();

		if (tmp) {
			level.push_back(tmp->val);

			if (tmp->left) qu.push(tmp->left);
			if (tmp->right) qu.push(tmp->right);
		} else {
			if (right_to_left)
				reverse(level.begin(), level.end());

			res.push_back(level);

			level.clear();
			right_to_left = !right_to_left;

			if (qu.size() > 0) qu.push(nullptr);
		}
	}

	return res;
}
