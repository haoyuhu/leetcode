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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root;
        create_tree(root, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        return root;
    }
    void create_tree(TreeNode *&root, iter start_in, iter end_in, iter start_post, iter end_post) {
    	if (start_in == end_in) {
    		root = NULL; return;
    	}
    	int mid = *(--end_post);
    	iter mid_in = find(start_in, end_in, mid), mid_post;
    	root = (TreeNode*)malloc(sizeof(TreeNode));
    	root->val = mid;
    	int gap = mid_in - start_in;
    	mid_post = start_post + gap;
    	create_tree(root->left, start_in, mid_in, start_post, mid_post);
    	create_tree(root->right, mid_in + 1, end_in, mid_post, end_post);
    }
};