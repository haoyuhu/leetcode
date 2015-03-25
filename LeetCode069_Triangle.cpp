class Solution {
public:
	#define MAX_INT 999999999
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        int path[len];
        int min = MAX_INT;
        path[0] = triangle[0][0];
        for (int i = 1; i < len; ++i){
        	path[i] = MAX_INT;
        }
        for (int i = 1; i < len; ++i){
        	for (int j = i; j >= 0; --j){
        		if (j - 1 >= 0)
        			path[j] = min_val(path[j], path[j-1]) + triangle[i][j];
        		else
        			path[j] += triangle[i][j];
        	}
        }
        for (int i = 0; i < len; ++i){
        	min = min_val(min, path[i]);
        }
        return min;
    }
    int min_val(int ix, int iy){
    	return ix < iy ? ix : iy;
    }
};