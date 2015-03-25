/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head){
			return NULL;
        }
		RandomListNode *p = head, *q;
		while (p){
			q = (RandomListNode *)malloc(sizeof(RandomListNode));
			q->label = p->label;
			q->next = p->next; p->next = q;
			p = q->next;
		}
		p = head;
		while (p){
			q = p->next;
			if (!p->random){
				q->random = NULL;
			}
			else{
				q->random = p->random->next;
			}
			p = q->next;
		}
		RandomListNode *cpyhead;
		p = head;
		cpyhead = p->next;
		while (p){
			q = p->next;
			p->next = q->next;
			p = p->next;
			if (p){
				q->next = p->next;
			}
			else{
				q->next = NULL;
			}
		}
		return cpyhead;
    }
};