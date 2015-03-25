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
    void flatten(TreeNode *root) {
        TreeNode *pre;
        flatten_tree(pre, root);
    }
    void flatten_tree(TreeNode *&pre, TreeNode *now){
    	if (!now)
    		return;
    	TreeNode *right = now->right;
    	if (pre) {
    		pre->right = now;
    		pre->left = NULL;
    	}
    	pre = now;
    	flatten_tree(pre, now->left);
    	flatten_tree(pre, right);
    }
};