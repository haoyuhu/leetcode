class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 1; i < nums.size(); ++i) {
        	for (int j = i - 1; j >= 0 && j > i - k; --j) {
        		if (abs(nums[i] - nums[j]) <= t) { return true; }
        	}
        }
        return false;
    }
};
//Time Limit Exceeded
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if (nums.empty()) return false;
        vector<int> order(nums.size());
        for (int i = 0; i != order.size(); ++i) {
        	order[i] = i;
        }
        //sort nums and orders
        sortNumbers(nums, order, 0, nums.size() - 1);
        //push and pop
        queue<int> numsque;
        queue<int> orderque;
        //initialize queue
        numsque.push(nums[0]);
        orderque.push(order[0]);

        for (int i = 1; i < nums.size();) {
        	if (numsque.empty()) {
        		numsque.push(nums[i]);
        		orderque.push(order[i]);
        		++i; continue;
        	}
        	int num = numsque.front();
        	int ord = orderque.front();
        	if (nums[i] > num + t) {
        		numsque.pop();
        		orderque.pop();

        	} else {
        		if (isOrderRangeSatisfactory(order[i], ord, k)) {
        			return true;
        		} else {
        			numsque.push(nums[i]);
        			orderque.push(order[i]);
        			++i;
        		}
        	}
        }

        int backOrder = orderque.back();
        int frontOrder = orderque.front();
        while (backOrder != frontOrder) {
        	if (isOrderRangeSatisfactory(backOrder, frontOrder, k)) {
        		break;
        	}
        	orderque.pop();
        	frontOrder = orderque.front();
        }
        if (backOrder == frontOrder) {
        	return false;
        } else {
        	return true;
        }
    }

    bool isOrderRangeSatisfactory(int i, int j, int k) {
    	return i <= j + k && i >= j - k;
    }

    void sortNumbers(vector<int> &nums, vector<int> &order, int bottom, int top) {
    	if (bottom >= top) return;
    	int i = bottom, j = top;
    	int saveValue = nums[i];
    	int saveIndex = order[i];
    	while (i < j) {
    		for (; i < j && nums[j] >= saveValue; --j);
    		nums[i] = nums[j];
    		order[i] = order[j];
    		for (; i < j && nums[i] <= saveValue; ++i);
    		nums[j] = nums[i];
    		order[j] = order[i];
    	}
    	nums[i] = saveValue;
    	order[i] = saveIndex;
    	sortNumbers(nums, order, bottom, i - 1);
    	sortNumbers(nums, order, i + 1, top);
    }
};
