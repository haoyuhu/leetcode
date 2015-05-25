class Solution {
public:
    string shortestPalindrome(string s) {
    	if (s.empty()) return s;
        string reverse_s(s);
        reverse(reverse_s.begin(), reverse_s.end());
        int mark;
        vector<int> next(s.size());
        makeNext(s, next);

        for (int i = 0, j = 0; i < reverse_s.size(); ) {
        	if (j == -1 || reverse_s[i] == s[j]) {
        		++i; ++j;
        		if (i == reverse_s.size()) {
        			mark = j;
        		}
        	} else {
        		j = next[j];
        	}
        }

        return mark == s.size() ? reverse_s : reverse_s + s.substr(mark);
    }

    void makeNext(string& s, vector<int>& next) {
    	next[0] = -1;
    	for (int i = 0, j = -1; i < s.size(); ) {
    		if (j == -1 || s[i] == s[j]) {
    			++i; ++j;
    			if (i != s.size()) {
    				if (s[i] == s[j]) {
    					next[i] = next[j];
    				} else {
    					next[i] = j;
    				}
    			}
    		} else {
    			j = next[j];
    		}
    	}
    }
};