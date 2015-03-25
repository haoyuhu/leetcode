class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        int i, j, tag = 1;
        for (i = 1, j = 0; i < n; ++i){
        	if (A[j] == A[i]){
        		if (tag != 2){
        			A[++j] = A[i]; ++tag;
        		}
        	}
        	else {
        		A[++j] = A[i]; tag = 1;
        	}
        }
        return j + 1;
    }
};