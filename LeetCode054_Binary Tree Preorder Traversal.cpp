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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        preorderTraverse(root, preorder);
        return preorder;
    }
    void preorderTraverse(TreeNode *root, vector<int> &orderlist){
    	if (!root) return;
    	orderlist.push_back(root->val);
    	preorderTraverse(root->left, orderlist);
    	preorderTraverse(root->right, orderlist);
    }
};
/////////
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode *p;
        while (!stk.empty()){
        	while ((p = stk.top()) && p){
        		preorder.push_back(p->val);
        		stk.push(p->left);
        	}
        	stk.pop();
        	if (!stk.empty()){
        		p = stk.top();
        		stk.pop(); stk.push(p->right);
        	}
        }
        return preorder;
    }
};

/////////
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        postorderTraverse(root, postorder);
        return postorder;
    }
    void postorderTraverse(TreeNode *root, vector<int> &orderlist){
    	if (!root) return;
    	postorderTraverse(root->left, orderlist);
    	postorderTraverse(root->right, orderlist);
    	orderlist.push_back(root->val);
    }
};
//////////////
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	struct pair{
    		TreeNode *first;
    		bool second;
    		pair(TreeNode *root, bool tag): first(root), second(tag) {}
    		~pair(){}
    	};
        vector<int> postorder;
        stack<pair> stk;
        stk.push(pair(root, false));
        while (!stk.empty()){
        	pair<TreeNode*, bool> p;
        	while ((p = stk.top()) && p.first != NULL){
        		stk.push(pair(p->left, false));
        	}
        	stk.pop();
        	while (!stk.empty() && (p = stk.top()) && (p.second || !p.second && !p.first->right)){
        		postorder.push_back(p->val);
        		stk.pop();
        	}
        	if (!stk.empty()) {
        		stk.pop();
        		stk.push(pair(p, true));
        		stk.push(pair(p->right, false));
        	}
        }
        return postorder;
    }
};