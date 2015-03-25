class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0)
    		return false;
        int reverse = 0, orig = x;
        while (x) {
        	reverse = reverse * 10 + x % 10;
        	x /= 10;
        }
        if (orig != reverse)
        	return false;
        else
        	return true;
    }
};