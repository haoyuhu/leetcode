class Solution {
public:
    void sortColors(int A[], int n) {
        int ct[3] = {0, 0, 0};
        int colors;
        for (int i = 0; i < n; ++i){
        	colors = A[i];
        	++ct[colors];
        }
        for (int i = 0, k = 0; i < 3; ++i){
        	while (ct[i]--){
        		A[k++] = i;
        	}
        }
    }
};