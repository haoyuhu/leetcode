class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int length = s.size();
        bool tag[length+1];
        tag[0] = true;
        vector< vector<int> > split_save(length + 1);
        for (int i = 1; i <= length; ++i){
        	tag[i] = false;
        	for (int j = 0; j != i; ++j){
        		if (tag[j] && indict(string(s, j, i - j), dict)) {
        			tag[i] = true;
        			split_save[i].push_back(j);
        		}
        	}
        }
        vector<string> svec;
        if (tag[length]) {
            svec.push_back(string());
            create_answer(svec, 0, split_save, length, s);
        }
        return svec;
    }
    void create_answer(vector<string> &svec, int i, 
        const vector< vector<int> > &save, int now, string s){
        if (!now)
            return;
        int len = save[now].size();
        string st(svec[i]);
        for (int k = 0; k != len; ++k){
            if (!k) {
                if (svec[i].empty())
                    svec[i] += string(s, save[now][k], now - save[now][k]);
                else
                    svec[i] = string(s, save[now][k], now - save[now][k]) + " " +svec[i];
                create_answer(svec, i, save, save[now][k], s);
            }
            else {
                svec.push_back(st);
                int index = svec.size() - 1;
                if (svec[index].empty())
                    svec[index] += string(s, save[now][k], now - save[now][k]);
                else
                    svec[index] = string(s, save[now][k], now - save[now][k]) + " " + svec[index];
                create_answer(svec, index, save, save[now][k], s);
            }
        }
    }
    bool indict(string s, unordered_set<string> &dict) {
    	unordered_set<string>::iterator it = find(dict.begin(), dict.end(), s);
    	return it != dict.end();
    }
};