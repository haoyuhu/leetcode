class Solution {
public:
    int addDigits(int num) {
    	while (num >= 10) {
    		int current = 0;
    		while (num) {
    			current += num % 10;
    			num /= 10;
    		}
    		num = current;
    	}
    	return num;
    }
};