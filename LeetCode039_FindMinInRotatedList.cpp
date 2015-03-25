class Solution {
public:
    int findMin(vector<int> &num) {
        typedef vector<int>::iterator IterType;
        IterType bottom_it = num.begin(), top_it = --num.end(), mid_it;
        while (bottom_it < top_it){
        	mid_it = bottom_it + (top_it - bottom_it) / 2;
        	if (*bottom_it > *top_it){
        		bottom_it = mid_it;
        	}
        	else top_it = mid_it;
        }
        return *bottom_it;
    }
};