class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() == 1) return 0;
        int max = num.front(), min = num.front();
        vector<int>::const_iterator it;
        for (it = num.begin(); it != num.end(); ++it){
        	if (max < *it) max = *it;
        	if (min > *it) min = *it;
        }
        int *tp = new int[max-min+1]();
        for(it = num.begin(); it != num.end(); ++it){
        	++tp[*it-min];
        }
        int gap = 0, t = 0;
        for (int i = 0; i <= max - min; ++i){
        	if (tp[i] > 1){
        		return 0;
        	}
        	else if (tp[i] == 1){
        		if (gap < i - t){
        			gap = i - t;
        		}
        		t = i;
        	}
        }
        return gap;
    }
};
////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() <= 1) return 0;
        sort(num.begin(), num.end());
        vector<int>iterator it = num.begin(), end = num.end() - 1;
        int gap = 0;
        while (it != end){
            if (*(it+1) - *it > gap){
                gap = *(it+1) - *it;
            }
        }
        return gap;
    }
};//O(nlogn)