class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector< vector<int> > answer;
        if (num.size() < 4)
        	return answer;
        sort(num.begin(), num.end());
        for (int i = 0; i != num.size() - 3; ++i) {
        	for (int j = i + 1; j != num.size() - 2; ++j) {
        		int left = j + 1, right = num.size() - 1;
        		while (left < right) {
        			int sum = num[i] + num[j] + num[left] + num[right];
        			if (sum < target)
        				++left;
        			else if (sum > target)
        				--right;
        			else {
        				int arr[] = {num[i], num[j], num[left], num[right]};
        				vector<int> tvec(arr, arr + 4);
        				answer.push_back(tvec);
        				++left; --right;
        			}
        		}
        	}
        }
        sort(answer.begin(), answer.end());
        vector<vector<int> >::iterator it = unique(answer.begin(), answer.end());
        answer.erase(it, answer.end());
        return answer;
    }
};