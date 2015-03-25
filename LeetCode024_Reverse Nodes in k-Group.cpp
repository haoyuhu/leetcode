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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1 || !head){
        	return head;
        }
        ListNode *p = head, *q, *r = NULL;
        while (1){
        	int ct;
        	q = p;
            ListNode *psave = q;
        	for (ct = 0; ct < k && p; p = p->next, ++ct);
        	if (ct == k){
        		ListNode *quse = q->next, *qsave;
        		q->next = p;
        		qsave = quse->next;
        		while (quse != p){
        			 quse->next = q;
                     if (r){
                        r->next = quse;
        			 }
                     else head = quse;
        			 q = quse;
        			 quse = qsave;
                     if (quse){
                         qsave = quse->next;
                     }
        		}
        	}
        	else return head;
            r = psave;
        }
    }
};