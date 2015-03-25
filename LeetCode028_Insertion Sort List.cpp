/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head){
        	ListNode *p, *psave, *puse;
        	for (puse = head; puse->next;){
        		p = head;
        		if (p->val > puse->next->val){
        			psave = puse->next; puse->next = psave->next;
        			psave->next = head; head = psave;
        		}
        		else {
        			while (p->next->val < puse->next->val){
        				p = p->next;
        			}
        			if (p != puse){
        				psave = puse->next; puse->next = psave->next;
        				psave->next = p->next;
        				p->next = psave;
        			}
        			else puse = puse->next;
        		}
        	}
        }
        return head;
    }
};
//////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head){
        	ListNode *p, *q;
        	int tp1, tp2, tp3;
        	for (p = head->next; p; p = p->next){
        		q = head;
        		while (q->val < p->val){
        			q = q->next;
        		}
        		if (q != p){
        			ListNode *qsave = q;
                    tp1 = p->val; tp2 = q->val; tp3 = q->next->val;
        			for (; q != p; q = q->next, tp3 = q->next->val){
        				q->next->val = tp2;
                        tp2 = tp3;
        			}
        			qsave->val = tp1;
        		}
        	}
        }
        return head;
    }
};// this method is worse than the first one;