class Solution {
public:
    int numDistinct(string S, string T) {
        int slen = S.size();
        int tlen = T.size();
        int tag[slen+1][tlen+1];
        for (int i = 0; i <= slen; ++i)
        	tag[i][0] = 1;
        for (int j = 1; j <= tlen; ++j)
        	tag[0][j] = 0;
        for (int i = 1; i <= slen; ++i){
        	for (int j = 1; j <= tlen; ++j){
        		if (S[i-1] != T[j-1])
        			tag[i][j] = tag[i-1][j];
        		else
        			tag[i][j] = tag[i-1][j] + tag[i-1][j-1];
        	}
        }
        return tag[slen][tlen];
    }
};