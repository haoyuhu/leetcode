class Solution {
public:
    int trailingZeroes(int n) {
        int count_five = 0;
        while (n) {
        	count_five += n / 5;
        	n /= 5;
        }
        return count_five;
    }
};