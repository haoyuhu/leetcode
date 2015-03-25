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
        TreeNode * symroot;
        CopySymmetricTree(root, symroot);
        return isSameTree(root, symroot);
    }
    void CopySymmetricTree(TreeNode * root1, TreeNode * root2){
        if (!root1){
            root2 = NULL;
            return;
        }
        root2 = (TreeNode *)malloc(sizeof(TreeNode));
        root2->val = root1->val;
        CopySymmetricTree(root1->left, root2->right);
        CopySymmetricTree(root1->right, root2->left);
    }
    bool isSameTree(TreeNode * root1, TreeNode *root2){
        if (!root1 && !root2) return true;
        if (!root1 && root2 || !root2 && root1) return false;
        if (isSameTree(root1->right, root2->right) && isSameTree(root1->left, root2->left) && root1->val == root2->val) return true;
        else return false;
    }
};
