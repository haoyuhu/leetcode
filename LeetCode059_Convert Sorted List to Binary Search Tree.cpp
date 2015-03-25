/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> ivec;
        ListNode *p = head;
        while (p){
        	ivec.push_back(p->val);
        	p = p->next;
        }
        TreeNode *root;
        create_tree(root, ivec, 0, ivec.size() - 1);
        return root;
    }
    void create_tree(TreeNode *&root, const vector<int> &ivec, int i, int j){
    	if (i > j) {
    		root = NULL; return;
    	}
    	int mid = (i + j) / 2;
    	root = (TreeNode*)malloc(sizeof(TreeNode));
    	root->val = ivec[mid];
    	create_tree(root->left, ivec, i, mid - 1);
    	create_tree(root->right, ivec, mid + 1, j);
    }
};