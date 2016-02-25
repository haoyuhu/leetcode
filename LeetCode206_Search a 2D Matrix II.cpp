class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (!row) {
        	return false;
        }
        int col = matrix[0].size();
        for (int i = row - 1, j = 0; i >= 0 && j < col; ) {
        	for (; i >= 0 && target < matrix[i][j]; --i);
        	if (i < 0) {
        		return false;
        	}
        	for (; j < col && target > matrix[i][j]; ++j);
        	if (j >= col) {
        		return false;
        	}
        	if (target == matrix[i][j]) {
        		return true;
        	}
        }
        return false;
    }
};