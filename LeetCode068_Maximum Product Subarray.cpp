class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1)
        	return A[0];
        int maxprd[n], minprd[n];
        maxprd[0] = minprd[0] = A[0];
        for (int i = 1; i != n; ++i){
        	maxprd[i] = max_val(maxprd[i-1] * A[i], minprd[i-1] * A[i], A[i]);
        	minprd[i] = min_val(maxprd[i-1] * A[i], minprd[i-1] * A[i], A[i]);
        }
        int max = 0;
        for (int i = 0; i != n; ++i){
        	if (max < maxprd[i])
        		max = maxprd[i];
        }
        return max;
    }
    int max_val(int ix, int iy, int iz){
    	if (ix > iy && ix > iz)
    		return ix;
    	else if (iy >= ix && iy >= iz)
    		return iy;
    	else
    		return iz;
    }
    int min_val(int ix, int iy, int iz){
    	if (ix < iy && ix < iz)
    		return ix;
    	else if (iy <= ix && iy <= iz)
    		return iy;
    	else
    		return iz;
    }    
};