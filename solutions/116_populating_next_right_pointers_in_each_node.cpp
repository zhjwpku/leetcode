#include <iostream>
#include <vector>

using namespace std;

void connect(TreeLinkNode *root) {
	if (root == NULL) return;

	TreeLinkNode dummy(-1);
	for (TreeLinkNode *cur = root, *prev = &dummy;
		cur; cur = cur->next) {
		if (cur->left != nullptr) {
			prev->next = cur->left;
			prev = prev->next;
		}
		if (cur->right != nullptr) {
			prev->next = cur->right;
			prev = prev->next;
		}
	}

	connect(dummy.next);
}
