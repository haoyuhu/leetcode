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
    bool isSymmetric(TreeNode *root) {
        TreeNode * symroot = root;
        return Symmetric(root, symroot);
    }
    bool Symmetric(TreeNode * root1, TreeNode * root2){
        if (!root1 && !root2) return true;
        else if (!root1 && root2 || !root2 && root1) return false;
        else if (Symmetric(root1->right, root2->left) && Symmetric(root1->left, root2->right) && root1->val == root2->val) return true;
        else return false;
    }
};
