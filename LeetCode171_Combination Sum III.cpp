class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        findCombinationSum(k, n, 0, vector<int>(), answer);
        return answer;
    }

    void findCombinationSum(int k, int n, int curr, vector<int> combination, vector<vector<int>>& answer) {
    	if (k == 0) {
    		if (!combination.empty() && n == 0) {
    			answer.push_back(combination);
    		}
    		return;
    	}
    	int sum = 0;
    	for (int i = curr + 1, cnt = 0; i != 10 && cnt != k; ++i, ++cnt) {
    		sum += i;
    	}
    	int sum_max = 0;
    	for (int i = 9, cnt = 0; i != curr && cnt != k; --i, ++cnt) {
    		sum_max += i;
    	}
    	if (sum <= n && n <= sum_max) {
    		for (int i = curr + 1; i != 10; ++i) {
    			vector<int> copy(combination);
    			copy.push_back(i);
    			findCombinationSum(k - 1, n - i, i, copy, answer);
    		}
    	}
    }
};