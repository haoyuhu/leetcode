class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> store(10);
        set<int> check;
        string answer;

        if (n == 1) {
        	answer.push_back('1');
        	return answer;
        }

        store[0] = 1;
        for (int i = 1; i <= 9; ++i) {
        	store[i] = store[i-1] * i;
        }

        for (int i = 1; i <= n; ++i) {
        	check.insert(i);
        }

        for (int i = n - 1; i >= 0; --i) {
        	set<int>::iterator it = check.begin();
        	if (k >= store[i]) {
        		while (k - store[i] >= 0) {
        			k -= store[i];
        			++it;
        		}
        	}
        	if (k == 0) {
        		--it;
        	}
        	answer.push_back('0' + *it);
        	check.erase(it);
        	if (k == 0) {
        		set<int>::reverse_iterator rit = check.rbegin();
        		for (; rit != check.rend(); ++rit) {
        			answer.push_back('0' + *rit);
        		}
        		break;
        	}
        }
        return answer;
    }
};