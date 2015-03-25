class Solution {
public:
	#define MAX_INT 999999999
    string longestCommonPrefix(vector<string> &strs) {
        int num = strs.size(), minlen = MAX_INT, cnt = 0;
        string answer;
        bool tag = true;
        if (!num)
        	return answer;
        for (int i = 0; i != num; ++i)
        	minlen = min_val(minlen, strs[i].size());
        for (int i = 0; i != minlen; ++i){
        	char ch = strs[0][i];
        	for (int j = 1; j != num; ++j){
        		if (ch != strs[j][i])
        			tag = false;
        	}
        	if (!tag)
        		break;
        	++cnt;
        }
        if (cnt)
        	answer = string(strs[0], 0, cnt);
        return answer;
    }
    int min_val(int ix, int iy) {
    	return ix < iy ? ix : iy;
    }
};