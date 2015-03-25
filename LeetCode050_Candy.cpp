class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 0);
        for (int i = 0; i < ratings.size()-1; ){
        	for (; i < ratings.size()-1 && ratings[i] >= ratings[i+1]; ++i);
        	if (i != ratings.size() - 1)
        		candy[i] = 1;
        	for (; i < ratings.size()-1 && ratings[i] < ratings[i+1]; ++i){
        		candy[i+1] = candy[i] + 1;
        	}
        }
        for (int i = ratings.size()-1; i > 0; ){
        	for (; i > 0 && ratings[i] >= ratings[i-1]; --i);
        	candy[i] = 1;
        	for (; i > 0 && ratings[i] < ratings[i-1]; --i){
        		if (!candy[i-1] || candy[i-1] < candy[i] + 1)
        			candy[i-1] = candy[i] + 1;
        	}
        }
        int sum = 0;
        for (int i = 0; i < ratings.size(); ++i){
        	if (!candy[i]){
        		sum += 1;
        	}
        	else sum += candy[i];
        }
        return sum;
    }
};