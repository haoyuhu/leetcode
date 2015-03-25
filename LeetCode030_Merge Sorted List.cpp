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
    typedef enum { L1, L2 }ListType;
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *p, *q, *save;
        ListType tag;
        if (l1->val < l2->val){
        	p = l1; q = l2; tag = L1;
        }
        else {
        	p = l2; q = l1; tag = L2;
        }
        while (p->next && q){
        	if (p->next->val > q->val){
        		save = q->next;
        		q->next = p->next; p->next = q;
        		q = save;
        	}
        	p = p->next;
        }
        if (q){
        	p->next = q;
        }
        if (tag == L1) return l1;
        else return l2;
    }
};