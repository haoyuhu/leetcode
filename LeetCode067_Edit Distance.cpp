class Solution {
public:
    int minDistance(string word1, string word2) {
		int lena = word1.size(), lenb = word2.size();
		int dp[lena+1][lenb+1];
		for (int i = 0; i <= lena; ++i){
			dp[i][0] = i;
		}
		for (int i = 0; i <= lenb; ++i){
			dp[0][i] = i;
		}
		for (int i = 1; i <= lena; ++i){
			for (int j = 1; j <= lenb; ++j){
				if (word1[i-1] == word2[j-1]){
					dp[i][j] = min_val(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1);
				}
				else
					dp[i][j] = min_val(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1);
			}
		}
		return dp[lena][lenb];
    }
    int min_val(int x, int y, int z){
    	if (x < y && x < z)
    		return x;
    	else if (y <= x && y <= z)
    		return y;
    	else
    		return z;
    }
};