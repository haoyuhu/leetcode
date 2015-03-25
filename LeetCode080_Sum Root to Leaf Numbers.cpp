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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if (root) {
        	sum_solution(root, sum, 0);
        }
        return sum;
    }
    void sum_solution(TreeNode *root, int &sum, int now){
    	now = now * 10 + root->val;
    	if (!root->right && !root->left) {
    		sum += now;
    		return;
    	}
    	if (root->right)
    		sum_solution(root->right, sum, now);
    	if (root->left)
    		sum_solution(root->left, sum, now);
    }
};