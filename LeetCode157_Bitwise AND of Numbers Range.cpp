class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m && m != n) {
        	++count;
        	m >>= 1; n >>= 1;
        }
        return m << count;
    }
};