class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        if (nums.empty()) {
        	return answer;
        }
        int start = nums[0];
        for (int i = 0; i != nums.size(); ++i) {
        	if (i + 1 >= nums.size() || nums[i+1] != nums[i] + 1) {
        		if (start != nums[i]) {
        			string interval(toString(start) + "->" + toString(nums[i]));
        			answer.push_back(interval);
        		} else {
        			answer.push_back(toString(start));
        		}
        		if (i + 1 < nums.size()) {
        			start = nums[i+1];
        		}
        	}
        }
        return answer;
    }
    string toString(int i) {
    	string str;
    	if (i == -2147483648) {
    		return string("-2147483648");
    	}
    	bool isNegative = i < 0;
    	i = abs(i);
    	do {
    		str.push_back(toChar(i % 10));
    	} while (i /= 10);
    	if (isNegative) {
    		str.push_back('-');
    	}
    	reverse(str.begin(), str.end());
    	return str;
    }
    char toChar(int i) {
    	return '0' + i;
    }
};