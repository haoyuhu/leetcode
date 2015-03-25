class Solution {
public:
    int sqrt(int x) {
    	if (!x)
    		return 0;
        int bottom = 1, top = x / 2 + 1;
        while (bottom <= top){
        	int mid = (bottom + top) / 2;
        	if (mid > 46340 || mid * mid > x)
        		top = mid - 1;
        	else if (mid * mid < x)
        		bottom = mid + 1;
        	else
        		return mid;
        }
        return top;
    }
};