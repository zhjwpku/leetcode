#include <iostream>
#include <vector>

void connect(TreeLinkNode *root) {
	if (root == nullptr) return;

	TreeLinkNode dummy(-1);
	for (TreeLinkNode *cur = root, *prev = &dummy; cur; cur=cur->next) {
		if (cur->left) {
			prev->next = cur->left;
			prev = prev->next;
		}

		if (cur->right) {
			prev->next = cur->right;
			prev = prev->next;
		}
	}

	connect(dummy.next);
}
