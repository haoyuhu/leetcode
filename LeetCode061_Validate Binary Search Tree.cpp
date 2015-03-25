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
    bool isValidBST(TreeNode *root) {
    	TreeNode *pre = NULL;
    	return inorder_traverse(pre, root);
    }
    bool inorder_traverse(TreeNode *&pre, TreeNode *now){
    	if (!now)
    		return true;
    	if (!inorder_traverse(pre, now->left))
    		return false;
    	if (pre) {
    		if (pre->val >= now->val)
    			return false;
    	}
    	pre = now;
    	if (!inorder_traverse(pre, now->right))
    		return false;
    	return true;
    }
};