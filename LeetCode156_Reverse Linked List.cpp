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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *curr = head->next, *suc = NULL;
        head->next = NULL;
        while (curr) {
        	suc = curr->next;
        	curr->next = head;
        	head = curr;
        	curr = suc;
        }
        return head;
    }
};