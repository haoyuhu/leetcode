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
    bool hasCycle(ListNode *head) {
        if (!head){
			return true;
        }
		Lnode *p = head;
		Lnode *puse = head;
		while (p){
			if (p->next == p){
				return false;
			}
			while (puse != p){
				if (puse == p->next){
					return false;
				}
				puse = puse->next;
			}
			puse = head;
			p = p->next;
		}
		return true;
    }
};
////////////////////////////////////////////////////////
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *pfast, *pslow;
		if (!head){
			return false;
		}
		pfast = head->next; pslow = head;
		while (pfast && pfast != pslow){
			if (pfast->next){
				pfast = pfast->next->next;
			}
			else{
				pfast = pfast->next;
			}
			pslow = pslow->next;
		}
		if (!pfast){
			return false;
		}
		else{
			return true;
		}
    }
};