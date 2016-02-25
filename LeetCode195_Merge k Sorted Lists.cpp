/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Heap {
public:
	Heap(vector<ListNode*>& lists) {
		for (int i = 0; i != lists.size(); ++i) {
			if (lists[i]) {
				push(lists[i], i);
				lists[i] = lists[i]->next;
			}
		}
		// for (int i = heap.size() - 1; i >= 0; --i) {
		// 	adjustDown(i);
		// }
	}
	int size() {
		return heap.size();
	}
	bool empty() {
		return heap.empty() && indexHeap.empty();
	}
	void push(ListNode* pointer, int index) {
		heap.push_back(pointer);
		indexHeap.push_back(index);
		adjustUp(heap.size() - 1);
	}
	int pop() {
		int index = indexHeap.front();
		heap.front() = heap.back();
		indexHeap.front() = indexHeap.back();
		heap.pop_back();
		indexHeap.pop_back();
		adjustDown(0);
		return index;
	}
	ListNode* front() {
		return heap.front();
	}
private:
	vector<ListNode*> heap;
	vector<int> indexHeap;
	void adjustDown(int index) {
		if (heap.empty()) {
			return;
		}
		ListNode* save = heap[index];
		int saveIndex = indexHeap[index];
		for (int s = index * 2 + 1; s < heap.size(); s = s * 2 + 1) {
			if (s + 1 < heap.size() && heap[s]->val > heap[s+1]->val) {
				s += 1;
			}
			if (heap[s]->val < save->val) {
				heap[index] = heap[s];
				indexHeap[index] = indexHeap[s];
				index = s;
			} else {
				break;
			}
		}
		heap[index] = save;
		indexHeap[index] = saveIndex;
	}
	void adjustUp(int index) {
		ListNode* save = heap[index];
		int saveIndex = indexHeap[index];
		for (int s = (index - 1) / 2; s >= 0 && s != index; s = (s - 1) / 2) {
			if (heap[s]->val > save->val) {
				heap[index] = heap[s];
				indexHeap[index] = indexHeap[s];
				index = s;
			} else {
				break;
			}
		}
		heap[index] = save;
		indexHeap[index] = saveIndex;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = NULL, *current;
        Heap heap(lists);
        while (!heap.empty()) {
        	if (root) {
        		current->next = heap.front();
        		current = current->next;
        	} else {
        		root = current = heap.front();
        	}
        	int index = heap.pop();
        	if (lists[index]) {
        		heap.push(lists[index], index);
        		lists[index] = lists[index]->next;
        	}
        }
        return root;
    }
};
