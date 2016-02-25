class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
        	if (set.find(num) == set.end()) {
        		set.insert(num);
        	} else {
        		set.erase(num);
        	}
        }
        vector<int> answer;
        for (unordered_set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        	answer.push_back(*it);
        }
        return answer;
    }
};