/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    	for (int i = 0; i != n + 2; ++i) {
    		treeStore.push_back(vector<vector<TreeNode*>>(n + 2));
    	}
        dfsGenerateTrees(1, n);
        return treeStore[1][n];
    }
private:
	vector<vector<vector<TreeNode*>>> treeStore;
	void dfsGenerateTrees(int bottom, int top) {
		if (bottom > top) {
			treeStore[bottom][top].push_back(NULL);
			return;
		}
		for (int i = bottom; i <= top; ++i) {
			if (treeStore[bottom][i-1].empty()) {
				dfsGenerateTrees(bottom, i - 1);
			}
			if (treeStore[i+1][top].empty()) {
				dfsGenerateTrees(i + 1, top);
			}
			for (TreeNode* leftRoot : treeStore[bottom][i-1]) {
				for (TreeNode* rightRoot : treeStore[i+1][top]) {
					TreeNode* current = new TreeNode(i);
					TreeNode* left = copyTree(leftRoot);
					TreeNode* right = copyTree(rightRoot);
					current->left = left;
					current->right = right;
					treeStore[bottom][top].push_back(current);
				}
			}
		}
	}

	TreeNode* copyTree(TreeNode* root) {
		if (!root) {
			return NULL;
		}
		TreeNode* copy = new TreeNode(root->val);
		copy->left = copyTree(root->left);
		copy->right = copyTree(root->right);
		return copy;
	}
};