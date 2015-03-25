class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if (!length)
        	return 0;
        int count[length];
        count[0] = 1;
        for (int i = 1; i != length; ++i){
        	count[i] = 0;
        	int cnt = 0;
        	for (int j = i - 1; j >= i - count[i-1] && s[j] != s[i]; --j, ++cnt);
        	count[i] = cnt + 1;
        }
        int max = 0;
        for (int i = 0; i != length; ++i){
        	if (max < count[i])
        		max = count[i];
        }
        return max;
    }
};