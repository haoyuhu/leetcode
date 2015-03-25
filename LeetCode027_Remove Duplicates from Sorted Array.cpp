class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!n){
        	return 0;
        }
        int ct = 0;
        for (int i = 1; i < n; ++i){
        	if (A[i] != A[ct]){
        		A[++ct] = A[i];
        	}
        }
        return ct + 1;
    }
};