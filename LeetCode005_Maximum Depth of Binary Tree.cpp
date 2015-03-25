/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        else if (!root->left) return maxDepth(root->right) + 1;
        else if (!root->right) return maxDepth(root->left) + 1;
        else{
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return (left>right?(left + 1):(right + 1));
        }
    }
};
