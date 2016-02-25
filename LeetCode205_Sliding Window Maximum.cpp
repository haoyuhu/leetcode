class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size(), i;
        deque<int> maxque, index;
        vector<int> answer;

        for (i = 0; i != size;) {
        	int rear;
        	if (maxque.empty()) {
        		maxque.push_back(nums[i]);
        		index.push_back(i);
        		
        		int low = index.front(), high = index.back();
        		if (high - low + 1 > k) {
        			maxque.pop_front(); index.pop_front();
        		}
        		if (i >= k - 1) {
        			answer.push_back(maxque.front());
        		}
        		++i; continue;
        	} else {
        		rear = maxque.back();
        	}
        	if (rear < nums[i]) {
        		maxque.pop_back();
        		index.pop_back();
        	} else {
        		maxque.push_back(nums[i]);
        		index.push_back(i);
        		
        		int low = index.front(), high = index.back();
        		if (high - low + 1> k) {
        			maxque.pop_front(); index.pop_front();
        		}

        		if (i >= k - 1) {
        			answer.push_back(maxque.front());
        		}
        		++i;
        	}
        }

        return answer;
    }
};