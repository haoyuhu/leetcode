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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > answer;
        vector<int> now;
        if (!root)
        	return answer;
        path_solution(root, sum, now, answer);
        return answer;
    }
    void path_solution(TreeNode *root, int sum, vector<int> now, vector< vector<int> > &answer) {
    	if (!root->left && !root->right && root->val == sum) {
    		now.push_back(root->val);
    		answer.push_back(now);
    		return;
    	}
    	else if (!root->left && !root->right)
    		return;
    	now.push_back(root->val);
    	if (root->left) {
    		path_solution(root->left, sum - root->val, now, answer);
    	}
    	if (root->right) {
    		path_solution(root->right, sum - root->val, now, answer);
    	}
    }
};