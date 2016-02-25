class Solution {
public:
	int PENDING = 999999999;
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> answer;
        int cand1, cand2;
        int count1, count2;
        cand1 = cand2 = PENDING;
        count1 = count2 = 0;
        for (int i = 0; i != nums.size(); ++i) {
        	if (nums[i] == cand1) {
        		count1 += 1;
        	} else if (nums[i] == cand2) {
        		count2 += 1;
        	} else {
        		if (count1 && count2) {
        			--count1; --count2;
        		} else if (!count1) {
        			count1 = 1; cand1 = nums[i];
        		} else {
        			count2 = 1; cand2 = nums[i];
        		}
        	}
        }
        count1 = count2 = 0;
        for (int i = 0; i != nums.size(); ++i) {
        	if (nums[i] == cand1) {
        		count1 += 1;
        	}
        	if (nums[i] == cand2) {
        		count2 += 1;
        	}
        }
        if (count1 > nums.size() / 3) {
        	answer.push_back(cand1);
        }
        if (count2 > nums.size() / 3) {
        	answer.push_back(cand2);
        }
        return answer;
    }
};