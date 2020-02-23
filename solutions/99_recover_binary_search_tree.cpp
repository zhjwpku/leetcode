#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode * root) {
	stack<TreeNode *> stk;
	vector<TreeNode *> vec;
	TreeNode *p = root;

	while (!stk.empty() || p != nullptr) {
		if (p != nullptr) {
			stk.push(p);
			p = p->left;
		} else {
			p = stk.top();
			stk.pop();
			cout << p->val << endl;
			vec.push_back(p);
			p = p->right;
		}
	}

	TreeNode *p1;
	TreeNode *p2;

	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i]->val > vec[i+1]->val) {
			p1 = vec[i];
			break;
		}
	}
	for (int i = vec.size() - 1; i > 0; i--) {
		if (vec[i]->val < vec[i-1]->val) {
			p2 = vec[i];
			break;
		}
	}

	swap(p1->val, p2->val);
}

// Morris
void recoverTree_Morris(TreeNode * root) {
	pair<TreeNode *, TreeNode *> broken;
	TreeNode *prev = nullptr;
	TreeNode *cur = root;

	while (cur != nullptr) {
		
	}
}


int main()
{
	TreeNode root(0);
	TreeNode l(1);
	root.left = &l;

	recoverTree(&root);

	return 0;
}
