class Solution {
public:
    string longestPalindrome(string s) {
    	int size = s.size();
        int tag[size][size];
        for (int i = 0; i != size; ++i){
            tag[i][i] = 1;
        }
        for (int l = 1; l != size; ++l){
            for (int i = 0; i != size - l; ++i){
                int j = i + l;
                if ((i + 1 > j - 1 || tag[i+1][j-1]) && s[i] == s[j])
                    tag[i][j] = j - i + 1;
                else
                    tag[i][j] = 0;
            }
        }
        int max = 0;
        int begin, end;
        for (int i = 0; i != size; ++i){
        	for (int j = i; j != size; ++j){
        		if (max < tag[i][j]) {
                    max = tag[i][j];
                    begin = i; end = j;
                }
        			
        	}
        }
        return string(s, begin, end - begin + 1);
    }
};