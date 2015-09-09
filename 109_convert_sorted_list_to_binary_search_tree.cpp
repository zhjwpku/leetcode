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
	TreeNode *left = sortedArrayToBST(nums, l, mid-1);
	TreeNode *right = sortedArrayToBST(nums, mid+1, r);

	root->left = left;
	root->right = right;
	return root;
}

TreeNode * sortedArrayToBST(ListNode *head) {
	if (head == NULL) return NULL;
	vector<int> nums;
	ListNode *p = head;
	while (p) {
		nums.push_back(p->val);
		p = p->next;
	}

	return sortedArrayToBST(nums, 0, nums.size() - 1);
}
