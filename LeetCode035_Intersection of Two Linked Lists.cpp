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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ctA = 0, ctB = 0, gap;
        ListNode *pa = headA, *pb = headB;
        if (headA && headB){
        	while (pa){
        		pa = pa->next; ++ctA;
        	}
        	while (pb){
        		pb = pb->next; ++ctB;
        	}
        	if (ctA > ctB){
        		pa = headA; pb = headB;
        		for (gap = ctA - ctB; gap > 0; --gap){
        			pa = pa->next;
        		}
        	}
        	else {
        		pb = headB; pa = headA;
        		for (gap = ctB - ctA; gap > 0; --gap){
        			pb = pb->next;
        		}
        	}
        	while (pa && pb){
        		if (pa == pb){
        			return pa;
        		}
        		else {
        			pa = pa->next; pb = pb->next;
        		}
        	}
        }
        return NULL;
    }
};