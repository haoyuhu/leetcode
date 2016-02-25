class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        	return false;
        vector<int> counter(26, 0);
        for (char ch : s) {
        	counter[ch - 'a'] += 1;
        }
        for (char ch : t) {
        	if ((counter[ch - 'a'] -= 1) < 0) {
        		return false;
        	}
        }
        return true;
    }
};