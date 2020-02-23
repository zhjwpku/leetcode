#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode * root) {
	queue<TreeNode *> qu1;
	queue<TreeNode *> qu2;
	vector<vector<int> > res;

	if (root != NULL)
		qu1.push(root);

	while (!qu1.empty()) {
		vector<int> level;
		while (!qu1.empty()) {
			TreeNode *p = qu1.front();
			qu1.pop();

			level.push_back(p->val);

			if (p->left) qu2.push(p->left);
			if (p->right) qu2.push(p->right);
		}

		res.insert(vec.begin(), level)
		swap(qu1, qu2);
	}

	return res;
}
