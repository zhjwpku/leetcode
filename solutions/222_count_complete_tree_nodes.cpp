#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void dfs(TreeNode *root, int lv, int lv2) {
	if (root == NULL) return;
	if (lv == lv2) {
		cnt++;
		return;
	}

	dfs(root->left, lv+1, lv2);
	dfs(root->right, lv+1, lv2);

}

int countNodes_dfs_TLE(TreeNode *root) {
	if (root == NULL) return 0;
	TreeNode *p = root;
	int lv = 0;
	int rst = 1;
	while (p) {
		lv += 1;
		p = p->left;
	}

	dfs(root, 0, lv-1);

	for (int i = 1; i < lv; i++)
		rst << 1;

	return rst - 1 + cnt;
}

int countNodes(TreeNode *root) {
	if (!root) return 0;
	TreeNode *temp = root;
	int height = 0, count = 0, level;
	while (temp) {
		temp = temp->left;
		height ++;
	}

	temp = root;
	level = height - 2;

	while (level >= 0) {
		TreeNode *left = temp->left;
		for (int i = 0; i < level; i++) {
			left = left->right;
		}

		if (left) {
			temp = temp->right;
			count+=(1 << level);
		} else temp = temp->left;

		level --;
	}

	if (temp) count ++;
	return (1 << (height - 1)) + count - 1;
}
