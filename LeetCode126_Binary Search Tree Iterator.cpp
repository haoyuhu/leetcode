/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        tstk.push(root);
        TreeNode *p;
        while ((p = tstk.top()) && p) {
        	tstk.push(p->left);
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (tstk.size() >= 2)
        	return true;
        else
        	return false;
    }

    /** @return the next smallest number */
    int next() {
        tstk.pop();
        TreeNode *tp = tstk.top(), *p;
        tstk.pop();
        tstk.push(tp->right);
        while ((p = tstk.top()) && p)
        	tstk.push(p->left);
        return tp->val;
    }
private:
    stack<TreeNode*> tstk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */