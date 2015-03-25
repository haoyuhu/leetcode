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
	typedef vector<int>::iterator iter;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root;
        create_tree(root, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        return root;
    }
    void create_tree(TreeNode *&root, iter start_pre, iter end_pre, iter start_in, iter end_in) {
    	if (start_pre == end_pre) {
    		root = NULL; return;
    	}
    	int mid = *start_pre;
    	root = (TreeNode*)malloc(sizeof(TreeNode));
    	root->val = mid;
    	iter mid_pre, mid_in;
    	mid_in = find(start_in, end_in, mid);
    	int gap = mid_in - start_in;
    	++start_pre;
    	mid_pre = start_pre + gap;
    	create_tree(root->left, start_pre, mid_pre, start_in, mid_in);
    	create_tree(root->right, mid_pre, end_pre, mid_in + 1, end_in);
    }
};