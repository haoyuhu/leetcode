class Solution {
public:
    int numTrees(int n) {
        int numtr[n+1];
        for (int i = 0; i <= n; ++i){
        	numtr[i] = 0;
        }
        numtr[0] = 1;
        for (int i = 1; i <= n; ++i){
        	for (int j = 0, k = i - 1; k >=0 && j <= i - 1; ++j, --k){
        		numtr[i] += numtr[j] * numtr[k];
        	}
        }
        return numtr[n];
    }
};