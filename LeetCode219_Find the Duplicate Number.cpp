class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i != length; ++i) {
        	int value = abs(nums[i]);
        	if (nums[value - 1] < 0) {
        		reset(nums);
        		return value;
        	} else {
        		nums[value - 1] *= -1;
        	}
        }
    }
private:
	void reset(vector<int> &nums) {
		for (int i = 0; i != nums.size(); ++i) {
			nums[i] = abs(nums[i]);
		}
	}
};