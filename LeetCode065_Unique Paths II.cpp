class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if (!row || !col)
        	return 0;
        int path[row][col];
        int i, j;
        for (i = 0; i < row && obstacleGrid[i][0] != 1; ++i){
        	path[i][0] = 1;
        }
        for (; i < row; ++i){
        	path[i][0] = 0;
        }
        for (i = 0; i < col && obstacleGrid[0][i] != 1; ++i){
        	path[0][i] = 1;
        }
        for (; i < col; ++i){
        	path[0][i] = 0;
        }
        for (i = 1; i < row; ++i){
        	for (j = 1; j < col; ++j){
        		path[i][j] = 0;
        		if (!obstacleGrid[i][j]) {
        			if (!obstacleGrid[i-1][j])
        				path[i][j] += path[i-1][j];
        			if (!obstacleGrid[i][j-1])
        				path[i][j] += path[i][j-1];
        		}
        	}
        }
        return path[row-1][col-1];
    }
};