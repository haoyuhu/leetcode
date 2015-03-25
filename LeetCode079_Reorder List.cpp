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
    void reorderList(ListNode *head) {
        int cnt = 0;
        ListNode *p = head;
        while (p){
        	p = p->next;
        	++cnt;
        }
        if (!cnt || cnt == 1 || cnt == 2)
        	return;
        stack<ListNode*> pstk;
        p = head;
        for (int i = 0; i != cnt / 2 - 1; ++i)
        	p = p->next;
        ListNode *save, *pre;
        pre = p->next;
       	p->next = NULL; p = pre;
        while (p){
        	pstk.push(p);
        	p = p->next;
        }
        p = head;
        
        while (!pstk.empty()){
        	save = pstk.top();
        	pre = p->next; p->next = save;
        	pstk.pop();
        	if (pre) {
        		save->next = pre;
        		p = pre;
        	}
        	else {
        		if (!pstk.empty()) {
        			pre = pstk.top();
        			save->next = pre;
        			pre->next = NULL;
        			pstk.pop();
        		}
        		else
        			save->next = NULL;
        	}
        }
    }
};