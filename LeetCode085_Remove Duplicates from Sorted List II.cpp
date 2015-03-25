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
    ListNode *deleteDuplicates(ListNode *head) {
    	if (!head || !head->next)
    		return head;
    	ListNode *now = (ListNode*)malloc(sizeof(ListNode));
    	now->next = head; head = now;
    	ListNode *pre = head, *suc;
    	bool tag = false;
    	now = head->next;
    	while (now){
    		suc = now->next;
    		if (!suc && !tag)
    			break;
    		if (!suc && tag) {
    			pre->next = NULL;
    			free(now); break;
    		}
    		if (suc->val != now->val && !tag) {
    			pre = now; now = now->next;
    			continue;
    		}
    		if (suc->val != now->val && tag) {
    			pre->next = suc;
    			free(now);
    			tag = false;
    			now = suc;
    			continue;
    		}
    		if (suc->val == now->val) {
    			tag = true;
    			pre->next = suc; free(now);
    			now = suc;
    		}
    	}
    	now = head;
    	head = now->next;
    	free(now);
    	return head;
    }
};