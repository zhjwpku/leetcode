#include <iostream>
#include <queue>

using namespace std;

vector<vector<int> > levelOrder(TreeNode * root) {
	vector<vector<int> > res;
	queue<TreeNode *> queue1;
	queue<TreeNode *> queue2;

	if (root == NULL)
		return res;

	queue1.push(root);

	while(!queue1.empty()) {
		vector <int> tmp;
		while (!queue1.empty()) {
			TreeNode *p = queue1.front();
			queue1.pop();

			tmp.push_back(p->val);

			if (p->left) queue2.push(p->left);
			if (p->right) queue2.push(p->right);
		}

		res.push_back(tmp);
		swap(queue1, queue2);
	}

	return res;
}
