class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> counter(citations.size());
        for (int num : citations) {
        	if (num > 0 && num <= citations.size()) {
        		counter[num-1] += 1;
        	} else if (num > citations.size()) {
        		counter[citations.size() - 1] += 1;
        	}
        }
        for (int i = counter.size() - 1; i >= 0; --i) {
        	if (i != counter.size() - 1) {
        		counter[i] += counter[i+1];
        	}
        	if (counter[i] >= i + 1) {
        		return i + 1;
        	}
        }
        return 0;
    }
};