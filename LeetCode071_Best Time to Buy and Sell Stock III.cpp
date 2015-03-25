class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (!size)
        	return 0;
        int max_total = 0;
        for (int i = 1; i != size; ++i){
        	int maxl = max_solution(prices, 0, i-1);
        	int maxr = max_solution(prices, i, size-1);
        	max_total = max_val(max_total, maxl + maxr);
        }
        max_total = max_val(max_total, max_solution(prices, 0, size-1));
        return max_total;
    }
    int max_solution(vector<int> &prices, int bottom, int top){
    	int size = top - bottom + 1;
    	int max_prices[size], min_prices[size];
    	max_prices[size-1] = prices[top];
    	min_prices[0] = prices[bottom];
        for (int i = 1; i != size; ++i){
        	if (prices[bottom+i] < min_prices[i-1])
        		min_prices[i] = prices[bottom+i];
        	else
        		min_prices[i] = min_prices[i-1];
        }
        for (int i = size - 2; i >= 0; --i){
        	if (prices[top+i-size+1] > max_prices[i+1])
        		max_prices[i] = prices[top+i-size+1];
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
    int max_val(int ix, int iy){
    	return ix > iy ? ix : iy;
    }
};
//
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (!size)
        	return 0;
        int max_total = 0;
        int i, j;
        for (i = 0; i != size - 1 && prices[i] <= prices[i+1]; ++i);
        for (j = size - 1; j != 0 && prices[j] <= prices[j-1]; --j);
        int min = prices[i], index = i;
    	for (int k = i + 1; k < j; ++k){
    		if (prices[k] < min) {
    			min = prices[k];
    			index = k;
    		}
    	}
        max_total = max_val(max_solution(prices, 0, index - 1) + max_solution(prices, index, size - 1), max_solution(prices, 0, size-1));
        return max_total;
    }
    int max_solution(vector<int> &prices, int bottom, int top){
    	if (bottom > top)
    		return 0;
    	int size = top - bottom + 1;
    	int max_prices[size], min_prices[size];
    	max_prices[size-1] = prices[top];
    	min_prices[0] = prices[bottom];
        for (int i = 1; i != size; ++i){
        	if (prices[bottom+i] < min_prices[i-1])
        		min_prices[i] = prices[bottom+i];
        	else
        		min_prices[i] = min_prices[i-1];
        }
        for (int i = size - 2; i >= 0; --i){
        	if (prices[top+i-size+1] > max_prices[i+1])
        		max_prices[i] = prices[top+i-size+1];
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
    int max_val(int ix, int iy){
    	return ix > iy ? ix : iy;
    }
};//wrong

//
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int firstProfit, buy, sell, size = prices.size();
        if (size <= 1)
            return 0;
        firstProfit = oneTimeMaxProfit(prices, buy, sell);
        int left, right, profit_left, profit_mid, profit_right;
        if (!firstProfit)
            return 0;
        profit_right = profit_mid = profit_left = 0;
        if (buy >= 2) {
            vector<int> leftPrices;
            make_prices(leftPrices, prices, 0, buy);
            profit_left = oneTimeMaxProfit(leftPrices, left, right);
        }
        if (sell - buy >= 3) {
            vector<int> midPrices, tprices(prices);
            make_prices(midPrices, prices, buy + 1, sell);
            reverse(midPrices.begin(), midPrices.end());
            profit_mid = oneTimeMaxProfit(midPrices, left, right);
        }
        if (size - sell >= 3) {
            vector<int> rightPrices;
            make_prices(rightPrices, prices, sell + 1, size);
            profit_right = oneTimeMaxProfit(rightPrices, left, right);
        }
        return firstProfit + max_val(profit_left, profit_mid, profit_right);
    }
    void make_prices(vector<int> &newPrices, vector<int> &prices, int start, int end) {
        for (int i = 0; i != end; ++i) {
            if (i >= start)
                newPrices.push_back(prices[i]);
        }
    }
    int oneTimeMaxProfit(vector<int> &prices, int &buy, int &sell) {
        int size = prices.size();
        int minPrice[size], maxPrice[size], minIndex[size], maxIndex[size];
        minPrice[0] = prices.front(); maxPrice[size-1] = prices.back();
        minIndex[0] = 0; maxIndex[size-1] = size - 1;
        for (int i = 1, j = size - 2; i != size && j >= 0; ++i, --j) {
            if (prices[i] < minPrice[i-1]) {
                minPrice[i] = prices[i];
                minIndex[i] = i;
            }
            else {
                minPrice[i] = minPrice[i-1];
                minIndex[i] = minIndex[i-1];
            }
            if (prices[j] > maxPrice[j+1]) {
                maxPrice[j] = prices[j];
                maxIndex[j] = j;
            }
            else {
                maxPrice[j] = maxPrice[j+1];
                maxIndex[j] = maxIndex[j+1];
            }
        }
        int max_Profit = 0;
        for (int i = 0; i != size - 1; ++i) {
            if (maxPrice[i+1] - minPrice[i] > max_Profit) {
                max_Profit = maxPrice[i+1] - minPrice[i];
                buy = minIndex[i]; sell = maxIndex[i+1];
            }
        }
        return max_Profit;
    }
    int max_val(int ix, int iy, int iz) {
        if (ix >= iy && ix >= iz)
            return ix;
        if (iy >= ix && iy >= iz)
            return iy;
        if (iz >= ix && iz >= iy)
            return iz;
    }
};
//AC! but it cant solve the condition : several best solution on firstProfit;
//pro: save buy and sell as vector<int>, we can solve it in order;