class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n == 1) return A[0];
        int max = A[0], min = A[0];
        for (int i = 1; i < n; ++i){
        	if (max < A[i]) max = A[i];
        	if (min > A[i]) min = A[i];
        }
        int gap = max - min + 1;
        int ct[gap] = {0};
        for (int i = 0; i < n; ++i){
        	++ct[A[i] - min];
        }
        for (int i = 0; i < gap; ++i){
        	if (ct[i] == 1) return i + min;
        }
    }
};
//
class Solution {
public:
    int singleNumber(int A[], int n) {
        int answer[32];
        int single = 0;
        for (int i = 0; i != 32; ++i){
            answer[i] = 0;
        }
        for (int i = 0; i != n; ++i){
            for (int j = 0; j != 32; ++j){
                if (A[i] >> j & 1)
                    answer[j] += 1;
            }
        }
        for (int i = 0; i != 32; ++i){
            answer[i] %= 3;
        }
        for (int i = 31; i >= 0; --i){
            single = single * 2 + answer[i];
        }
        return single;
    }
};