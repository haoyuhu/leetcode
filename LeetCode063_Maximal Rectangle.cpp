class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (!matrix.size() || !matrix[0].size())
        	return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector< vector<int> > map(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i){
        	for (int j = 0; j < col; ++j){
        		if (!i){
        			if (matrix[i][j] == '1')
        				map[i][j] = 1;
        		}
        		else {
        			if (matrix[i][j] == '1')
        				map[i][j] = map[i-1][j] + 1;
        		}
        	}
        }
        int max = 0;
        for (int i = 0; i < row; ++i){
        	int tmp = max_area(map[i]);
        	if (max < tmp)
        		max = tmp;
        }
        return max;
    }
    int max_area(const vector<int> &ivec){
    	int length = ivec.size();
    	stack<int> index;
    	stack<int> val;
    	int max = 0;
    	int save, k;
    	for (int i = 0; i < length; ){
    		while (i < length && (val.empty() || val.top() <= ivec[i])){
    			val.push(ivec[i]);
    			index.push(i);
    			++i;
    		}
    		if (i == length)
    			break;
    		else {
    			while (!val.empty() && ivec[i] <= val.top()){
    				save = val.top(); k = index.top();
    				int area = save * (i - k);
    				if (area > max)
    					max = area;
    				val.pop(); index.pop();
    			}
    			val.push(ivec[i]); index.push(k);
    			++i;
    		}
    	}
    	while (!val.empty()) {
    		save = val.top(); k = index.top();
    		int area = save * (length - k);
    		if (area > max)
    			max = area;
    		val.pop(); index.pop();
    	}
    	return max;
    }
};