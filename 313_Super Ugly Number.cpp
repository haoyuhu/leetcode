class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> indexs = vector<int> (primes.size(), 0);
        vector<int> results = vector<int> (1, 1);

        while (results.size() < n) {
        	int minValue = -1;
        	vector<int> minIndexs;
        	for (int i = 0; i != indexs.size(); ++i) {
        		int v = primes[i] * results[indexs[i]];
        		if (v == minValue) {
        			minIndexs.push_back(i);
        		} else if (v < minValue || minValue == -1) {
        			minValue = v;
        			minIndexs.clear();
        			minIndexs.push_back(i);
        		}
        	}
        	for (int i = 0; i != minIndexs.size(); ++i) {
        		++indexs[minIndexs[i]];
        	}
        	results.push_back(minValue);
        }

        return results.back();
    }
};