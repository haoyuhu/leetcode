class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int length = s.size();
        bool tag[length+1];
        tag[0] = true;
        for (int i = 1; i <= length; ++i){
        	tag[i] = false;
        	for (int j = 0; j != i; ++j){
        		if (tag[j] && indict(string(s, j, i - j), dict)) {
        			tag[i] = true;
        			break;
        		}
        	}
        }
        return tag[length];
    }
    bool indict(string s, unordered_set<string> &dict) {
    	unordered_set<string>::iterator it = find(dict.begin(), dict.end(), s);
    	return it != dict.end();
    }
};