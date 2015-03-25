class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size(), col = grid[0].size();
        int sum[row][col];
        sum[0][0] = grid[0][0];
        for (int i = 1; i != row; ++i){
        	sum[i][0] = sum[i-1][0] + grid[i][0];
        }
        for (int j = 1; j != col; ++j){
        	sum[0][j] = sum[0][j-1] + grid[0][j];
        }
        for (int i = 1; i != row; ++i){
        	for (int j = 1; j != col; ++j){
        		sum[i][j] = min_val(sum[i-1][j], sum[i][j-1]) + grid[i][j];
        	}
        }
        return sum[row-1][col-1];
    }
    int min_val(int ix, int iy) {
    	return ix < iy ? ix : iy;
    }
};