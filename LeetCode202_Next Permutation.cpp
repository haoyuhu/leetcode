class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int MAX_INT = 999999999;
    	int size = nums.size(), i;
    	for (i = size - 1; i > 0 && nums[i] <= nums[i-1]; --i);
    	if (i == 0) {
	    	reverse(nums.begin(), nums.end());
	    	return;
	    }
    	int front = nums[i-1], min = MAX_INT, index, j;
	    for (j = i; j < size; ++j) {
	    	if (nums[j] > front && nums[j] < min) {
	    		min = nums[j];
	    		index = j;
	    	}
	    }
	    if (min == MAX_INT) {
	    	for (j = i; j != size; ++j) {
	    		if (nums[j] >= front && nums[j] < min) {
	    			min = nums[j];
	    			index = j;
	    		}
	    	}
	    }
	    nums[i-1] = min;
	    nums[index] = front;
	    sort(nums.begin() + i, nums.end());
    }
};