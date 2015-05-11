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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr, *save = NULL;
        curr = head;
        while (curr) {
        	if (curr->val == val) {
        		if (curr == head) {
        			head = curr->next;
        			delete curr;
        			curr = head;
        		}
        		else {
        			save->next = curr->next;
        			delete curr;
        			curr = save->next;
        		}
        	}
        	else {
        		save = curr;
        		curr = curr->next;
        	}
        }
        return head;
    }
};