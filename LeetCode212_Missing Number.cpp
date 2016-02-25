class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i != nums.size(); ++i) {
        	int current = i;
        	bool isFirst = true;
        	while (current != nums.size() && nums[current] != current) {
        		if (isFirst) {
        		    current = nums[current];
        		    isFirst = false;
        		}
        		if (current != nums.size()) {
        			int save = nums[current];
        			nums[current] = current;
        			current = save;
        		} else {
        			break;
        		}
        	}
        }
        for (int i = 0; i != nums.size(); ++i) {
        	if (nums[i] != i) {
        		return i;
        	}
        }
        return nums.size();
    }
};