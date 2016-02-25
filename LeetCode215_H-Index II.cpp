class Solution {
public:
    int hIndex(vector<int>& citations) {
        int bottom = 0, top = citations.size() - 1;
        while (bottom <= top) {
        	int mid = (bottom + top) / 2;
        	int midValue = citations[mid];
        	int num = citations.size() - mid;
        	if (num > midValue) {
        		bottom = mid + 1;
        	} else if (num < midValue) {
        		top = mid - 1;
        	} else {
        		return num;
        	}
        }
        return (citations.size() - bottom);
    }
};