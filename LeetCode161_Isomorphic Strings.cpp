class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	unordered_map<char, char> match;
    	unordered_set<char> occupy;
    	for (int i = 0; i != s.size(); ++i) {
    		unordered_map<char, char>::iterator it = match.find(s[i]);
    		if (it == match.end()) {
    			if (occupy.find(t[i]) == occupy.end()) {
    				match.insert(make_pair(s[i], t[i]));
    				occupy.insert(t[i]);
    			}
    			else
    				return false;
    		}
    		else {
    			if (it->second != t[i]) return false;
    		}
    	}
    	return true;
    }
};