class Solution {
public:
    int maxSubArray(int A[], int n) {
        int tmp[n+1];
		tmp[0] = 0;
		for (int i = 0; i < n; ++i){
			tmp[i+1] = tmp[i] + A[i];
		}
		int max = tmp[1];
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j < i; ++j){
				int t = tmp[i] - tmp[j];
				max = max>t?max:t;
			}
		}
		return max;
    }
};
//

class Solution {
public:
	#define MIN_INT -999999999
    int maxSubArray(int A[], int n) {
        int sum = 0, max = 0;
        for (int i = 0; i < n; ++i){
        	sum += A[i];
        	if (sum > max)
        		max = sum;
        	if (sum < 0)
        		sum = 0;
        }
        if (!max) {
        	max = MIN_INT;
        	for (int i = 0; i < n; ++i){
        		if (max < A[i])
        			max = A[i];
        	}
        }
        return max;
    }
};