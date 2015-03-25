class Solution {
public:
    int findMin(vector<int> &num) {
    	int i;
        for (i = 0; i != num.size() - 1 && num[i] <= num[i+1]; ++i);
        if (i != num.size() - 1)
        	return num[i+1];
        else
        	return num[0];
    }
};