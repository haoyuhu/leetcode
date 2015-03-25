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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ivec;
        inorder_traverse(root, ivec);
        return ivec;
    }
    void inorder_traverse(TreeNode *root, vector<int> &ivec){
    	if (!root)
    		return;
    	inorder_traverse(root->left, ivec);
    	ivec.push_back(root->val);
    	inorder_traverse(root->right, ivec);
    }
};
//
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> stk;
        vector<int> answer;
        TreeNode *p;
        stk.push(root);
        while (!stk.empty()){
        	while ((p = stk.top()) && p){
        		stk.push(p->left);
        	}
        	stk.pop();
        	if (!stk.empty() && (p = stk.top())) {
        		answer.push_back(p->val);
	        	stk.pop();
	        	stk.push(p->right);
        	}
        }
        return answer;
    }
};