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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next){
			return head;
        }
		ListNode *p = head;
		int n = 0, tmp;
		while (p){
			p = p->next;
			++n;
		}
		tmp = k % n;
		if (tmp){
			p = head;
			for (int i = 1; i <= n - tmp - 1; ++i){
				p = p->next;
			}
			ListNode *q = p->next;
			ListNode *psave = p;
			while (p->next){
				p = p->next;
			}
			p->next = head;
			head = q;
			psave->next = NULL;
		}
		return head;
    }
};