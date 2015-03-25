class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int size = prices.size();
    	if (!size)
    		return 0;
    	int max_prices[size], min_prices[size];
    	max_prices[size-1] = prices[size-1];
    	min_prices[0] = prices[0];
        for (int i = 1; i != size; ++i){
        	if (prices[i] < min_prices[i-1])
        		min_prices[i] = prices[i];
        	else
        		min_prices[i] = min_prices[i-1];
        }
        for (int i = size - 2; i >= 0; --i){
        	if (prices[i] > max_prices[i+1])
        		max_prices[i] = prices[i];
        	else
        		max_prices[i] = max_prices[i+1];
        }
        int max_profit = 0;
        for (int i = 1; i != size; ++i){
        	if (max_prices[i] - min_prices[i-1] > max_profit)
        		max_profit = max_prices[i] - min_prices[i-1];
        }
        return max_profit;
    }
};