class Solution {
public:
	int answer;
    int findKthLargest(vector<int>& nums, int k) {
        find(nums, 0, nums.size() - 1, k);
        return answer;
    }

    void find(vector<int>& nums, int bottom, int top, int k) {
    	int i = bottom, j = top, save = nums[bottom];
    	while (i < j) {
    		for (; i < j && nums[j] <= save; --j);
    		nums[i] = nums[j];
    		for (; i < j && nums[i] >= save; ++i);
    		nums[j] = nums[i];
    	}

    	int rank = j - bottom + 1;
    	if (rank == k) {
    		answer = save; return;
    	}
    	if (rank > k) {
    		find(nums, bottom, j - 1, k);
    	} else {
    		find(nums, j + 1, top, k - rank);
    	}
    }
};