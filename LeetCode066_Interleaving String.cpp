class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3)
        	return false;
        bool tag[len1+1][len2+1];
        int i, j;
        for (i = 1; i <= len1 && s1[i-1] == s3[i-1]; ++i)
        	tag[i][0] = true;
        for (; i <= len1; ++i)
        	tag[i][0] = false;
        for (j = 1; j <= len2 && s2[j-1] == s3[j-1]; ++j)
        	tag[0][j] = true;
        for (; j <= len2; ++j)
        	tag[0][j] = false;
        for (i = 1; i <= len1; ++i){
        	for (j = 1; j <= len2; ++j){
        		tag[i][j] = false;
        		if (s1[i-1] == s3[i+j-1])
        			tag[i][j] = tag[i-1][j];
        		if (!tag[i][j] && s2[j-1] == s3[i+j-1])
        			tag[i][j] = tag[i][j-1];
        	}
        }
        return tag[len1][len2];
    }
};