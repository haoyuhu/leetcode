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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right){
            if (root->val == sum) return true;
            else return false;
        }
        else if (!root->left) return hasPathSum(root->right, sum - root->val);
        else if (!root->right) return hasPathSum(root->left, sum - root->val);
        else{
            if (hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val)) return true;
            else return false;
        }
    }
};
