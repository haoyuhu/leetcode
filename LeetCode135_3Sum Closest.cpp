class Solution {
public:
	#define MAX_INT 999999999
    int threeSumClosest(vector<int> &num, int target) {
    	sort(num.begin(), num.end());
        int min = MAX_INT, answer;
        for (int i = 1; i != num.size() - 1; ++i) {
        	int left, right, gap;
        	for (left = i - 1, right = i + 1; left >= 0 && right < num.size(); ) {
        		gap = num[left] + num[i] + num[right] - target;
        		if (abs(gap) < min) {
        			min = abs(gap);
        			answer = gap + target;
        		}
        		if (gap < 0)
        			++right;
        		else if (gap > 0)
        			--left;
        		else return target;
        	}
        }
        return answer;
    }
};