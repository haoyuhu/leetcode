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
    #define MAXSIZE 1000000
	typedef struct Queue{
		TreeLinkNode *root[MAXSIZE];
		int front, rear;
    }Queue;
	bool EmptyQueue(Queue Q){
		if (Q.front == Q.rear){
			return true;
		}
		else{
			return false;
		}
	}
	void EnQueue(Queue &Q, TreeLinkNode *root){
		int tmp = (Q.rear + 1) % MAXSIZE - Q.front;
		if (!tmp){
			return;
		}
		else{
			Q.root[Q.rear] = root;
			Q.rear = (Q.rear + 1) % MAXSIZE;
		}
	}
	void DeQueue(Queue &Q, TreeLinkNode * &root){
		if (EmptyQueue(Q)){
			return;
		}
		else{
			root = Q.root[Q.front];
			Q.front = (Q.front + 1) % MAXSIZE;
		}
	}
	void connect(TreeLinkNode *root) {
        if (!root){
			return;
        }
		TreeLinkNode *p, *q = NULL;
		Queue Q;
		Q.front = Q.rear = 0;
		EnQueue(Q, root);
		EnQueue(Q, NULL);
		while (!EmptyQueue(Q)){
			DeQueue(Q, p);
			if (!p){
				if (EmptyQueue(Q)) break;
				EnQueue(Q, p); continue;
			}
			q = Q.root[Q.front];
			p->next = q;
			if (p->left){
				EnQueue(Q, p->left);
			}
			if (p->right){
				EnQueue(Q, p->right);
			}
		}
	}
};