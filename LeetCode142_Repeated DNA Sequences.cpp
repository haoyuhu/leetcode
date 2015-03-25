class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> answer;
        unordered_set<string> repeated;
        for (int i = 0; i + 9 < s.size(); ++i) {
        	string t(s, i, 10);
        	unordered_set<string>::iterator it = repeated.find(t);
        	if (it != repeated.end())
        		answer.push_back(t);
        	else
        		repeated.insert(t);
        }
        return answer;
    }
};//memory limit exceeded
//
class Solution {
public:
	#define eraser 0x3ffff
	vector<string> findRepeatedDnaSequences(string s) {
	    vector<string> answer;
	    int hint = 0;
	    if (s.size() < 10)
	    	return answer;
	    unordered_set<unsigned int> repeated, check;
	    unordered_map<char, unsigned int> ati{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
	    for (int i = 0; i != 10; ++i) {
	    	hint = (hint << 2) + ati[s[i]];
	    }
	    repeated.insert(hint);
	    for (int i = 10; i != s.size(); ++i) {
	    	hint = ((hint & eraser) << 2) + ati[s[i]];
	    	unordered_set<unsigned int>::iterator it = repeated.find(hint);
	    	if (it != repeated.end()) {
	    		it = check.find(hint);
	    		if (it == check.end()) {
	    			answer.push_back(string(s, i - 9, 10));
	    			check.insert(hint);
	    		}
	    	}
	    	else
	    		repeated.insert(hint);
	    }
	    return answer;
	}
};