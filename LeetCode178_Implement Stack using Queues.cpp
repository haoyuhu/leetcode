class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = queue.size();
        if (size == 0) {
            return;
        }
        for (int i = 0; i != size - 1; ++i) {
            int x = queue.front();
            queue.erase(queue.begin());
            queue.push_back(x);
        }
        queue.erase(queue.begin());
    }

    // Get the top element.
    int top() {
        return queue.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue.empty();
    }
private:
    vector<int> queue;
};