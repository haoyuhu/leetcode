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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        TreeNode *final, *last, *now;
        vector< vector<int> > answer;
        if (!root)
        	return answer;
        queue<TreeNode*> treeque;
        final = root;
        treeque.push(root);
        vector<int> level;
        while (!treeque.empty()) {
        	now = treeque.front();
        	level.push_back(now->val);
        	treeque.pop();
        	if (now->left) {
        		treeque.push(now->left);
        		last = now->left;
        	}
        	if (now->right) {
        		treeque.push(now->right);
        		last = now->right;
        	}
        	if (now == final) {
        		answer.insert(answer.begin(), level);
        		level.clear();
        		final = last;
        	}
        }
    }
};