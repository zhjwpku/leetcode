#include <iostream>

vector <TreeNode *> generateTrees(int n) {
	if (n == 0) return vector<TreeNode *>(1, NULL);

	vector<vector<vector<TreeNode *> > > treeMap(n+2,
			vector<vector<TreeNode *> >(n+2, vector<TreeNode*>()));

	for (int i = 1; i <= n + 1; i++) {
		treeMap[i][i].push_back(new TreeNode(i));
		treeMap[i][i-1].push_back(NULL);
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			for (int j = i; j <= i+l-1; j++) {
				for (int k = 0; k < treeMap[j+1][i+l-1].size(); k++) {
					for (int m = 0; m < treeMap[i][j-1].size(); m++) {
						TreeNode *T = new TreeNode(j);
						T->left = treeMap[i][j-1][m];
						T->right = treeMap[j+1][i+l-1][k];
						treeMap[i][i+l-1].push_back(T);
					}
				}
			}
		}
	}

	return treeMap[1][n];
}
