class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > match;
        unordered_map<string, vector<string> >::iterator matchit;
        vector<string> answer;
        for (int i = 0; i != strs.size(); ++i) {
        	string str(strs[i]);
        	sort(str.begin(), str.end());
        	matchit = match.find(str);
        	if (matchit != match.end())
        		matchit->second.push_back(strs[i]);
        	else
        		match.insert(make_pair(str, vector<string>{strs[i]}));
        }
        for (matchit = match.begin(); matchit != match.end(); ++matchit) {
        	if (matchit->second.size() > 1)
        		merge(answer, matchit->second);
        }
        return answer;
    }
    void merge(vector<string> &answer, const vector<string> &matched) {
    	for (int i = 0; i != matched.size(); ++i)
    		answer.push_back(matched[i]);
    }
};