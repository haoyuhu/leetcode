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
        findLowestCommonAncestor(root, p, q);
        return ancestor;
    }
private:
	TreeNode* ancestor;
	bool findLowestCommonAncestor(TreeNode* current, TreeNode* p, TreeNode* q) {
		if (!current) {
			return false;
		}
		bool isLeft = findLowestCommonAncestor(current->left, p, q);
		bool isRight = findLowestCommonAncestor(current->right, p, q);
		bool isCurrent = (current == p) || (current == q);
		if (isLeft && isCurrent || isRight && isCurrent || isLeft && isRight) {
			ancestor = current;
			return false;
		}
		return isCurrent || isLeft || isRight;
	}
};