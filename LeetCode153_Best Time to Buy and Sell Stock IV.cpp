class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
    	if (k >= prices.size()) return multiMaxProfit(prices);
        vector<int> g(k + 1, 0), l(k + 1, 0);
        for (int i = 1; i < prices.size(); ++i) {
        	int diff = prices[i] - prices[i-1];
        	for (int j = k; j > 0; --j) {
        		l[j] = max(g[j-1] + max(diff, 0), l[j] + diff);
        		g[j] = max(g[j], l[j]);
        	}
        }
        return g[k];
    }
private:
	int multiMaxProfit(vector<int> &prices) {
		int diff, profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			diff = prices[i] - prices[i-1];
			profit += diff > 0 ? diff : 0;
		}
		return profit;
	}
};