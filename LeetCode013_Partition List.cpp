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
    ListNode *partition(ListNode *head, int x) {
        if (!head){
			return head;
        }
		ListNode *p = (ListNode *)malloc(sizeof(ListNode));
		p->next = head->next;
		head->next = p;
		p->val = head->val;
		ListNode *headsave = (ListNode *)malloc(sizeof(ListNode));
		headsave->next = NULL;
		ListNode *q, *psave;
		p = head;
		psave = headsave;
		while (p->next){
			if (p->next->val >= x){
				q = p->next;
				p->next = q->next;
				q->next = NULL;
				psave->next = q;
				psave = q;
			}
			else{
				p = p->next;
			}
		}
		p->next = headsave->next;
		free(headsave);
		head->val = head->next->val;
		q = head->next;
		head->next = q->next;
		free(q);
		return head;
    }
};
