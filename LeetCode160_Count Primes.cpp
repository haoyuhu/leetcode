class Solution {
public:
    int countPrimes(int n) {
        bool isDeleted[n];
        for (unsigned i = 0; i < n; ++i)
        	isDeleted[i] = false;

        int count = 0;
        for (unsigned i = 2; i < n; ++i) {
        	if (!isDeleted[i]) {
        		++count;
        		for (unsigned times = 1; i * times <= n; ++times) {
        			isDeleted[i*times] = true;
        		}
        	}
        }
        return count;
    }
};