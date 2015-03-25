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
    ListNode *sortList(ListNode *head) {
        if (!head)
        	return head;
        ListNode *beg = head, *end;
        for (end = head; end->next; end = end->next);
        qsort_list(beg, end);
    	head = beg; end->next = NULL;
    	return head;
    }
    void qsort_list(ListNode *&beg, ListNode *&end) {
    	if (beg == end)
    		return;
        ListNode *deal = beg;
        bool isfinished = true;
        while (deal && deal->next) {
            if (deal->val > deal->next->val) {
                isfinished = false; break;
            }
            deal = deal->next;
        }
        if (isfinished)
            return;
    	int save = beg->val;
    	ListNode *p = beg->next, *left, *left_sv, *right, *right_sv;
    	beg->next = left = right = left_sv = right_sv = NULL;
    	while (p){
    		ListNode *nxt = p->next;
    		p->next = NULL;
    		if (p->val <= save) {
    			if (!left)
    				left = p;
    			else
    				left_sv->next = p;
    			left_sv = p;
    			p = nxt;
    		}
    		else {
    			if (!right)
    				right = p;
    			else
    				right_sv->next = p;
    			right_sv = p;
    			p = nxt;
    		}
    	}
        qsort_list(left, left_sv);
        qsort_list(right, right_sv);
/*        bool left_finish, right_finish;
        left_finish = right_finish = true;
        ListNode *tl = left, *tr = right;
        while (tl && tl->next){
            if (tl->val > tl->next->val) {
                left_finish = false; break;
            }
        }
        while (tr && tr->next) {
            if (tr->val > tr->next->val) {
                right_finish = false; break;
            }
        }
        if (!left_finish)
    	   qsort_list(left, left_sv);
    	if (!right_finish)
            qsort_list(right, right_sv);*/
    	p = beg;
    	if (left) {
    		left_sv->next = p;
    		beg = left;
    	}
    	if (right) {
    		p->next = right;
    		end = right_sv;
    	}
    	else
    		end = p;
    }
};