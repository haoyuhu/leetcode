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
    int kthSmallest(TreeNode* root, int k) {
    	findKthSmallest(root, k);
        return value;
    }
private:
	int value;
	int findKthSmallest(TreeNode* current, int k) {
		if (!current) {
			return 0;
		}
		int left = findKthSmallest(current->left, k);
		if (left == -1) {
			return -1;
		}
		if (left + 1 == k) {
			value = current->val;
			return -1;
		}
		int right = findKthSmallest(current->right, k - left - 1);
		return right == -1 ? right : left + right + 1;
	}
};