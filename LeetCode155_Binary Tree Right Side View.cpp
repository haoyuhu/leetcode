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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> answer;
        if (!root) return answer;
        queue<TreeNode *> level;
        level.push(root);
        TreeNode *last, *final = root;
        while (!level.empty()) {
        	TreeNode * curr = level.front(); level.pop();
        	if (curr->left) {
        		level.push(curr->left);
        		last = curr->left;
        	}
        	if (curr->right) {
        		level.push(curr->right);
        		last = curr->right;
        	}
        	if (curr == final) {
        		answer.push_back(curr->val);
        		final = last;
        	}
        }
        return answer;
    }
};