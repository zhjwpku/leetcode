#include <iostream>
#include <vector>
using namespace std;

TreeNode *help(vector<int> &inorder, int inBeg, int inEnd,
		vector<int> &postorder, int postBeg, int postEnd) {
	if (inBeg > inEnd || postBeg > postEnd) return nullptr;

	int val = postorder[postEnd];
	int i;
	TreeNode *node = new TreeNode(val);

	if (postBeg == postEnd) return node;

	for (i = inBeg; i <= inEnd; i++) {
		if (val == inorder[i])
			break;
	}

	node->left = help(inorder, inBeg, i - 1,
			postorder, postBeg, postBeg + (i-inBeg-1));

	node->right = help(inorder, i + 1, inEnd,
			postorder, postBeg + (i-inBeg), postEnd - 1);
	return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	return help(inorder, 0, inorder.size() - 1,
			postorder, 0, postorder.size() - 1);
}

