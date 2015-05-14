//O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        int bottom = 0, top = -1;
        int sum = 0, len = 0;
        while (true) {
        	if (sum < s) {
        		++top;
        		if (top != nums.size())
        			sum += nums[top];
        		else
        			break;
        	} else {
        		sum -= nums[bottom]; ++bottom;
        		if (bottom > top)
        			break;
        	}
        	if (sum >= s) {
        		int new_len = top - bottom + 1;
        		if (!len || len && new_len < len)
        			len = new_len;
        	}
        }
        return len;
    }
};

//O(nlogn)
class Solution {
public:
    int MAX_INT = 999999999;
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        return findMinLen(s, nums, 0, nums.size() - 1);
    }
    int findMinLen(int s, vector<int>& nums, int bottom, int top) {
        if (top == bottom) return nums[top] >= s ? 1 : 0;
        int mid = (bottom + top) / 2;
        int left = mid, right = mid + 1, sum = 0, len;
        while (sum < s && (right <= top || left >= bottom)) {
            if  (right > top) {
                sum += nums[left]; --left;
            }
            else if (left < bottom) {
                sum += nums[right]; ++right;
            }
            else if (nums[left] > nums[right]) {
                sum += nums[left]; --left;
            }
            else {
                sum += nums[right]; ++right;
            }
        }
        if (sum >= s) {
            len = right - left - 1;
            int leftLen = findMinLen(s, nums, bottom, mid);
            int rightLen = findMinLen(s, nums, mid + 1, top);
            return minValue(leftLen, rightLen, len);
        }
        else {
            return 0;
        }
    }
    int minValue(int x, int y, int z) {
        if (!x) x = MAX_INT;
        if (!y) y = MAX_INT;
        if (x <= y && x <= z) return x;
        if (y <= x && y <= z) return y;
        return z;
    }
};