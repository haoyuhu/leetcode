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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
        	return head;
        ListNode *front, *rear;
        int cnt = 0;
        if (m != 1) {
        	front = head;
        	for (; cnt != m - 2; ++cnt)
        		front = front->next;
        }
        else
        	front = NULL;
        if (front)
        	rear = front;
        else
        	rear = head;
        for (; cnt != n - 2; ++cnt)
        	rear = rear->next;
        if (front) {
        	if (m + 1 < n) {
        		ListNode *pm = front->next, *pn = rear->next, *t = pm->next;
        		front->next = pn;
        		pm->next = pn->next;
        		pn->next = t;
        		rear->next = pm;
        	}
        	else {
        		front->next = rear->next;
        		rear->next = front->next->next;
        		front->next->next = rear;
        	}
        }
        else {
        	if (m + 1 < n) {
        		ListNode *t = head->next, *pn = rear->next;
        		head->next = pn->next;
        		pn->next = t;
        		rear->next = head;
        		head = pn;
        	}
        	else {
        		ListNode *pn = rear->next;
        		rear->next = pn->next;
        		pn->next = rear;
        		head = pn;
        	}
        }
        return head;
    }
};
//
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
        	return head;
        stack<ListNode*> liststack;
        ListNode *front = m != 1 ? head : NULL, *rear;
        int cnt = 0;
        for (; cnt < m - 2; ++cnt)
        	front = front->next;
        if (front)
        	rear = front->next;
        else
        	rear = head;
        for (cnt = 0; cnt != n - m + 1; ++cnt) {
        	liststack.push(rear);
        	rear = rear->next;
        }
        ListNode *pre, *suc;
        suc = liststack.top();
        while (!liststack.empty()) {
        	ListNode *t;
        	pre = liststack.top();
        	liststack.pop();
        	if (!liststack.empty()) {
        		t = liststack.top();
        		pre->next = t;
        	}
        }
        if (front)
        	front->next = suc;
        else
        	head = suc;
        pre->next = rear;
        return head;
    }
};