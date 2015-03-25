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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
        	return head;
    	ListNode *front, *pre, *suc, *rear;
    	front = NULL; pre = head;
    	while (pre){
    		if (pre->next)
    			suc = pre->next;
    		else
    			break;
    		rear = suc->next;
    		pre->next = rear;
    		suc->next = pre;
    		if (!front)
    			head = suc;
    		else
    			front->next = suc;
    		front = pre; pre = rear;
    	}
    	return head;
    }
};