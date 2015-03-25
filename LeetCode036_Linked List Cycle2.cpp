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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast){
        	slow = slow->next;
        	if (fast->next){
        		fast = fast->next->next;
        	}
        	else fast = fast->next;
        	if (fast == slow){
        		break;
        	}
        }
        if (!fast) return NULL;
        slow = head;
        while (slow != fast){
        	slow = slow->next; fast = fast->next;
        }
        return slow;
    }
};