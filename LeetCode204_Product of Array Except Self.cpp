class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front(nums.size()), rear(nums.size()), answer(nums.size());
        front[0] = rear[nums.size()-1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
        	front[i] = front[i-1] * nums[i-1];
        	rear[nums.size()-i-1] = rear[nums.size()-i] * nums[nums.size()-i];
        }
        for (int i = 0; i != nums.size(); ++i) {
        	answer[i] = front[i] * rear[i];
        }
        return answer;
    }
};