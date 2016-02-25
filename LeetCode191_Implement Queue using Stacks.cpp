class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        enter.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (exit.empty()) {
            while (!enter.empty()) {
                exit.push(enter.top());
                enter.pop();
            }
        }
        exit.pop();
    }

    // Get the front element.
    int peek(void) {
        if (exit.empty()) {
            while (!enter.empty()) {
                exit.push(enter.top());
                enter.pop();
            }
        }
        return exit.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return enter.empty() && exit.empty();
    }

private:
    stack<int> enter, exit;
};