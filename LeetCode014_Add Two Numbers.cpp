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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (!l1){
			return l2;
		}
		if (!l2){
			return l1;
		}
		ListNode *p = l1, *q = l2;
		ListNode *head = NULL, *tmp = head;
		while (p && q){
			ListNode *t = (ListNode *)malloc(sizeof(ListNode));
			t->val = p->val + q->val;
			t->next = NULL;
			if (!head){
				head = t;
				tmp = t;
			}
			else{
				tmp->next = t;
				tmp = t;
			}
			p = p->next;
			q = q->next;
		}
		if (p){
			tmp->next = p;
		}
		if (q){
			tmp->next = q;
		}
		ListNode *puse = head;
		int t1 = 0, t2 = 0;
		while (puse){
			t1 = (puse->val + t2) % 10;
			t2 = (puse->val + t2) / 10;
			puse->val = t1;
			puse = puse->next;
		}
		if (t2){
			puse = head;
			while (puse->next){
				puse = puse->next;
			}
			ListNode *t = (ListNode *)malloc(sizeof(ListNode));
			t->val = t2;
			t->next = NULL;
			puse->next = t;
		}
		return head;
    }
};