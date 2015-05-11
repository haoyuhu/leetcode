class Solution {
public:
    bool isHappy(int n) {
        int sum;
        unordered_set<int> check;
        check.insert(n);
        while (n != 1) {
        	sum = 0;
        	while (n) {
        		int t = n % 10;
        		n /= 10;
        		sum += t * t;
        	}
        	if (check.find(sum) != check.end())
        		return false;
        	check.insert(sum);
        	n = sum;
        }
        return true;
    }
};