#include <iostream>

using namespace std;

TreeNode *helpBuild(vector<int> &preorder, int preBeg, int preEnd,
			vector<int> &inorder, int inBeg, int inEnd) {
	int val = preorder[preBeg];
	int i;

	if (inBeg > inEnd || preBeg > preEnd) return nullptr;

	TreeNode *node = new TreeNode(val);

	if (preBeg == preEnd)
		return node;

	for (i = inBeg; i <= inEnd; i++) {
		if (inorder[i] == val )
			break;
	}

	node->left = helpBuild(preorder, preBeg + 1, preBeg+(i-inBeg),
			inorder, inBeg, i - 1);

	node->right = helpBuild(preorder, preBeg + (i-inBeg + 1), preEnd,
			inorder, i + 1, inEnd);
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	if (preorder.size() == 0) return NULL;
	return helpBuild(preorder, 0, preorder.size() - 1,
				inorder, 0, inorder.size() - 1);
}
