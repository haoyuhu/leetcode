class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> save;
        for (int i = 0; i != nums.size(); ++i) {
        	unordered_map<int, int>::iterator it = save.find(nums[i]);
        	if (it != save.end()) {
        		int& index = it->second;
        		if (i - index <= k) { return true; }
        		index = i;
        	} else {
        		save.insert(make_pair(nums[i], i));
        	}
        }
        return false;
    }
};