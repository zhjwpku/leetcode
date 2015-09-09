#include <iostream>
using namespace std;

TreeNode* sortedArrayToBST(vector<int> &nums, int l, int r) {
	if (l == r){
		TreeNode *root = new TreeNode(nums[l]);
		return root;
	}

	if (l > r) return NULL;

	int mid = (l + r) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	TreeNode *left = sortedArrayToBST(nums, left, mid-1);
	TreeNode *right = sortedArrayToBST(nums, mid+1, right);

	root->left = left;
	root->right = right;
	return root;
}

TreeNode * sortedArrayToBST(vector<int> &nums) {
	if (nums.size() == 0) return NULL;

	return sortedArrayToBST(nums, 0, nums.size() - 1);
}
