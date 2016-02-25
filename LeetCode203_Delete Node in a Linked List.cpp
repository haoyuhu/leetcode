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
    void deleteNode(ListNode* node) {
        ListNode* rear, *front;
        while (rear = node->next) {
        	node->val = rear->val;
        	front = node;
        	node = rear;
        }
        front->next = NULL;
        delete node;
    }
};