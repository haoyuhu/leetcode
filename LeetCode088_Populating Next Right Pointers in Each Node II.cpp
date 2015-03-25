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
        int tail = 1, count = 0, i = 0;
        queue<TreeLinkNode*> treeque;
        treeque.push(root);
        while (!treeque.empty()){
        	TreeLinkNode *pre = treeque.front();
        	treeque.pop();
        	if (pre->left) {
        		treeque.push(pre->left);
        		++count;
        	}
        	if (pre->right) {
        		treeque.push(pre->right);
        		++count;
        	}
        	if (++i != tail && !treeque.empty()) {
        		TreeLinkNode *suc = treeque.front();
        		pre->next = suc;
        	}
        	else {
        		if (!treeque.empty()) {
        			tail = count;
        			i = count = 0;
        		}
        		pre->next = NULL;
        	}
        }
    }
};