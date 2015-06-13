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
    int countNodes(TreeNode* root) {
    	int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }

    void dfs(TreeNode * root, int & cnt) {
    	if (!root) return;
    	count(root->left);
    	++cnt;
    	count(root->right);
    }
};
//Time Limit Exceeded

class Solution {
public:
    int countNodes(TreeNode* root) {
    	int leftHeight = getLeftHeight(root);
    	int rightHeight = getRightHeight(root);
    	if (leftHeight == rightHeight) {
    		return (1 << leftHeight) - 1;
    	}

    	queue<TreeNode*> treeNodeQueue;
    	treeNodeQueue.push(root);
    	int level = 1, count = 0;
    	TreeNode *last, *final;
    	final = root;
    	while (!treeNodeQueue.empty()) {
    		TreeNode * current = treeNodeQueue.front();
    		treeNodeQueue.pop();
    		if (level == leftHeight - 1) {
    			bool hasLeft = true, hasRight = true;
    			if (hasLeft = (current->left != NULL)) {
    				++count;
    			} else {
    				hasLeft = false; break;
    			}
    			if (hasRight = (current->right != NULL)) {
    				++count;
    			} else {
    				hasRight = false; break;
    			}
    		} else {
    			if (current->left) {
    				treeNodeQueue.push(current->left);
    				last = current->left;
    			}
    			if (current->right) {
    				treeNodeQueue.push(current->right);
    				last = current->right;
    			}
    		}
    		if (current == final) {
    			++level;
    			final = last;
    		}
    	}
    	return (1 << rightHeight) - 1 + count;
    }

    int getLeftHeight(TreeNode * root) {
    	int count = 0;
    	while (root) {
    		root = root->left;
    		++count;
    	}
    	return count;
    }

    int getRightHeight(TreeNode * root) {
    	int count = 0;
    	while (root) {
    		root = root->right;
    		++count;
    	}
    	return count;
    }
};
