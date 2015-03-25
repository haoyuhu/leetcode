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
	#define MIN_INT -999999999
	typedef struct MyTreeNode{
        int pathleft, pathright, max;
        struct MyTreeNode *left, *right;
    }MyTreeNode, *MyTree;
    int max_two(int x, int y){
    	return x > y ? x : y;
    }
    int max_three(int x, int y, int z){
    	if (x > y && x > z)
    		return x;
    	else if (y > x && y > z)
    		return y;
    	else
    		return z;
    }
    int maxPathSum(TreeNode *root) {
    	MyTree mytree = NULL;
    	int max = CreateScoreTree(mytree, root);
        if (!max)
            // max = SearchSpecial(root);
            max = MIN_INT;
            SearchSpecial(root, max);
        ClearTree(mytree);
        return max;
    }
    int CreateScoreTree(MyTree &mytree, TreeNode *root){
    	if (!root){
    		mytree = NULL; return 0;
    	}
    	mytree = (MyTree)malloc(sizeof(MyTreeNode));
    	int maxl = CreateScoreTree(mytree->left, root->left);
    	int maxr = CreateScoreTree(mytree->right, root->right);
    	mytree->pathleft = mytree->left ? max_two(mytree->left->pathleft, mytree->left->pathright) + root->left->val : 0;
    	if (mytree->pathleft < 0)
    		mytree->pathleft = 0;
     	mytree->pathright = mytree->right ? max_two(mytree->right->pathleft, mytree->right->pathright) +root->right->val : 0;
     	if (mytree->pathright < 0)
     		mytree->pathright = 0;
    	mytree->max = max_three(maxl, maxr, mytree->pathleft + mytree->pathright + root->val);
    	return mytree->max;
    }
/*    int SearchSpecial(const TreeNode *&root){
    	if (!root)
    		return MIN_INT;
    	int maxl = SearchSpecial(root->left);
    	int maxr = SearchSpecial(root->right);
    	if (maxl >= maxr && maxl >= root->val)
    		return maxl;
    	else if (maxr >= maxl && maxr >= root->val)
    		return maxr;
    	else
    		return root->val;
    }*/
    void SearchSpecial(TreeNode *root, int &max){
        if (!root)
            return;
        SearchSpecial(root->left, max);
        if (max < root->val)
            max = root->val;
        SearchSpecial(root->right, max);
    }
    void ClearTree(MyTree &mytree){
    	if (!mytree) return;
    	ClearTree(mytree->left);
    	ClearTree(mytree->right);
    	free(mytree);
    }
};