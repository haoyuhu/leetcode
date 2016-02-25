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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestor = NULL;
        int minVal = min(p->val, q->val), maxVal = max(p->val, q->val);
        preorderTraverse(root, minVal, maxVal);
        return ancestor;
    }
private:
	bool preorderTraverse(TreeNode*& current, int minVal, int maxVal) {
		if (!current) {
			return false;
		}
		if (current->val <= maxVal && current->val >= minVal) {
			ancestor = current;
			return true;
		}
		if (current->val > maxVal) {
			return preorderTraverse(current->left, minVal, maxVal);
		} else {
			return preorderTraverse(current->right, minVal, maxVal);
		}
	}
	TreeNode* ancestor;
};