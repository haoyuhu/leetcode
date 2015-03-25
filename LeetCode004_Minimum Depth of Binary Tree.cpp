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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        else if (!root->left) return minDepth(root->right) + 1;
        else if (!root->right) return minDepth(root->left) + 1;
        else{
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return left>right?(right + 1):(left + 1);
        }
    }
};
