class MinStack {
public:
    void push(int x) {
        minstk.push_back(x);
        if (min_index == -1 || minstk[min_index] > x)
            min_index = minstk.size() - 1;
    }

    void pop() {
        minstk.pop_back();
        if (minstk.size()) {
            int minval = MAX_INT;
            for (int i = 0; i != minstk.size(); ++i) {
                if (minstk[i] < minval) {
                    minval = minstk[i];
                    min_index = i;
                }
            }
        }
        else
            min_index = -1;
    }

    int top() {
        return minstk.back();
    }

    int getMin() {
        return minstk[min_index];
    }
    MinStack(): min_index(-1) {}
private:
    vector<int> minstk;
    int min_index;
};//Memory Limit Exceeded
struct minStkNode {
    int count, curmin;
    minStkNode(int min): count(1), curmin(min) {}
};
class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (minstk.empty())
            minstk.push(minStkNode(x));
        else {
            auto &minval = minstk.top();
            if (minval.curmin > x)
                minstk.push(minStkNode(x));
            else if (minval.curmin == x)
                ++minval.count;
        }
    }

    void pop() {
        int cur = stk.top(); stk.pop();
        auto &minval = minstk.top();
        if (cur == minval.curmin && --minval.count == 0)
            minstk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top().curmin;
    }
private:
    stack<int> stk;
    stack<minStkNode> minstk;
};//AC
