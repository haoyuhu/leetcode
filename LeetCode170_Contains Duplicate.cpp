class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for (int num : nums) {
            if (check.find(num) != check.end()) {
                return true;
            } else {
                check.insert(num);
            }
        }
        return false;
    }
};