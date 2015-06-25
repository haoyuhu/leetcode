class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = tail = NULL;
    }
    
    int get(int key) {
        unordered_map<int, pair<int, DoubleLinkedNode*>>::iterator storeIterator = store.find(key);
        int value = -1;
        if (storeIterator != store.end()) {
        	value = (storeIterator->second).first;
        	eraseItem((storeIterator->second).second);
        	(storeIterator->second).second = push(key);
        }
        return value;
    }
    
    void set(int key, int value) {
        unordered_map<int, pair<int, DoubleLinkedNode*>>::iterator storeIterator = store.find(key);
        if (storeIterator != store.end()) {
        	(storeIterator->second).first = value;
        	get(key);
        	return;
        }
        if (getSize() == capacity) {
        	int oldKey = pop();
        	storeIterator = store.find(oldKey);
        	if (storeIterator != store.end()) {
        		store.erase(storeIterator);
        	}
        }
        store.insert(make_pair(key, make_pair(value, push(key))));
    }

private:

	struct DoubleLinkedNode {
		DoubleLinkedNode * previous;
		DoubleLinkedNode * next;
		int key;

		DoubleLinkedNode(): previous(NULL), next(NULL), key(0) {}
		};

	int capacity;
	int size;
	DoubleLinkedNode * head;
	DoubleLinkedNode * tail;
	unordered_map<int, pair<int, DoubleLinkedNode *>> store;

	int eraseItem(DoubleLinkedNode * current) {
		DoubleLinkedNode *pre = current->previous, *suc = current->next;
		int key = current->key;
		if (current == head) {
			head = suc;
		}
		if (current == tail) {
			tail = pre;
		}
		if (pre) {
			pre->next = suc;
		}
		if (suc) {
			suc->previous = pre;
		}
		delete current;
		current = NULL;
		--size;
		return key;
	}

	DoubleLinkedNode * push(int key) {
		DoubleLinkedNode * current = new DoubleLinkedNode();
		current->key = key;
		++size;
		if (tail) {
			tail->next = current;
			current->previous = tail;
			tail = current;
		} else {
			tail = head = current;
		}
		return current;
	}

	int pop() {
		DoubleLinkedNode *suc = head->next;
		int key = eraseItem(head);
		head = suc;
		if (head) {
			head->previous = NULL;
		} else {
			tail = NULL;
		}
		return key;
	}

	int getSize() {
		return size;
	}

};
