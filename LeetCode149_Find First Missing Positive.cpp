class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        for (i = 0; i != n; ++i) {
            while (A[i] != i + 1 && A[i] > 0 && A[i] <= n) {
                int t = A[i];
                if (A[t-1] == A[i]) break;
                A[i] = A[t-1];
                A[t-1] = t;
            }
        }
        for (i = 0; i != n && A[i] == i + 1; ++i);
        return i + 1;
    }
};