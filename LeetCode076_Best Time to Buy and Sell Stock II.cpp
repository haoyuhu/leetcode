class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;
        int size = prices.size();
        if (!size || size == 1)
        	return max;
        int low = prices[0];
        for (int i = 0; i != size - 1;){
        	for (; i != size - 1 && prices[i] <= prices[i+1]; ++i);
        	max += prices[i] - low;
        	for (; i != size - 1 && prices[i] >= prices[i+1]; ++i);
        	low = prices[i];
        }
        return max;
    }
};