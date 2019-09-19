/**
 * https://leetcode-cn.com/problems/balanced-binary-tree/submissions/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    if (a > b) return a;
    return b;
}

bool helper(struct TreeNode* root, int *h) {
    int l_h = 0;
    int r_h = 0;
    
    if (root == NULL) {
        *h = 0;
        return true;
    }
    
    if (helper(root->left, &l_h) && helper(root->right, &r_h) && (abs(l_h - r_h) < 2)) {
        *h = max(l_h, r_h) + 1;
        return true;
    }
    
    return false;
}

bool isBalanced(struct TreeNode* root){
    int h = 0;
    return helper(root, &h);
}

