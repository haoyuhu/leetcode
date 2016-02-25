class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i != nums.size(); ++i) {
        	if (nums[i] != 0) {
        		if (count) {
        			nums[i - count] = nums[i];
        		}
        	} else {
        		++count;
        	}
        }
        for (int i = nums.size() - 1; count; --count, --i) {
        	nums[i] = 0;
        }
    }
};