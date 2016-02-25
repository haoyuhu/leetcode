class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> set;
        set.insert(1);
        int count = 1;
        long use[3] = {2, 3, 5};
        while (count != n) {
        	long num = *set.begin();
        	for (long item : use) {
        		set.insert(num * item);
        	}
        	set.erase(set.begin());
        	++count;
        }
        return (int) *set.begin();
    }
};