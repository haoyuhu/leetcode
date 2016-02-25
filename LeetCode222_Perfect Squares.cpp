// Time Limit Exceeded
class Solution {
public:

    int numSquares(int n) {
    	store = vector<int> (n + 1, 0);
    	for (int i = 1; i * i <= n; ++i) {
    		store[i * i] = 1;
    	}
    	return dfs(n);
    }

private:

	int MAX_INT = 999999999;
	vector<int> store;

	int dfs(int n) {
		int min = MAX_INT;
    	if (hasSaved(n)) {
    		min = store[n];
		} else {
			for (int i = 1; i <= n / 2; ++i) {
				int count_left = hasSaved(i) ? store[i] : dfs(i);
				if (count_left >= min - 1) {
					continue;
				}
				int count_right = hasSaved(n - i) ? store[n - i] : dfs(n - i);
				int sum = count_left + count_right;
				if (sum < min) {
					min = sum;
				}
			}
		}
		store[n] = min;
		return min;
	}

	bool hasSaved(int n) {
		return store[n] != 0;
	}

};

// AC
class Solution {
public:
    int numSquares(int n) {
    	int MAX_INT = 999999999;
		vector<int> store(n + 1, 0);
		for (int i = 1; i * i <= n; ++i) {
    		store[i * i] = 1;
    	}

    	for (int i = 1; i <= n; ++i) {
    		if (store[i] != 0) {
    			continue;
    		}
    		int min = MAX_INT;
    		for (int j = 1; j <= i / 2; ++j) {
    			int sum = store[j] + store[i - j];
    			if (sum < min) {
    				min = sum;
    			}
    		}
    		store[i] = min;
    	}
    	return store[n];
    }
};