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
        if (head && head->next){
            ListNode * p = head;
            ListNode * q = NULL;
            while (p->next){
                q = p->next;
                if (p->val == q->val){
                    p->next = q->next;
                    free(q);
                }
                else
                    p = p->next;
            }
            q = NULL;
        }
        return head;
    }
};
