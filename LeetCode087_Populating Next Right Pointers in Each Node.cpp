/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (!root)
    		return;
        int count = 1;
        queue<TreeLinkNode*> treeque;
        treeque.push(root);
        int i = 0;
        while (!treeque.empty()){
        	TreeLinkNode *pre = treeque.front(), *suc;
        	treeque.pop();
        	if (pre->left) {
        		treeque.push(pre->left);
        		treeque.push(pre->right);
        	}
        	if (++i != count && !treeque.empty()) {
        		suc = treeque.front();
        		pre->next = suc;
        	}
        	else {
        		if (!treeque.empty()) {
        			i = 0; count *= 2;
        		}
        		pre->next = NULL;
        	}
        }
    }
};