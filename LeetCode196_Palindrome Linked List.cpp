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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* current = head, *reverse = NULL;
        while (current) {
        	current = current->next;
        	++count;
        }
        int halfLength = count / 2;
        bool isEven = count % 2 == 0;
        for (int i = 0; i != halfLength; ++i) {
        	current = head;
        	head = current->next;
        	current->next = reverse;
        	reverse = current;
        }
        if (!isEven) {
        	head = head->next;
        }
        while (reverse && head) {
        	if (reverse->val != head->val) {
        		return false;
        	} else {
        		reverse = reverse->next;
        		head = head->next;
        	}
        }
        return true;
    }
};