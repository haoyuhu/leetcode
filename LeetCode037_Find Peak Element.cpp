class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.begin() != num.end()){
        	for (vector<int>::size_type i = 0; i < num.size(); ++i){
        		if (i + 1 != num.size() && num[i+1] < num[i] || i + 1 == num.size()){
        			return i;
        		}
        	}
        }
    }
};