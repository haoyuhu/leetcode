class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>::reverse_iterator rit = digits.rbegin();
        *rit += 1;
        while (rit != digits.rend() && *rit == 10){
        	*rit = 0;
        	++rit;
        	if (rit != digits.rend()){
        		*rit += 1;
        	}
        }
        if (rit == digits.rend()){
        	digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};