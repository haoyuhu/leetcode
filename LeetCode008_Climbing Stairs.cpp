class Solution {
public:
    int climbStairs(int n) {
        int stp[n + 1];
        for (int i = 0; i <= n; ++i) stp[i] = 0;
        stp[0] = 1;
        stp[1] = 1;
        for (int i = 2; i <= n; ++i){
            stp[i] = stp[i - 1] + stp[i - 2];
        }
        return stp[n];
    }
};
