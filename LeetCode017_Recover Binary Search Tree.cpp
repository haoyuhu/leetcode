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
    typedef struct Lnode{
		TreeNode *tree;
		struct Lnode *next;
    }Lnode, *LList;
	void recoverTree(TreeNode *root) {
        LList L = (LList)malloc(sizeof(Lnode));
		L->tree = NULL;
		L->next = NULL;
		InOrderTraverse(root, L);
		LList p = L->next;
		LList mst1 = NULL, mst2 = NULL;
		while (p->next){
			if (p->tree->val < p->next->tree->val){
				if (!mst1){
					mst1 = p;
				}
				else{
					mst2 = p->next;
				}
				p = p->next;
			}
		}
		if (!mst2){
			mst2 = mst1->next;
		}
		int tmp;
		tmp = mst1->tree->val;
		mst1->tree->val = mst2->tree->val;
		mst2->tree->val = tmp;
		return;
    }
    void InOrderTraverse(TreeNode *p, LList L){
		if (!p){
			return;
		}
		InOrderTraverse(p->left, L);
		StoreTNode(p, L);
		InOrderTraverse(p->right, L);
    }
	void StoreTNode(TreeNode *p, LList L){
		LList q = (LList)malloc(sizeof(Lnode));
		q->tree = p;
		q->next = L->next;
		L->next = q;
	}
};

//
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
    void recoverTree(TreeNode *root) {
        TreeNode *pre = NULL;
        TreeNode *mp1_front, *mp1_rear, *mp2_front, *mp2_rear;
        mp1_front = mp1_rear = mp2_front = mp2_rear = NULL;
        inordertraversal(pre, root, mp1_front, mp1_rear, mp2_front, mp2_rear);
        if (mp2_front)
        	mp1_rear = mp2_rear;
        int t = mp1_front->val;
        mp1_front->val = mp1_rear->val;
        mp1_rear->val = t;
    }
    void inordertraversal(TreeNode *&pre, TreeNode *now, 
    	TreeNode *&mp1_front, TreeNode *&mp1_rear, TreeNode *&mp2_front, TreeNode *&mp2_rear){
    	if (!now)
    		return;
    	inordertraversal(pre, now->left, mp1_front, mp1_rear, mp2_front, mp2_rear);
    	if (pre) {
    		if (pre->val > now->val) {
    			if (!mp1_front){
    				mp1_front = pre;
    				mp1_rear = now;
    			}
    			else {
    				mp2_front = pre;
    				mp2_rear = now;
    			}
    		}
    	}
    	pre = now;
    	inordertraversal(pre, now->right, mp1_front, mp1_rear, mp2_front, mp2_rear);
    }
};
