class Solution {
public:
    int rob(vector<int> &num) {
    	if (!num.size()) return 0;
        vector<int> buy(num.size(), 0), notbuy(num.size(), 0);
        buy[0] = num[0]; notbuy[0] = 0;
        for (int i = 1; i < num.size(); ++i) {
        	buy[i] = notbuy[i-1] + num[i];
        	notbuy[i] = max(buy[i-1], notbuy[i-1]);
        }
        return max(notbuy[num.size()-1], buy[num.size()-1]);
    }
};