class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = row - 1;
        while (i <= j){
        	int mid_row = (i + j) / 2;
        	if (matrix[mid_row][col-1] < target)
        		i = mid_row + 1;
        	else if (matrix[mid_row][col-1] > target) {
        		if (mid_row - 1 < i || matrix[mid_row-1][col-1] < target) {
        			j = mid_row; break;
        		}
        		else
        			j = mid_row - 1;
        	}
        	else
        		return true;
        }
        if (matrix[j][col-1] < target)
        	return false;
        int inrow = j;
        i = 0; j = col - 1;
        while (i <= j){
        	int mid_col = (i + j) / 2;
        	if (matrix[inrow][mid_col] < target)
        		i = mid_col + 1;
        	else if (matrix[inrow][mid_col] > target)
        		j = mid_col - 1;
        	else
        		return true;
        }
        return false;
    }
};